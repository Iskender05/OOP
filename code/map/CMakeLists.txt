cmake_minimum_required ( VERSION 3.5 )

add_library ( map
        ../controller/playerController.h
        ../events/game_event.h
        ../events/move_event.cpp
        ../events/negative_event.cpp
        ../events/positive_event.cpp
        console_render.cpp
        console_render.h
        game_render.h
        fieldRenderer.h
        game_level.h
        level_generator.h
        tail.h
        tailmap.h
        fieldRenderer.cpp
        game_level.cpp
        level_generator.cpp
        tail.cpp
        tailmap.cpp
)

target_include_directories ( map PUBLIC ../events ..controller )