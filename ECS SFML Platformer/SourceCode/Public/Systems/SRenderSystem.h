#pragma once

#include <iostream>
#include <entt/entt.hpp>
#include "Public/Components/CTransformComponent.h"
#include "Public/Components/CShapeTypeComponent.h"

class SRenderSystem
{
public:
	void Update(entt::registry& Registry);
	void Draw(entt::registry& Registry, sf::RenderWindow& Window);
private:

};

