#pragma once
#include <vector>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846,
eps = pow(10, -14), patm = 1E+5,
q0 = 0.001, l = 1.0, d = 0.01, ro = 1000, Csnd = 1260,
z = 1 - cos(PI / 4), t0 = 0.0, tn = 20.0;
const string path = "reports/";
//const vector<double> H = { 1e-0, 1e-1, 1e-2, 1e-3, 1e-4 };
const vector<double> H = { 1e-4, 1e-5 };

const double S = PI * d * d / 4.0;
const double C = l * S / (ro * Csnd * Csnd);

inline int sign(const double d)
{
   return -1 * (d < 0) + 1 * (d > 0);
}

inline double qh(const double t)
{
   return (t < 1.0) * q0 * t + q0 * (t > 1.0);
}

inline double p(const double t, const vector<double>& resn)
{
   return (qh(t) - resn[1]) / C;
}

double q(const double t, const vector<double>& resn)
{
   const double dif = resn[0] - patm;
   const double root_1 = sqrt(z   * abs(dif) / (2.0 * ro));
   const double root_2 = sqrt(2.0 * abs(dif) / (z   * ro));

   return root_1 * (S * root_2 * sign(dif) - resn[1]);
}

//inline double p(const double t, const vector<double>& resn)
//{
//   return resn[0] - 2;
//}
//
//inline double q(const double t, const vector<double>& resn)
//{
//   return resn[0] + 2 * resn[1] -3;
//}

inline vector<double> f(const double t, const vector<double>& vec)
{
   return { p(t, vec), q(t, vec) };
}

//void output(ofstream& fout,
//   const vector<double>& T,
//   const double h,
//   const vector<vector<double>>& Y_num,
//   const vector<vector<double>>& Y_anl)
//{
//   int N = T.size();
//
//   fout << "h = " << h << endl;
//   fout << "t" << "\t";
//
//   fout << "y_num_p" << "\t";
//   fout << "y_anl_p" << "\t";
//   fout << "|y_num_p - y_anl_p|" << "\t";
//
//   fout << "y_num_q" << "\t";
//   fout << "y_anl_q" << "\t";
//   fout << "|y_num_q - y_anl_q|" << endl;
//
//   fout << scientific;
//
//   for (int n = 0; n < N; n++)
//   {
//      fout << T[n] << "\t";
//
//      fout << Y_num[n][0] << "\t";
//      fout << Y_anl[n][0] << "\t";
//      fout << abs(Y_num[n][0] - Y_anl[n][0]) << "\t";
//
//      fout << Y_num[n][1] << "\t";
//      fout << Y_anl[n][1] << "\t";
//      fout << abs(Y_num[n][1] - Y_anl[n][1]);
//      fout << endl;
//   }
//}

vector<double> fill_grid(const double t0, const  double tn, const double h)
{
   int N = (tn - t0) / h + 1;
   vector<double> res(N);

   for (int n = 0; n < N; n++)
      res[n] = t0 + n * h;

   return res;
}

//const vector<double> analyt_1(const double t)
//{
//   return { (patm - 2) * exp(t) + 2.0,
//      (patm - 2.5) * exp(2.0 * t) + (2.0 - patm) * exp(t) + 0.5 };
//}
//
//vector<vector<double>> y_analysis(const vector<double>& T, const double h, const vector<double> Y_anln(const double))
//{
//   int N = T.size();
//   vector<vector<double>> res(N);
//
//   for (int i = 0; i < N; i++)
//      res[i].resize(2);
//
//   for (int n = 0; n < N; n++)
//   {
//      res[n] = Y_anln(T[n]);
//   }
//
//   return res;
//}
