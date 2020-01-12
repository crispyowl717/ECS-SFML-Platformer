#pragma once

/*
**********************************************************************;
*	Project      : ECS SFML Platformer
*
*	Author		 : ResponsibleFile (Dawson McThay)
*
*	Date created : 01/12/2019
*
*	Purpose		 : This component compiles a list of all inputs the
*				 : the entity can react to. 
*
*	Revisions	 : 01/12/2019
*
**********************************************************************;
*/

#include <SFML/Window.hpp>

struct CInputComponent
{
public:
	std::vector<sf::Keyboard::Key> KeyList{};
};