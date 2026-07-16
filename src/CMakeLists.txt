add_executable(algoritmi main.cpp Node.cpp LinkedList.cpp)

target_include_directories(algoritmi PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
