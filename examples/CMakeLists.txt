include(example_utility)

find_package(OpenCV REQUIRED)
find_package(realsense2 REQUIRED)

list(APPEND EXAMPLES
  "TestInputOutput"
)

list(APPEND PUBLIC_LIBS
)

list(APPEND PRIVATE_LIBS
  ${realsense2_LIBRARY}
  ${OpenCV_LIBS}
)

foreach(example ${EXAMPLES})
  __build_example(
    ${example}
    "${PUBLIC_LIBS}"
    "${PRIVATE_LIBS}"
  )

  target_include_directories(${example}
    PRIVATE
      ${OpenCV_INCLUDE_DIRS}
      ${realsense_INCLUDE_DIR}
  )
endforeach()
