#include <fstream>
#include <iostream>
#include <string>
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

   fout.open("info/info_step_" + file_name + ".txt");
   for (int i = 0; i < H.size(); i++)
      fout << log10(H[i]) << " ";
   fout.close();

   for (int i = 0; i < H.size(); i++)
   {
      string filename_e = file_name + "_1e" + to_string((int)log10(H[i]));
      fout.open(path + filename_e + ".txt");
      vector<double> T = fill_grid(t0, tn, H[i]);

      vector<vector<double>> Y_num = method(T, H[i], f);
      //vector<vector<double>> Y_anl = y_analysis(T, H[i], analyt_1);
      //output(fout, T, H[i], Y_num, Y_anl);

      //vector<double> Y_anl_tn = analyt_1(tn);

      //double tp = abs(Y_num[Y_num.size() - 1][0] - Y_anl_tn[0]);
      //fout << fixed << "kp = " << kp / tp << endl;

      //double tq = abs(Y_num[Y_num.size() - 1][1] - Y_anl_tn[1]);
      //fout << fixed << "kq = " << kq / tq << endl << endl;

      //kp = tp;
      //kq = tq;

      fout.close();

      fout.open("values/" + filename_e + "_vals.txt");

      int size = T.size();

      for (int j = 0; j < size; j++)
      {
         fout << T[j] << ",";
         fout << Y_num[j][0] << ",";
         fout << Y_num[j][1] << endl;
      }

      fout.close();
   }
}

int main()
{
   //report("adams3", adams3_exp);
   report("runge", runge);
}
