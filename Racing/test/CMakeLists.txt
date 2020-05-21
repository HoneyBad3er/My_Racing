set(BINARY ${CMAKE_PROJECT_NAME}_tst)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Racing_SOURCE_DIR}/bin)

add_executable(${BINARY} 
                main.cpp 
                f1_create_test.cpp 
                gt_create_test.cpp 
                dtm_create_test.cpp
                car_modification_test.cpp
                )

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)