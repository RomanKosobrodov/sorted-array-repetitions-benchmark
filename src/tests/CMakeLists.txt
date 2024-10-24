include(CTest)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.0 
)

FetchContent_MakeAvailable(Catch2)

set(SOLUTIONS_TEST_NAME test_solutions)

set(SOLUTIONS_TEST_HEADERS
)

set(SOLUTIONS_TEST_SOURCES
  ${CMAKE_SOURCE_DIR}/solutions/optimal.cpp
  test_generator.cpp	
  test_main.cpp
  test_solutions.cpp
)

add_executable(${SOLUTIONS_TEST_NAME}
    ${SOLUTIONS_TEST_HEADERS}
    ${SOLUTIONS_TEST_SOURCES}
)

target_include_directories(${SOLUTIONS_TEST_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/solutions/
)

target_link_libraries(${SOLUTIONS_TEST_NAME}
    PRIVATE Catch2::Catch2WithMain
)    

add_test(NAME ${SOLUTIONS_TEST_NAME}
         COMMAND  ${SOLUTIONS_TEST_NAME})