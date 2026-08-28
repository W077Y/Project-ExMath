cmake_minimum_required (VERSION 3.19)


set(target_name "TEST-POLYNOMIAL")
 message(STATUS "-> ${target_name}")


add_executable(${target_name})

target_include_directories(${target_name}
 PRIVATE "${CMAKE_CURRENT_LIST_DIR}"
)

target_sources(${target_name}
 PRIVATE "${CMAKE_CURRENT_LIST_DIR}/tst-polynomial.cpp"
)

target_link_libraries(${target_name}
 PRIVATE Catch2::Catch2WithMain
 PRIVATE exmath-lib
)

include(Catch)
catch_discover_tests(${target_name})


