#pragma once

/*
**********************************************************************;
*	Project      : ECS_SFML Platformer
*
*	Author		 : ResponsibleFile (Dawson McThay)
*
*	Date created : 01/12/2019
*
*	Purpose		 : This component adds a visible rectangle to the screen.
*
*	Revisions	 : 01/12/2019
*
**********************************************************************;
*/

#include<SFML/Graphics.hpp>

struct CShapeTypeComponent {
public:
	sf::RectangleShape Rectangle{};
};