#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("input.txt");   
    ofstream fout("output.txt");  

    if(!fin.is_open()) {
        cerr << "Cannot open input file.\n";
        return 1;
    }

    while(true) {
        fout << "Enter the number of equations: ";
        int n;
        if(!(fin >> n)) break; 
        fout << n << endl;

        vector<vector<double>> v(n, vector<double>(n+1));
        fout << "Augmented matrix:" << endl;
        for(int i=0; i<n; i++) {
            for(int j=0; j<=n; j++) {
                fin >> v[i][j];
                fout << v[i][j] << " ";
            }
            fout << endl;
        }

     
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                double r = v[j][i] / v[i][i];
                for(int k=0; k<=n; k++) {
                    v[j][k] -= v[i][k] * r;
                }
            }
        }

        int cc = 0;
        for(int i=0; i<n; i++) {
            int f = 1;
            for(int j=0; j<=n; j++) {
                if(v[i][j] != 0) f = 0;
            }
            if(!f) cc++;
        }

        int c = 0;
        for(int i=0; i<n; i++) {
            int f = 1;
            for(int j=0; j<n; j++) {
                if(v[i][j] != 0) f = 0;
            }
            if(!f) c++;
        }

        if(c == cc) {
            if(c == n) {
                fout << "Unique solution" << endl;
            } else {
                fout << "Infinite solution" << endl;
                continue;
            }
        } else {
            fout << "NO solution" << endl;
            continue;
        }

 
        vector<double> sol(n);
        for(int i=n-1; i>=0; i--) {
            sol[i] = v[i][n];
            for(int j=0; j<n; j++) {
                if(i != j) sol[i] -= v[i][j] * sol[j];
            }
            sol[i] /= v[i][i];
        }

        fout << "Solution: ";
        for(int i=0; i<n; i++) {
            fout << fixed << setprecision(3) << sol[i] << " ";
        }
        fout << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
