cmake_minimum_required(VERSION 3.12)

# Определение параметров проекта
include(cmake/Settings.cmake)

project(${HW_PROJECT_NAME} VERSION ${PROJECT_VERSION})

# Кодогенерация версии
configure_file(${CMAKE_SOURCE_DIR}/version.h.in ${CMAKE_SOURCE_DIR}/version.h)

include(cmake/FindLibrary.cmake)

add_executable(${CLI_TARGET} main.cpp)
add_library(${VERSION_LIB_TARGET} lib.cpp)

target_include_directories(${VERSION_LIB_TARGET}
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(${CLI_TARGET} PRIVATE
    ${VERSION_LIB_TARGET}
)

# Установка параметров компиляции
if (MSVC)
    target_compile_options(${CLI_TARGET} PRIVATE
        /W4
    )
    target_compile_options(${VERSION_LIB_TARGET} PRIVATE
        /W4
    )
else ()
    target_compile_options(${CLI_TARGET} PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(${VERSION_LIB_TARGET} PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS ${CLI_TARGET} RUNTIME DESTINATION bin)
include(cmake/Cpack.cmake)
include(cmake/Tests.cmake)