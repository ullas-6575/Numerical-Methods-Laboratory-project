#include<bits/stdc++.h>
using namespace std;

double fact(int n){
    double res=1;
    for(int i=2; i<=n; i++) res*=i;
    return res;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout<<"Num of data points:\n";
    int n; cin>>n;

    cout<<"Enter x values:\n";
    vector<double> xv(n);
    for(int i=0; i<n; i++) cin>>xv[i];

    cout<<"Enter y values:\n";
    vector<double> yv(n);
    for(int i=0; i<n; i++) cin>>yv[i];

    cout<<"Enter the value:\n";
    double x; cin>>x;

    vector<vector<double>> diff(n, vector<double>(n));
    for(int i=0; i<n; i++) diff[i][0] = yv[i];

    for(int j=1; j<n; j++){
        for(int i=0; i<n-j; i++) {
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
        }
    }

    cout<<"Backward difference table:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++) cout << diff[i][j] << "\t"; 
        cout<<endl;
    }
    
    double h = xv[1] - xv[0];
    
    double u = (x - xv[n-1]) / h;

    double val1 = 0;
    
    // Term 1: del(y)
    if(n > 1) val1 += diff[n-2][1]; 
    
    // Term 2: (2u+1)/2! * del^2(y)
    if(n > 2) val1 += ((2*u + 1) / fact(2)) * diff[n-3][2];
    
    // Term 3: (3u^2+6u+2)/3! * del^3(y)
    if(n > 3) val1 += ((3*u*u + 6*u + 2) / fact(3)) * diff[n-4][3];
    
    double fp = val1 / h;

    // 4. Second Derivative Calculation
    double val2 = 0;
    
    // Term 1: del^2(y)
    if(n > 2) val2 += diff[n-3][2];
    
    // Term 2: (u+1) * del^3(y)
    if(n > 3) val2 += (u + 1) * diff[n-4][3];

    double fpp = val2 / (h * h);

    cout<<"f'(x) = "<<fp<<endl;
    cout<<"f''(x) = "<<fpp<<endl;
    return 0;
}