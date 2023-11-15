cmake_minimum_required ( VERSION 3.5 )

add_library ( game_class
        ../controller/playerController.cpp
        game.h
        game.cpp
)

target_include_directories ( game_class PUBLIC ../controller )