set(BINARY ${CMAKE_PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Racing_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${Racing_SOURCE_DIR}/lib)

add_executable(${BINARY}
    main.cpp
    car.cpp
    carlist.cpp
    concreatecarfactory.cpp
    carmodifications.cpp
    concreate_race.cpp
    game.cpp
    race_interface.cpp
    racing_team.cpp
    tracks.cpp
    )

add_library(${BINARY}_lib STATIC     	
    main.cpp
    car.cpp
    carlist.cpp
    concreatecarfactory.cpp
    carmodifications.cpp
    concreate_race.cpp
    game.cpp
    race_interface.cpp
    racing_team.cpp
    tracks.cpp
    )

install(TARGETS ${BINARY}
        RUNTIME DESTINATION  ${CMAKE_INSTALL_PREFIX}/bin
        )