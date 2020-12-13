#include <fstream>
#include <iostream>
#include "Vector.h"
#include "adams.h"
#include "runge.h"
#include "DifLab.h"

using namespace std;

void report(const string file_name,
            vector<vector<double>> method(const vector<double>&, const double,
            vector<double> (const double, const vector<double>&)))
{
   ofstream fout;
   double kp = 0, kq = 0;

   fout.open(path + file_name);

   for (int i = 0; i < H.size(); i++)
   {
      vector<double> T = fill_grid(t0, tn, H[i]);

      vector<vector<double>> Y = method(T, H[i], f);
      vector<vector<double>> Y_anl = y_analysis(T, H[i], analyt_1);
      output(fout, T, H[i], Y, Y_anl);

      vector<double> Y_anl_tn = analyt_1(tn);

      double tp = abs(Y[Y.size() - 1][0] - Y_anl_tn[0]);
      fout << fixed << "kp = " << kp / tp << endl;

      double tq = abs(Y[Y.size() - 1][1] - Y_anl_tn[1]);
      fout << fixed << "kq = " << kq / tq << endl << endl;

      kp = tp;
      kq = tq;
   }

   fout.close();
}

int main()
{
   report("euler1.txt", euler1);
   report("adams3.txt", adams3_exp);
}
