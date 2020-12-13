#pragma once
#include <vector>
#include "runge.h"

using namespace std;

vector<double> adams3_exp_n(const int n,
   const vector<double>& T,
   const double h,
   const vector<vector<double>>& Y,
   vector<double> func(double, const vector<double>&))
{
   return Y[n - 1] + h *
      (23.0 * func(T[n - 1], Y[n - 1]) -
       16.0 * func(T[n - 2], Y[n - 2]) +
        5.0 * func(T[n - 3], Y[n - 3])) * (1 / 12.0);
}

vector<vector<double>> adams3_exp(const vector<double>& T,
   const double h,
   vector<double> func(const double, const vector<double>&))
{
   int N = T.size();
   vector<vector<double>> res (N);

   for (int i = 0; i < N; i++)
      res[i].resize(2);

   res[0][0] = patm;
   res[0][1] = 0.0;

   res[1] = runge_n(1, T, h, res, func);
   res[2] = runge_n(2, T, h, res, func);

   for (int n = 3; n < N; n++)
      res[n] = adams3_exp_n(n, T, h, res, func);

   return res;
}