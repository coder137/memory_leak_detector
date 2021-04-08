add_executable(test_mldmalloc
    test_mldmalloc.c
)
target_link_libraries(test_mldmalloc PRIVATE mldmalloc)

add_test(NAME test_mldmalloc COMMAND test_mldmalloc)

# Check memory leaks using drmemory
add_custom_target(
    check_memory_leak
    DEPENDS test_mldmalloc
    COMMAND drmemory -leaks_only -- ${CMAKE_CURRENT_BINARY_DIR}/test_mldmalloc
  )
