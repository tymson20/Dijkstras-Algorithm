cmake_minimum_required(VERSION 3.14)

project(DijkstrasAlgorithm)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCES 
    src/node.cpp
    src/graph.cpp
    src/graphMatrix.cpp)

add_executable(DijkstrasAlgorithm main.cpp ${SOURCES})

enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/843976e4f582ccb76cf87e0f128585324335779b.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(DijkstrasTests test/maintest.cpp ${SOURCES})
target_link_libraries(DijkstrasTests gtest_main)
add_test(NAME Tests COMMAND DijkstrasTests)