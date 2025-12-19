#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    if (!fin.is_open())
    {
        cerr << "Cannot open input file.\n";
        return 1;
    }
    while (true)
    {
        int n, var;
      
        if (!(fin >> n))
            break;

        if (!(fin >> var))
            break;

        vector<vector<double>> v(n, vector<double>(var + 1));
        fout << "Enter augmented matrix:" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= var; j++)
            {
                fin >> v[i][j];
            }
        }

        for (int i = 0; i < n - 1; i++)
        {

            for (int j = i + 1; j < n; j++)
            {
                double r = v[j][i] / v[i][i];
                for (int k = 0; k < var + 1; k++)
                {
                    v[j][k] -= v[i][k] * r;
                }
            }

            for (int i = 0; i < n; i++)
            {

                for (int j = 0; j <= var; j++)
                {

                    fout << setw(6) << fixed << setprecision(1) << v[i][j] << " ";
                }
                fout << endl;
            }
            fout << endl;
        }

        int cc = 0;
        for (int i = 0; i < n; i++)
        {
            int f = 1;
            for (int j = 0; j <= var; j++)
            {
                if (v[i][j] != 0)
                {
                    f = 0;
                }
            }
            if (!f)
                cc++;
        }

        int c = 0;
        for (int i = 0; i < n; i++)
        {
            int f = 1;
            for (int j = 0; j < var; j++)
            {
                if (v[i][j] != 0)
                {
                    f = 0;
                }
            }
            if (!f)
                c++;
        }

        if (c == cc)
        {
            if (c == n)
            {
                fout << "Unique solution" << endl;
            }
            else
            {
                fout << "Infinite sol" << endl;
                continue;
            }
        }
        else
        {
            fout << "NO solution" << endl;
            continue;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                double ratio = v[j][i] / v[i][i];
                for (int k = 1; k <= var; k++)
                {
                    v[j][k] -= ratio * v[i][k];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            v[i][var] /= v[i][i];
            v[i][i] = 1;
        }

        fout << endl;
        fout << "NOrmal form:" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= var; j++)
            {
                fout << v[i][j] << " ";
            }
            fout << endl;
        }
        fout << "Solutions -->" << endl;

        for (int i = 0; i < n; i++)
        {
            fout << v[i][var] << " ";
        }
        fout<<endl;
    }
    fin.close();
    fout.close();
}
