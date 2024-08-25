# ==================================================
# Unit tests

get_subdirs(${CMAKE_CURRENT_SOURCE_DIR} subdirs)
foreach(utest_path IN LISTS subdirs)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" utest_dir ${utest_path})
    message(${utest_dir})
endforeach()

