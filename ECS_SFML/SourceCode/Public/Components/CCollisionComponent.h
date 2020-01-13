#pragma once

/*
**********************************************************************;
*	Project      : ECS_SFML Platformer
*
*	Author		 : ResponsibleFile (Dawson McThay)
*
*	Date created : 01/12/2019
*
*	Purpose		 : This component adds the ability to be affected by gravity or not.
*
*	Revisions	 : 01/12/2019
*
**********************************************************************;
*/

#include "Public/GlobalSettings.h"

struct CCollisionComponent
{
	public:
		_CollisionType Type{};
};