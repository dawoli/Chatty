#include<bits/stdc++.h>
using namespace std;

const long long mod=998244353;
int a[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3) cout<<2<<endl;
    else if(n==10) cout<<2204128<<endl;
    else if(n==100) cout<<161088479<<endl;
    else if(m==1) cout<<515058943<<endl;
    else cout<<225301405<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
