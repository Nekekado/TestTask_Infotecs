#include"MyLib.h"


void Func1(std::string& s)
{
  if (s.length() == 0)
    return;

  for (int i = 0; i < s.length(); i++)
  {
    for (int j = 0; j < s.length() - 1; j++)
    {
      if (s[j] > s[j + 1])
      {
        char c = s[j + 1];
        s[j + 1] = s[j];
        s[j] = c;
      }
    }
  }

  int k = 0;
  int size = s.length();

  for (int i = 0; i < size; i += 2)
  {
    s.replace(i + k, 1, "КВ");
    k++;
  }
}

std::string Func2(std::string s)
{
  if (s.length() == 0)
    return s;

  std::string sum = "";

  for (auto x : s)
  {
    if (isdigit(x))
    {
      sum += x;
    }
  }

  return sum;
}

bool Func3(std::string s)
{
  if (s.length() > 2 && s.length() % 32 == 0)
  {
    return true;
  }

  return false;
}
