#pragma once
#include <vector>
#include "Vector.h"
#include "DifLab.h"

using namespace std;

inline vector<double> kn1(const double tn, const vector<double>& yn, vector<double> func(const double, const vector<double>&))
{
   return func(tn, yn);
}

inline vector<double> kn2(const double tn, const vector<double>& yn, const double h,
   vector<double> func(const double, const vector<double>&))
{
   return func(tn + h / 2, yn + h / 2 * kn1(tn, yn, func));
}

inline vector<double> kn3(const double tn, const vector<double>& yn, const double h,
   vector<double> func(const double, const vector<double>&))
{
   return func(tn + h / 2, yn + h / 2 * kn2(tn, yn, h, func));
}

inline vector<double> kn4(const double tn, const vector<double>& yn, const double h,
   vector<double> func(const double, const vector<double>&))
{
   return func(tn + h, yn + h * kn3(tn, yn, h, func));
}

inline vector<double> kn(const double tn, const vector<double>& yn, const double h,
   vector<double> func(const double, const vector<double>&))
{
   return 1 / 6.0 * (kn1(tn, yn, func) +
                 2 * kn2(tn, yn, h, func) +
                 2 * kn3(tn, yn, h, func) +
                     kn4(tn, yn, h, func));
}

vector<double> runge_n(const int n,
               const vector<double>& T,
               const double h,
               const vector<vector<double>>& Y,
               vector<double> func(const double, const vector<double>&))
{
   return Y[n - 1] + h * kn(T[n - 1], Y[n - 1], h, func);
}