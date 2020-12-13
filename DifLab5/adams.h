#pragma once
#include <vector>
#include "runge.h"

using namespace std;

//double adams2_exp_n(const int n, const double h,
//   const vector<double>& T,
//   const vector<double>& Y,
//   double func(double, double))
//{
//   return Y[n - 1] + h *
//      (3.0 * func(T[n - 1], Y[n - 1]) -
//             func(T[n - 2], Y[n - 2])) / 2.0;
//}

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

//double adams4_exp_n(const int n, const double h,
//                    const vector<double>& T,
//                    const vector<double>& Y,
//                    double func(double, double))
//{
//   return Y[n - 1] + h *
//      (55.0 * func(T[n - 1], Y[n - 1]) -
//      59.0 * func(T[n - 2], Y[n - 2]) +
//      37.0 * func(T[n - 3], Y[n - 3]) -
//      9.0 * func(T[n - 4], Y[n - 4])) / 24.0;
//}

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
//
//vector<double> adams4_exp(const vector<double>& T, double func(double, double))
//{
//   double h = calc_h(T);
//   int size = T.size();
//   vector<double> Y(size);
//   Y[0] = 1;
//   Y[1] = runge_n(1, h, T, Y, func);
//   Y[2] = runge_n(2, h, T, Y, func);
//   Y[3] = runge_n(3, h, T, Y, func);
//
//   for (int n = 4; n < size; n++)
//      Y[n] = adams4_exp_n(n, h, T, Y, func);
//
//   return Y;
//}
//
//double adams3_imp_n(const int n, const double h,
//   const vector<double>& T,
//   const vector<double>& Y,
//   double func(double, double),
//   const double x)
//{
//   return Y[n - 1] + h *
//      (5.0 * func(T[n], x) +
//      8.0 * func(T[n - 1], Y[n - 1]) -
//      func(T[n - 2], Y[n - 2])) / 12.0;
//}
//
//double adams4_imp_n(const int n, const double h,
//   const vector<double>& T,
//   const vector<double>& Y,
//   double func(double, double),
//   const double x)
//{
//   return Y[n - 1] + h *
//      (9.0 * func(T[n], x) +
//      19.0 * func(T[n - 1], Y[n - 1]) -
//      5.0 * func(T[n - 2], Y[n - 2]) +
//      func(T[n - 3], Y[n - 3])) / 24.0;
//}
//
//vector<double> adams3_imp(const vector<double>& T, double func(double, double))
//{
//   double h = calc_h(T);
//   int size = T.size();
//   vector<double> Y(size);
//   Y[0] = 1;
//   Y[1] = runge_n(1, h, T, Y, func);
//   Y[2] = runge_n(2, h, T, Y, func);
//
//   for (int n = 3; n < size; n++)
//   {
//      double x0 = adams3_exp_n(n, h, T, Y, func);
//      double x1;
//      int k = 0;
//
//      while(k < K)
//      {
//         x1 = adams3_imp_n(n, h, T, Y, func, x0);
//         if (abs(x1 - x0) < eps)
//            break;
//         else
//         {
//            x0 = x1;
//            k++;
//         }
//      }
//
//      Y[n] = x1;
//   }
//
//   return Y;
//}
//
//vector<double> adams4_imp(const vector<double>& T, double func(double, double))
//{
//   double h = calc_h(T);
//   int size = T.size();
//   vector<double> Y(size);
//   Y[0] = 1;
//   Y[1] = runge_n(1, h, T, Y, func);
//   Y[2] = runge_n(2, h, T, Y, func);
//   Y[3] = runge_n(3, h, T, Y, func);
//
//   for(int n = 4; n < size; n++)
//   {
//      double x0 = adams4_exp_n(n, h, T, Y, func);
//      double x1;
//      int k = 0;
//
//      while (k < K)
//      {
//         x1 = adams4_imp_n(n, h, T, Y, func, x0);
//         if (abs(x1 - x0) < eps)
//            break;
//         else
//         {
//            x0 = x1;
//            k++;
//         }
//      }
//
//      Y[n] = x1;
//   }
//
//   return Y;
//}
//
//vector<double> adams3_prediction(const vector<double>& T, double func(double, double))
//{
//   double h = calc_h(T);
//   int size = T.size();
//   vector<double> Y(size);
//   Y[0] = 1;
//   Y[1] = runge_n(1, h, T, Y, func);
//
//   for (int n = 2; n < size; n++)
//   {
//      double y = adams2_exp_n(n, h, T, Y, func);
//      Y[n] = adams3_imp_n(n, h, T, Y, func, y);
//   }
//
//   return Y;
//}
//
//vector<double> adams4_prediction(const vector<double>& T, double func(double, double))
//{
//   double h = calc_h(T);
//   int size = T.size();
//   vector<double> Y(size);
//   Y[0] = 1;
//   Y[1] = runge_n(1, h, T, Y, func);
//   Y[2] = runge_n(2, h, T, Y, func);
//
//   for (int n = 3; n < size; n++)
//   {
//      double y = adams3_exp_n(n, h, T, Y, func);
//      Y[n] = adams4_imp_n(n, h, T, Y, func, y);
//   }
//   
//   return Y;
//}
