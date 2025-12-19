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
    int n;
while (fin>>n)
{
     vector<double>x(n),y(n);
    for(int i=0;i<n;i++)fin>>x[i];
    for(int i=0;i<n;i++)fin>>y[i];
    double sop=0,pos=0,sxs=0,SoX=0,SoY=0;
    for(int i=0;i<n;i++ ){
        SoX+=x[i];
        SoY+=y[i];
        sop+=(x[i]*y[i]);
        sxs+=(x[i]*x[i]);
    }
      pos=SoX*SoY;
      double b=(n*sop-pos)/(n*sxs-SoX*SoX);
      double a=SoY/n-b*(SoX/n);
    
      fout<<"y="<<a<<"+"<<b<<"x"<<endl;
}

 
 return 0; }