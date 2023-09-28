cmake_minimum_required ( VERSION 3.5 )

project ( game )

include_directories ( head/ )
set (SOURCE code/main.cpp
            code/Player.cpp
            code/PlayerController.cpp )

add_executable ( ${PROJECT_NAME} ${SOURCE} )
