set(SOLUTIONS "solutions")

set(SOLUTIONS_HEADER_FILES
)

set(SOLUTIONS_SOURCE_FILES
    main.cpp
    optimal.cpp
)

add_executable(${SOLUTIONS} 
    ${SOLUTIONS_HEADER_FILES}
    ${SOLUTIONS_SOURCE_FILES}
)

if(MSVC)
  target_compile_options(${SOLUTIONS} PRIVATE /W4 /WX)
else()
  target_compile_options(${SOLUTIONS} PRIVATE -Wall -Wextra -Wconversion -Wdouble-promotion
  -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion)
endif()

target_compile_definitions(${SOLUTIONS} PRIVATE CMAKE_EXPORT_COMPILE_COMMANDS=1)




