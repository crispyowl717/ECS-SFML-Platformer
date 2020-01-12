#pragma once

/*
**********************************************************************;
*	Project      : ECS SFML Platformer
*
*	Author		 : ResponsibleFile (Dawson McThay)
*
*	Date created : 01/12/2019
*
*	Purpose		 : This prefab creates a square that's can receive input
*				 : and is affected by gravity and collision.
*
*	Revisions	 : 01/12/2019
*
**********************************************************************;
*/

#include <entt/entt.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Public/GlobalSettings.h"
#include "Public/Components/CTransformComponent.h"
#include "Public/Components/CShapeTypeComponent.h"
#include "Public/Components/CCollisionComponent.h"
#include "Public/Components/CInputComponent.h"

struct PF_MovingRectangle
{
public:
	void Create(entt::registry& Registry);
};

inline void PF_MovingRectangle::Create(entt::registry& Registry)
{
	auto RectangleEntity = Registry.create();
	auto Rectangle = std::unique_ptr<sf::RectangleShape>{std::make_unique<sf::RectangleShape>(sf::RectangleShape())};
	Rectangle->setFillColor(sf::Color(109, 236, 185));

	// Make it a rectangle
	Registry.assign<CShapeTypeComponent>(RectangleEntity, *Rectangle);
	// Let it have a shape, transform, scale, and rotation
	Registry.assign<CTransformComponent>(RectangleEntity,
	                                     sf::Vector2f(_WindowSizes[_WindowSelectionID].x / 2 - (25 / 2.f),
	                                                  _WindowSizes[_WindowSelectionID].y / 2 + (25 / 2.f)),
	                                     sf::Vector2f(0.f, 0.f),
	                                     sf::Vector2f(25, 25), 0.f);
	// Let it detect input from the left, right, and space key
	Registry.assign<CInputComponent>(RectangleEntity,
	                                 std::vector<sf::Keyboard::Key>{
		                                 sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Space
	                                 });
	// Let it be affected by gravity
	Registry.assign<CCollisionComponent>(RectangleEntity, _CollisionType::DYNAMIC);
}
