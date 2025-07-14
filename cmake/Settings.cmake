# Название проекта
set(HW_PROJECT_NAME "helloworld")

# Названия таргетов
set(CLI_TARGET "helloworld_cli")
set(VERSION_LIB_TARGET "helloworld")
set(TESTS_TARGET "general_tests")

# Установка параметров версионирования
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

# Установка параметров языка
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Опция для включения поддержки тестирования
option(BUILD_TESTS "Enable testing" OFF)