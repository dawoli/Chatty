#include <bits/stdc++.h>
using namespace std;
ifstream fin("employ.in");
ofstream fout("employ.out");
long long n,m,ans,c[100005];
string s;
int main(){
    fin>>n>>m;
    fin>>s;
    for(int i=0;i<n;++i){
        fin>>c[i];
    }
    ans=1;
    for(int i = 1; i <= n; ++i){
        ans=ans*i%998244353;
    }
    fout<<ans<<endl;
    return 0;
}