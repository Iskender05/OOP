cmake_minimum_required ( VERSION 3.5 )

project ( game )

include_directories ( head/ )
set (SOURCE code/main.cpp
            code/player.cpp
            code/playerController.cpp 
            code/tail.cpp
            code/tailmap.cpp)

add_executable ( ${PROJECT_NAME} ${SOURCE} )
