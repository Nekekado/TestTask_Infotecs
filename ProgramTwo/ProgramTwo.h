#pragma once
#include<filesystem>

class ProgramTwo
{
public:
  ProgramTwo(std::string path);
  void CheckDataEnter();

private:
  std::string GetFileData();
  std::string path;
  std::filesystem::file_time_type lastTimeWrite;
};
