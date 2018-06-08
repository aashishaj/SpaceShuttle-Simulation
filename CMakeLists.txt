cmake_minimum_required(VERSION 3.10)
project(ssproj)

set(CMAKE_CXX_STANDARD 11)

add_executable(rocket_simulation_cg main.cpp misc.h decl.h drawings.h shuttle_drawer_animator.h shuttle_anim.h planets_drawer.h display_and_menus.h)