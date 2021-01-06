#pragma once
#include <cstdint>
#include <bitset>
#include <queue>
#include <array>
#include <iostream>
#define LOG(x) std::cout << x << std::endl
#define LOGINFO(x) std::cout << "INFO: " << x << std::endl
#define LOGWARN(x) std::cout << "WARNING: " << x << std::endl
#define LOGERR(x) std::cerr << "ERROR: " << x << std::endl

namespace Aero
{
    using AE_Entity = std::uint64_t;
    const AE_Entity MAX_ENTTIES = 8192;

    using AE_ComponentType = std::uint16_t;
    const AE_ComponentType MAX_COMPONENTS = 64;

    using AE_Signature = std::bitset<MAX_COMPONENTS>;

    class AE_EntityManager
    {
    public:
        AE_EntityManager();

        AE_Entity CreateEntity();

        void DestroyEntity(AE_Entity entity);

        void SetSignature(AE_Entity entity, AE_Signature signature);

        AE_Signature GetSignature(AE_Entity entity);

    private:
        std::queue<AE_Entity> mAvailableEntities{};

        std::array<AE_Signature, MAX_ENTTIES> mSignatures{};

        uint32_t mLivingEntityCount{};
    };

    class AE_IComponentArray
    {
    public:
        virtual ~AE_IComponentArray() = default;
        virtual void EntityDestroyed(AE_Entity entity) = 0;
    };

    template <typename T>
    class AE_ComponentArray : public AE_IComponentArray
    {
    public:
        void InsertData(AE_Entity entity, T component);

        void RemoveData(AE_Entity entity);

        T &GetData(AE_Entity entity);

        void EntityDestroyed(AE_Entity entity) override;

    private:
        std::array<T, MAX_ENTITIES> mComponentArray;

        std::unordered_map<AE_Entity, size_t> mEntityToIndexMap;

        std::unordered_map<size_t, AE_Entity> mIndexToEntityMap;

        size_t mSize;
    };
} // namespace Aero