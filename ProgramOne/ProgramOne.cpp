#include<iostream>
#include<thread>
#include<fstream>
#include"MyLib.h"
#include"ProgramOne.h"
#include<string>

ProgramOne::ProgramOne(std::string path)
{
  bufferUpdated = false;
  this->path = path;
};

ProgramOne::~ProgramOne()
{
  ClearFileData();
};

void ProgramOne::ReadUserInput()
{
  // Предварительная очистка файла
  ClearFileData();

  while (true)
  {
    // Чтение ввода пользователя
    std::string input;
    std::cin >> input;

    // Проверка ввода 
    if (!CheckInput(input)) continue;
      
    // Обработка ввода функцией 1 из библеотеки
    Func1(input);

    // Запись в буфер
    buffer.push_back(input);
    bufferUpdated = true;
  }
}

void ProgramOne::ProcessData()
{
  while(true)
  {
    // Проверка данных буфера
    if (bufferUpdated == false || buffer.size() == 0 && buffer.size() > 1) continue;

    // Получение и затирание данных буфера
    std::string source = buffer[0];
    buffer.clear();
    bufferUpdated = false;

    // Сообщение о получении данных
    std::cout << "Данные из буффера: " << source << std::endl;

    // Запись результата функции 2 библеотеки
    std::string result = Func2(source);

    // Запись данных в файл для программы 2
    WriteFileData(source);
  }

}

bool ProgramOne::CheckInput(std::string s)
{
  // Проверка ввода
  if (s.length() <= 64)
  {
    // Проверка есть ли в вводе не только числа
    for (int i = 0; i < s.length(); i++)
    {
      if (!isdigit(s[i]))
      {
        return false;
      }
    }

    return true;
  }

  return false;
}

void ProgramOne::WriteFileData(std::string source)
{
  // Открытие файла в потоке для записи
  std::ofstream file;
  file.open(path);

  if (file.is_open())
  {
    // Запись данных в файл
    file << source;
    file.close();
  }
  else
  {
    return;
  }
}

void ProgramOne::ClearFileData()
{
  // Очистка файла через поток для записи
  std::ofstream file;
  file.open(path);
  file.close();
}

int main()
{
  setlocale(LC_ALL, "RUS");

  ProgramOne program("../data/data.txt");
  std::thread t([&program]() {program.ReadUserInput();});
  std::thread t2([&program]() {program.ProcessData();});

  t.join();
  t2.join();
}
