# Добавьте источник в исполняемый файл этого проекта.
add_executable (ProgramTwo "ProgramTwo.cpp" "ProgramTwo.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ProgramTwo PROPERTY CXX_STANDARD 17)

  #Подлкючение своей библиотеки
  target_link_libraries(ProgramTwo MyLib)
endif()

