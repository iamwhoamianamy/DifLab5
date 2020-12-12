#pragma once
#include <vector>
#include <cmath>

using namespace std;

const double e = 2.718281828399998989, PI = 3.14159265358979323846, eps = pow(10, -14), p = 1E+5,
q0 = 0.001, l = 1.0, d = 0.01, ro = 1000, Csnd = 1260, z = 1 - cos(PI / 2), t0 = 0.0, tn = 20.0;
const int K = 10000;
const string path = "reports/";
const vector<double> H = { 1e-4, 1e-5,};

const double S = PI * d * d / 4.0;
const double C = l * S / (ro * Csnd * Csnd);

inline double qh(const double t)
{
   return t - 1.0 <= eps ? q0 * t : q0;
}

//inline double calc_h(const vector<double>& T)
//{
//   return T.size() > 1 ? T[1] - T[0] : 0;
//}
//
//void output(ofstream& fout, const vector<double>& T, const vector<double>& Y_num, const vector<double>& Y_anl)
//{
//   int N = T.size();
//
//   fout << "h = " << calc_h(T) << endl;
//   fout << "t" << "\t";
//   fout << "y_num" << "\t";
//   fout << "y_anl" << "\t";
//   fout << "|y_num - y_anl|" << endl;
//
//   fout << scientific;
//
//   for (int n = 0; n < N; n++)
//   {
//      fout << T[n] << "\t";
//      fout << Y_num[n] << "\t";
//      fout << Y_anl[n] << "\t";
//      fout << abs(Y_num[n] - Y_anl[n]);
//      fout << endl;
//   }
//}
//
//vector<double> fill_grid(double t0, double tn, double h)
//{
//   int N = (tn - t0) / h + 1;
//   vector<double> res(N);
//
//   for (int n = 0; n < N; n++)
//      res[n] = t0 + n * h;
//
//   return res;
//}
//
//vector<double> y_analysis(const vector<double>& T)
//{
//   double h = calc_h(T);
//   int N = T.size();
//   vector<double> res(N);
//
//   res[0] = 1.0;
//
//   for (int n = 0; n < N; n++)
//      res[n] = pow(e, pow(T[n], 2));
//
//   return res;
//}
