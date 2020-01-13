#pragma once

#include <entt/entity/registry.hpp>
#include <SFML/Window.hpp>

#include "Public/GlobalSettings.h"
#include "Public/WorldGravity.h"
#include "Public/Components/CTransformComponent.h"
#include "Public/Components/CInputComponent.h"

class SInputSystem
{
public:
	void Update(entt::registry& Registry, float DeltaTime);
private:
	
};

