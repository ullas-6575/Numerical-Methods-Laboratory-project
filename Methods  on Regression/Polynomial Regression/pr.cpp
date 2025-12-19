#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int main() {

     ifstream fin("input.txt");
    ofstream fout("output.txt");
       if (!fin)
    {
        cerr << "Cannot open input file\n";
        return 1;
    }

int n ;
while(fin>>n){;
    vector<double>x(n),y(n);
    for(int i=0;i<n;i++)fin>>x[i];
    for(int i=0;i<n;i++)fin>>y[i];
     int d;fin>>d;int m=d+1;
//    vector<vector<double>>A= Polynomial(m,n,x,y,fin,fout);

    vector<double>sumpow(2*m-1);
    for(int i=0;i<=2*m-2;i++){
        double sum=0;
        for(int j=0;j<n;j++){
            sum+=pow(x[j],i);
        }
        sumpow[i]=sum;
    }
    
    vector<double>propow(m);
    for(int i=0;i<m;i++){
        double sum=0;
        for(int j=0;j<n;j++){
            sum+=(pow(x[j],i))*y[j];
            
        }
        propow[i]=sum;
    }
    
    // for(int i=0;i<m;i++)fout<<propow[i]<<" ";
    // fout<<endl;
    vector<vector<double>>A(m,vector<double>(m+1));
    for(int i=0;i<m;i++){
        int k=i;
        for(int j=0;j<m;j++){
            A[i][j]=sumpow[k];
            k++;
        }
        A[i][m]=propow[i];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<=m;j++){
            fout<<A[i][j]<<" ";
        }fout<<endl;
    }
    fout<<endl;
 

   fout<<endl;
   for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            double r=A[j][i]/A[i][i];
            for(int k=0;k<=m;k++){
                A[j][k]-=r*A[i][k];
            }
        }
    for(int i=0;i<m;i++){
    for(int j=0;j<m+1;j++){
        fout<<setw(6)<<A[i][j]<<" ";
    }fout<<endl;
   }fout<<endl;
   }

   for(int i=0;i<m;i++){
    for(int j=0;j<m+1;j++){
        fout<<setw(6)<<A[i][j]<<" ";
    }fout<<endl;
   }

   vector<double>sol(m);
   for(int i=m-1;i>=0;i--){
        sol[i]=A[i][m];
        for(int j=0;j<m;j++){
            if(i!=j)
            sol[i]-=A[i][j]*sol[j];
        }
        sol[i]/=A[i][i];
   }

   for(int i=0;i<m;i++)fout<<sol[i]<<" ";fout<<endl;
fout << "y = " << sol[0];
for(int i=1;i<m;i++) fout << " + " << sol[i] << "x^" << i;

}

 return 0; }