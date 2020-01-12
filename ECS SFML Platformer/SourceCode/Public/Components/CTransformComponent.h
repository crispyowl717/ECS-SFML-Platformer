#pragma once

/*
**********************************************************************;
*	Project      : ECS SFML Platformer
*
*	Author		 : ResponsibleFile (Dawson McThay)
*
*	Date created : 01/12/2019
*
*	Purpose		 : This component adds position, velocity, size, and rotation.
*
*	Revisions	 : 01/12/2019
*
**********************************************************************;
*/

#include <SFML/System.hpp>

struct CTransformComponent {
public:
	sf::Vector2f Position{};
	sf::Vector2f Velocity{};
	sf::Vector2f Size{};
	float Rotation{};
};