#include "zpch.h"
#include "Entity.h"

namespace Zero {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}