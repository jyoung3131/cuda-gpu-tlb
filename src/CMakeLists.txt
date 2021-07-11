#Can use this to test different optimization levels but we did not see a significant difference
#set(CMAKE_CXX_FLAGS_RELEASE "-O1")

set(TARGET_LIST tlb_benchmark tlb_sharing)
foreach(TARGET ${TARGET_LIST})
    add_executable(hip_${TARGET}
                    ${TARGET}.cpp)
    set_target_properties(hip_${TARGET} PROPERTIES
                    OUTPUT_NAME ${TARGET})
    target_include_directories(hip_${TARGET} PUBLIC
                    ${CMAKE_SOURCE_DIR}/src)
    # Not clear this is needed..
    #target_link_libraries(hip_${TARGET} MIOpen)
endforeach()

list(TRANSFORM TARGET_LIST PREPEND "hip_")
