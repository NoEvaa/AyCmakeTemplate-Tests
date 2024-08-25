# Utils
# 

# ==================================================
# Get subdirectories of current path.
function(get_subdirs cur_path out_dirs)
    set(out_list "")
    file(GLOB children LIST_DIRECTORIES true "${cur_path}/*")
    foreach(child IN LISTS children)
        if(IS_DIRECTORY ${child})
            list(APPEND out_list ${child})
        endif()
    endforeach()
    set(${out_dirs} ${out_list} PARENT_SCOPE)
endfunction()

