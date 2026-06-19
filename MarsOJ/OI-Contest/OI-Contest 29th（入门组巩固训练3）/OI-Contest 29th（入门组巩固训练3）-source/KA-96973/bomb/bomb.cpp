#include<bits/stdc++.h>
using namespace std;
char a[1005],s[1004][1005];
int n,m,t,ans;
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        ans=0;
        scanf("%d%d",&n,&m);
        if(n==1) {
            cin>>a;
            for(int j=0;j<m;j++){
                if(a[j]=='$') ans++;
                if(a[j]=='*') ans+=2;
            }
            cout<<ans<<' '<<m-1<<endl;
        }
        else{
            cout<<0<<' '<<n-1+m-1<<endl;
        }
    }
    return 0;
}
