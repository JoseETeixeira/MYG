# CMake generated Testfile for 
# Source directory: C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/opencv/modules/flann
# Build directory: C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/modules/flann
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(opencv_test_flann "C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/bin/Debug/opencv_test_flannd.exe" "--gtest_output=xml:opencv_test_flann.xml")
  set_tests_properties(opencv_test_flann PROPERTIES  LABELS "Main;opencv_flann;Accuracy" WORKING_DIRECTORY "C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/test-reports/accuracy" _BACKTRACE_TRIPLES "C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/opencv/cmake/OpenCVUtils.cmake;1738;add_test;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/opencv/cmake/OpenCVModule.cmake;1352;ocv_add_test_from_target;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/opencv/cmake/OpenCVModule.cmake;1110;ocv_add_accuracy_tests;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/opencv/modules/flann/CMakeLists.txt;2;ocv_define_module;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/opencv/modules/flann/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(opencv_test_flann "C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/bin/Release/opencv_test_flann.exe" "--gtest_output=xml:opencv_test_flann.xml")
  set_tests_properties(opencv_test_flann PROPERTIES  LABELS "Main;opencv_flann;Accuracy" WORKING_DIRECTORY "C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/test-reports/accuracy" _BACKTRACE_TRIPLES "C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/opencv/cmake/OpenCVUtils.cmake;1738;add_test;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/opencv/cmake/OpenCVModule.cmake;1352;ocv_add_test_from_target;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/opencv/cmake/OpenCVModule.cmake;1110;ocv_add_accuracy_tests;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/opencv/modules/flann/CMakeLists.txt;2;ocv_define_module;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/opencv/modules/flann/CMakeLists.txt;0;")
else()
  add_test(opencv_test_flann NOT_AVAILABLE)
endif()
