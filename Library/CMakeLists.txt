add_library (MyLib SHARED "MyLib.cpp" "MyLib.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
	#generate_export_header(MyLib)
	target_include_directories(MyLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
endif()
