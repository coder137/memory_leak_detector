# Memory leak detection based malloc and free wrappers
add_library(mldmalloc)
target_sources(mldmalloc PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/mldmalloc.c
)
target_include_directories(mldmalloc PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(mldmalloc PUBLIC
    linkedlist
)

add_dependencies(mldmalloc linkedlist)
