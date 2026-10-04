include(FetchContent)

FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
)
FetchContent_MakeAvailable(googletest)

add_executable(rul_tests
    test_vector_utils.cpp
)
target_link_libraries(rul_tests PRIVATE rul::rul GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(rul_tests)
