if(EXISTS "D:/GitHub_Repos/pwr_AiZO_project2/cmake-build-debug/tests[1]_tests.cmake")
  include("D:/GitHub_Repos/pwr_AiZO_project2/cmake-build-debug/tests[1]_tests.cmake")
else()
  add_test(tests_NOT_BUILT tests_NOT_BUILT)
endif()
