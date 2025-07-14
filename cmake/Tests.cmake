if(BUILD_TESTS)

    enable_testing()
    include(GoogleTest)

    add_executable(${TESTS_TARGET} ${CMAKE_SOURCE_DIR}/test_version_gtest.cpp)

    target_link_libraries(${TESTS_TARGET} PRIVATE
                GTest::gtest
                GTest::gtest_main
                ${VERSION_LIB_TARGET}
            )

    gtest_discover_tests(${TESTS_TARGET})
endif()
