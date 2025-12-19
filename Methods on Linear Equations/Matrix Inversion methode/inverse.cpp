#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> get(vector<vector<double>> A, int r, int c)
{
    int n = A.size();
    vector<vector<double>> co;
    for (int i = 0; i < n; i++)
    {
        if (i == r) continue;
        vector<double> row;
        for (int j = 0; j < n; j++)
        {
            if (j == c) continue;
            row.push_back(A[i][j]);
        }
        co.push_back(row);
    }
    return co;
}

double Det(vector<vector<double>> A)
{
    int n = A.size();
    if (n == 1) return A[0][0];
    if (n == 2)
        return A[0][0]*A[1][1] - A[0][1]*A[1][0];

    double det = 0;
    int s = 1;
    for (int i = 0; i < n; i++)
    {
        det += s * A[0][i] * Det(get(A, 0, i));
        s *= -1;
    }
    return det;
}

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
    while (fin >> n)   
    {
        fout << "Enter the number of equations: " << n << "\n";
        fout << "Augmented matrix:\n";

        vector<vector<double>> A(n, vector<double>(n));
        vector<double> B(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (!(fin >> A[i][j])) return 0; 

            if (!(fin >> B[i])) return 0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                fout<<A[i][j]<<setw(6);
            }
            fout<<B[i]<<endl;
        }

        double det = Det(A);

        if (fabs(det) < 1e-9)
        {
            fout << "Determinant: " << det
                 << "  So Non Inversible\n\n";
            continue;
        }

        fout << "Determinant: " << det
             << "  So Inversible\n";

     
        vector<vector<double>> Adj(n, vector<double>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sign = ((i + j) % 2 == 0) ? 1 : -1;
                Adj[i][j] = sign * Det(get(A, i, j)) / det;
            }
        }


        vector<vector<double>> inv(n, vector<double>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                inv[i][j] = Adj[j][i];

        fout << "Adjoint Matrix:\n";
        for (auto &r : inv)
        {
            for (double x : r)
                fout << setw(10) << x;
            fout << "\n";
        }

        vector<double> ans(n, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans[i] += inv[i][j] * B[j];

        fout << "Solution:\n";
        for (double x : ans)
            fout << x << " ";
        fout << "\n\n";
    }

    return 0;
}
