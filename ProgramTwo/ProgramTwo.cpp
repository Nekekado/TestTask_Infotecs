#include<iostream>
#include<fstream>
#include<string>
#include<chrono>
#include<thread>
#include"filesystem"
#include"MyLib.h"
#include"ProgramTwo.h"


ProgramTwo::ProgramTwo(std::string path)
{
  this->path = path;
}

void ProgramTwo::CheckDataEnter()
{
  while(true)
  {
    std::string result = "Программа 2\t Данные "; // Формирование строки с результатом работы
    std::string data = "";

    // Получение данных из файла
    data = GetFileData();
    
    if (data.length() > 0)
    {
      // Проврека данных через функцию 3 библеотеки
      if (Func3(data))
      {
        result += "получены - " + data + "\n";
      }
      else
      {
        result += "не получены\n";
      }

      std::cout << result;
    }
    else
    {
      // Создание задержки для следующей итерации
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
  }
}

std::string ProgramTwo::GetFileData()
{
  std::string data = "";
  std::ifstream file;
  std::filesystem::file_time_type newTimeWrite = std::filesystem::last_write_time(path);

  // Если файл изменялся с последнего времени -> открыть файл 
  if(lastTimeWrite != newTimeWrite)
    file.open(path);

  if (file.is_open())
  {
    file >> data;
    file.close();

    // Запись последнего изменения файла
    lastTimeWrite = newTimeWrite;
  }

  return data;
}

int main()
{
  setlocale(LC_ALL, "RUS");
  ProgramTwo program("../data/data.txt");

  std::thread t([&program]() {program.CheckDataEnter();});

  t.join();
}
