#include<bits/stdc++.h>
using namespace std;
int n,k,a[6];
string s[6][9];
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        for(int i=1;i<=5;i++){
            for(int j=1;j<=8;j++){
                cin>>s[i][j];
                if(s[i][j]=="math")a[i]++;
            }
        }
        cin>>n>>k;
        long long ans=n/7*(a[1]+a[2]+a[3]+a[4]+a[5]);
        k=(k+n%7)%7;
        for(int i=1;i<=5;i++){
            if(i<=k)ans+=a[i];
        }
        cout<<ans<<endl;
    }
}
