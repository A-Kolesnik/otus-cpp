if(BUILD_TESTS)

    enable_testing()
    include(GoogleTest)

    add_executable(${TESTS_TARGET}
        ${CMAKE_SOURCE_DIR}/src/tests/tests.cpp
        ${CMAKE_SOURCE_DIR}/src/validator.cpp
        )

    target_include_directories(${TESTS_TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/include)

    target_link_libraries(${TESTS_TARGET} PRIVATE
                GTest::gtest
                GTest::gtest_main
            )

    gtest_discover_tests(${TESTS_TARGET})
endif()
