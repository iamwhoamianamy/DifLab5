#pragma once
#include <vector>
#include <fstream>
using namespace std;

// Умножение вектора на число
vector<double> operator * (double val, const vector<double>& vec)
{
   vector<double> res(vec.size());

   for (size_t i = 0; i < vec.size(); ++i)
      res[i] = val * vec[i];
   return res;
}

vector<double> operator * (const vector<double>& vec, double val)
{
   return val * vec;
}

// Сложение вектора с числом
vector<double> operator + (double val, const vector<double>& vec)
{
   vector<double> res(vec.size());

   for (size_t i = 0; i < vec.size(); ++i)
      res[i] = val + vec[i];
   return res;
}

vector<double> operator + (const vector<double>& vec, double val)
{
   return val + vec;
}

// Сложение векторов
vector<double> operator + (const vector<double>& vec1, const vector<double>& vec2)
{
   vector<double> res(vec1.size());

   for (size_t i = 0; i < vec1.size(); ++i)
      res[i] = vec1[i] + vec2[i];
   return res;
}

// Вычитание векторов
vector<double> operator - (const vector<double>& vec1, const vector<double>& vec2)
{
   vector<double> res(vec1.size());

   for (size_t i = 0; i < vec1.size(); ++i)
      res[i] = vec1[i] - vec2[i];
   return res;
}
