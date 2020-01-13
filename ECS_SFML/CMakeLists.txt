cmake_minimum_required(VERSION 3.15)
project(ECS_SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(ECS_SFML ECSSFMLPlatformer.cpp)

include_directories(.)
include_directories(SourceCode)
include_directories(SourceCode/Private)
include_directories(SourceCode/Public)
include_directories(SourceCode/Public/Components)
include_directories(SourceCode/Public/Helper)
include_directories(SourceCode/Public/Managers)
include_directories(SourceCode/Public/Prefab)
include_directories(SourceCode/Public/Systems)

set(SOURCE_FILES ECSSFMLPlatformer.cpp)
add_executable(ECS ${SOURCE_FILES})
