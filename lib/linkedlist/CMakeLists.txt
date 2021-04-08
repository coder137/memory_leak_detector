add_library(linkedlist)
target_sources(linkedlist PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/linkedlist.c
)
target_include_directories(linkedlist PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
