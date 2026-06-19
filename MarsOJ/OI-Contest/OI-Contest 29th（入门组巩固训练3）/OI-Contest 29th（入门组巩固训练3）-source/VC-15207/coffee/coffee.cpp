#include<bits/stdc++.h>
using namespace std;
long long n,m,t;
long long f[10][10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    cin>>t;
    while(t--){
        long long cnt=0,ans=0;
        for (int i=1;i<=5;i++)
            for (int j=1;j<=8;j++) {
                string s;cin>>s;
                if (s=="math") {cnt++;f[i][j]=1;}
                if (s=="chinese") {f[i][j]=2;}
                if (s=="english") {f[i][j]=3;}
                if (s=="science") {f[i][j]=4;}
            }
        cin>>n>>m;
        ans+=cnt*(floor(n*1.0/7));
        n%=7;
        for (int i=0;i<n;i++)
            if ((m+i)%7<=5 && (m+i)%7>=1){
                int l=0;
                for (int j=1;j<=8;j++)
                    if(f[(m+i)%7][j]==1) l++;
                ans+=l;
            }
        cout<<ans<<"\n";
    }
    return 0;
}
