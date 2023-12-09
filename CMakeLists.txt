
cmake_minimum_required(VERSION 3.16)

project( testing_something VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_GENERATOR ninja)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O3")

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-fsanitize=address,undefined,leak -O0
-ggdb -pthread -gdwarf-4 -DLinux -fPIC -Wno-deprecated -pipe
-fno-elide-type -fdiagnostics-show-template-tree -Wall -Werror -Wextra
-Wpedantic -Wvla -Wextra-semi -Wnull-dereference -Wswitch-enum
-Wduplicated-cond -Wduplicated-branches -rdynamic -Wsuggest-override
-MMD -MP")

file(GLOB sources src/main.cxx)

add_executable(testing_something ${sources})

find_package(re2 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(testing_something PRIVATE re2::re2 fmt::fmt)

add_custom_target(
    run
    COMMAND testing_something
    DEPENDS testing_something
)

