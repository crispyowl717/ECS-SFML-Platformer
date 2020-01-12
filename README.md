<p align="center">
  <img src="README/SS.gif">
</p>

# ECS SFML Platformer
I had been using objected-oriented programming since learning my first language. At some point, I always ran into the same issue where my inheratance trees quickly turn into a flaming, convoluted mess. I eventually found that Entity Component System removes that problem by assigning components to entities that are all impacted by the same system. I also frequently use C++ 17 features, particuarly unique_ptr and auto keyword.

Here's a little primer on Entity Component Systems.

### Entity Component System

Entities are ONLY a simple unsigned datatype like std::uint32_t. A component is a simple struct that only contains a collection of variables. A system refrences components and applies a universal set of rules upon it. In the example of the game above, the blue box is an entity that has a transform component (x,y,z) and is set as dynamic. In a system called gravity, it should check two things:

1) It has a transform (otherwise it wouldn't be able to refrence the Y position of the entity).
2) The entity is dynamic (because a static entity cannot be affected by gravity).

If these two conditions are fulfilled, then there should be a gravitational field going dornward. 

Each entity is added to a registry which keeps a record of all components attached to an entity. 

## System Architecture

##### Workflow

> ###### Systems
>
> Systems check every entity with a collection of components and apply a universal set of rules upon it.
> 
> ###### Components
>
> Components are a set of variables. An entity can have multiple of these of once. Each entity has their own
> inputs for the component;
>
> ###### Prefabs
>
> Prefabs create an entity that already has a specific group of components already.
>
> ###### Manager
>
> Managers contain a set of systems and describe how they interact with each other.
>

## Conventions

| Type                    | Convention                                                 |
| ----------------------- | ---------------------------------------------------------- |
| Global Variable         | &#95;VariableName                                          |
| System                  | SSystemClass                                               |
| Manager                 | MManagerClass                                              |
| Component               | CComponentStruct                                           |
| Prefab                  | PF_PrefabStruct                                            |
| Helper                  | HHelperStruct                                              |


## Most Recent Footage
<img src="README/ESGameplay.gif">

## Built With
* [SFML](https://github.com/SFML/SFML) - Graphics, Audio, Window, Input
* [EnTT](https://github.com/skypjack/entt/) - Entity Component System

## License
[MIT](https://choosealicense.com/licenses/mit/)
