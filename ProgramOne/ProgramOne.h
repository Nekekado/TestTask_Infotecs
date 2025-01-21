#include<vector>

class ProgramOne
{
public:
  ProgramOne(std::string path);
  ~ProgramOne();
  void ReadUserInput();
  void ProcessData();
private:
  bool CheckInput(std::string s);
  void WriteFileData(std::string source);
  void ClearFileData();
  std::vector<std::string> buffer;
  bool bufferUpdated = false;
  std::string path;
};
