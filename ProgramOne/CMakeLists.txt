# Добавьте источник в исполняемый файл этого проекта.
add_executable (ProgramOne "ProgramOne.cpp" "ProgramOne.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ProgramOne PROPERTY CXX_STANDARD 17)

  #Подлкючение своей библиотеки
  target_link_libraries(ProgramOne MyLib)
endif()
