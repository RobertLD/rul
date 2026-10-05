# RUL — Robbie's Utility Library



## Use via FetchContent

```cmake
include(FetchContent)
FetchContent_Declare(rul
    GIT_REPOSITORY https://github.com/RobertLD/rul.git
    GIT_TAG        main
)
FetchContent_MakeAvailable(rul)

target_link_libraries(my_app PRIVATE rul::rul)
```

## Use as a submodule

```sh
git submodule add https://github.com/RobertLD/rul.git extern/rul
```

```cmake
add_subdirectory(extern/rul)
target_link_libraries(my_app PRIVATE rul::rul)
```

Tests are off by default when RUL is consumed; set `RUL_BUILD_TESTS=ON` to force them.

## Build and test

```sh
cmake -B build -G Ninja
cmake --build build
ctest --test-dir build
```

## Contents

| Header                    | Provides                                 |
| ------------------------- | ---------------------------------------- |
| `<rul/matrix.hpp>`  | `rul::collections::matrix::Matrix<T>` — dense 2D matrix |
