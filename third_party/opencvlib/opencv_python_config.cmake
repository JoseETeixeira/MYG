
set(CMAKE_BUILD_TYPE "Release")

set(BUILD_SHARED_LIBS "ON")

set(CMAKE_C_FLAGS " /DWIN32 /D_WINDOWS /W3  /D _CRT_SECURE_NO_DEPRECATE /D _CRT_NONSTDC_NO_DEPRECATE /D _SCL_SECURE_NO_WARNINGS /Gy /bigobj /Oi  /fp:precise     /MP")

set(CMAKE_C_FLAGS_DEBUG "/MDd /Zi /Ob0 /Od /RTC1 ")

set(CMAKE_C_FLAGS_RELEASE "  /MD /O2 /Ob2 /DNDEBUG ")

set(CMAKE_CXX_FLAGS " /DWIN32 /D_WINDOWS /W4 /GR  /D _CRT_SECURE_NO_DEPRECATE /D _CRT_NONSTDC_NO_DEPRECATE /D _SCL_SECURE_NO_WARNINGS /Gy /bigobj /Oi  /fp:precise     /EHa /wd4127 /wd4251 /wd4324 /wd4275 /wd4512 /wd4589 /MP")

set(CMAKE_CXX_FLAGS_DEBUG " /MDd /Zi /Ob0 /Od /RTC1 ")

set(CMAKE_CXX_FLAGS_RELEASE " /MD /O2 /Ob2 /DNDEBUG ")

set(CV_GCC "")

set(CV_CLANG "")

set(ENABLE_NOISY_WARNINGS "OFF")

set(CMAKE_MODULE_LINKER_FLAGS "/machine:x64 ")

set(CMAKE_INSTALL_PREFIX "C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/install")

set(OPENCV_PYTHON_INSTALL_PATH "")

set(OpenCV_SOURCE_DIR "C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/opencv")

set(OPENCV_FORCE_PYTHON_LIBS "")

set(OPENCV_PYTHON_SKIP_LINKER_EXCLUDE_LIBS "")

set(OPENCV_PYTHON_BINDINGS_DIR "C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/modules/python_bindings_generator")

set(cv2_custom_hdr "C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/modules/python_bindings_generator/pyopencv_custom_headers.h")

set(cv2_generated_files "C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/modules/python_bindings_generator/pyopencv_generated_enums.h;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/modules/python_bindings_generator/pyopencv_generated_funcs.h;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/modules/python_bindings_generator/pyopencv_generated_include.h;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/modules/python_bindings_generator/pyopencv_generated_modules.h;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/modules/python_bindings_generator/pyopencv_generated_modules_content.h;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/modules/python_bindings_generator/pyopencv_generated_types.h;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/modules/python_bindings_generator/pyopencv_generated_types_content.h;C:/Users/Eduardo/OneDrive/Ambiente de Trabalho/BYOND/MYG/third_party/modules/python_bindings_generator/pyopencv_signatures.json")
