cmake_minimum_required ( VERSION 3.5 )

add_library ( events
        ../controller/playerController.h
        game_event.h
        move_event.h
        negative_event.h
        positive_event.h
        move_event.cpp
        negative_event.cpp
        positive_event.cpp
)

target_include_directories ( events PUBLIC ../controller )