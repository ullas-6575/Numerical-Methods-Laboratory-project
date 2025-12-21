#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin)
    {
        cerr << "Cannot open input file\n";
        return 1;
    }
    int n;
    while ((fin >> n))
    {
        fout << "Enter no of eq:"<<n<< endl;;
        vector<vector<double>> A(n, vector<double>(n + 1));
        vector<vector<double>> L(n, vector<double>(n, 0));
        vector<vector<double>> U(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                fin >> A[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int k = i; k < n; k++)
            {
                double sum = 0;
                for (int j = 0; j < i; j++)
                {
                    sum += (L[i][j] * U[j][k]);
                }
                U[i][k] = A[i][k] - sum;
            }

            for (int k = i; k < n; k++)
            {
                if (i == k)
                    L[i][i] = 1;
                else
                {
                    double sum = 0;
                    for (int j = 0; j < i; j++)
                    {
                        sum += (L[k][j] * U[j][i]);
                    }
                    L[k][i] = (A[k][i] - sum) / U[i][i];
                }
            }
            fout << "Lower Triangular:" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    fout << setw(6) << L[i][j];
                }
                fout << endl;
            }
            fout << endl;
            fout << "Upper Triangular:" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    fout << setw(6) << U[i][j];
                }
                fout << endl;
            }
        }
        fout << "Lower Triangular:" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fout << setw(6) << L[i][j];
            }
            fout << endl;
        }
        fout << endl;
        fout << "Upper Triangular:" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fout << setw(6) << U[i][j];
            }
            fout << endl;
        }

        vector<double> y(n), x(n);
        for (int i = 0; i < n; i++)
        {
            double s = 0;
            for (int j = 0; j < i; j++)
            {
                s += (L[i][j] * y[j]);
            }
            y[i] = A[i][n] - s;
        }

        int c = 0;
        for (int i = 0; i < n; i++)
        {
            int f = 1;
            for (int j = 0; j < n; j++)
            {
                if (U[i][j] != 0)
                    f = 0;
            }
            if (!f)
                c++;
        }

        int cc = 0;
        for (int i = 0; i < n; i++)
        {
            int f = 1;
            for (int j = 0; j < n; j++)
            {
                if (U[i][j] != 0)
                    f = 0;
            }
            if (y[i] != 0)
                f = 0;
            if (!f)
                cc++;
        }

        if (c == cc)
        {
            if (c == n)
            {
                fout << "unique sol" << endl;
            }
            else
            {
                fout << "many sol" << endl;
                continue;
                //                return 0;
            }
        }
        else
        {
            fout << "no sol" << endl;
            continue;
            //            return 0;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            double ss = 0;
            for (int j = i + 1; j < n; j++)
            {
                ss += (U[i][j] * x[j]);
            }
            x[i] = (y[i] - ss) / U[i][i];
        }
        fout << "Y:" << endl;
        for (int i = 0; i < n; i++)
        {
            fout << y[i] << " ";
        }
        fout << endl;

        fout << "X:" << endl;

        for (int i = 0; i < n; i++)
        {
            fout << x[i] << " ";
        }
        fout << endl;
        fout<<endl;
    }

    return 0;
}
