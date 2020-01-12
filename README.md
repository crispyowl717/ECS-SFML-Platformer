<p align="center">
  <img src="README/SS.gif">
</p>

# ECS SFML Platformer
I had been using objected-oriented programming since learning my first language. At some point, I always ran into the same issue where my inheratance trees quickly turn into a flaming, convoluted mess. I eventually found that Entity Component System removes that problem by  assigning components to entities that are all impacted by the same system. I also frequently use C++ 17 features, particuarly unique_ptr and auto keyword.

Here's a little primer on Entity Component Systems and Data Oriented Design:

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## System Architecture

##### Cases

There are a few different ways you can name things. Here are some common casing types:

> ###### PascalCase
>
> Capitalize every word and remove all spaces, e.g. `DesertEagle`, `StyleGuide`, `ASeriesOfWords`.
> 
> ###### camelCase
>
> The first letter is always lowercase but every following word starts with uppercase, e.g. `desertEagle`, `styleGuide`, `aSeriesOfWords`.
>
> ###### Snake_case
>
> Words can arbitrarily start upper or lowercase but words are separated by an underscore, e.g. `desert_Eagle`, `Style_Guide`, `a_Series_of_Words`.

## Naming Conventions

##### Variables

| Asset Type              | Asset Name                                                 |
| ----------------------- | ---------------------------------------------------------- |
| Skeletal Mesh           | SK_Bob                                                     |
| Material                | M_Bob                                                      |
| Texture (Diffuse/Albedo)| T_Bob_D                                                    |
| Texture (Normal)        | T_Bob_N                                                    |
| Texture (Evil Diffuse)  | T_Bob_Evil_D                                               |


## Most Recent Footage
<img src="README/ESGameplay.gif">

## Built With
* [SFML](https://github.com/SFML/SFML) - Graphics, Audio, Window, Input
* [EnTT](https://github.com/skypjack/entt/) - Entity Component System

## License
[MIT](https://choosealicense.com/licenses/mit/)
