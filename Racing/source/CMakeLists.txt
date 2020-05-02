set(BINARY ${CMAKE_PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Racing_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${Racing_SOURCE_DIR}/lib)

add_executable(${BINARY}
    main.cpp
    car.cpp
    car.h
    carfactory.h
    carlist.cpp
    carlist.h
    concreatecarfactory.cpp
    concreatecarfactory.h
    carmodifications.h
    carmodifications.cpp
    race.h
    race.cpp
    )

add_library(${BINARY}_lib STATIC     	
    main.cpp
    car.cpp
    car.h
    carfactory.h
    carlist.cpp
    carlist.h
    concreatecarfactory.cpp
    concreatecarfactory.h
    carmodifications.h
    carmodifications.cpp
    race.h
    race.cpp
    )

install(TARGETS ${BINARY}
        RUNTIME DESTINATION  ${CMAKE_INSTALL_PREFIX}/bin
        )