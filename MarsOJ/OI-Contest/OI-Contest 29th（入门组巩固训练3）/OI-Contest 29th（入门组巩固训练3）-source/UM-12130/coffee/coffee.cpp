#include<bits/stdc++.h>
using namespace std;
long long t,n,m,a[10],sum,ans;
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    cin>>t;
    while(t--){
        ans=sum=0;
        memset(a,0,sizeof a);
        for(int w=1;w<=5;w++){
            for(int l=1;l<=8;l++){
                string s;cin>>s;
                if(s=="math") sum++;
            }
        }
        cin>>n>>m;
        ans+=sum*(n/7);
        n%=7;
        for(int i=1;i<=n;i++){
            if(++m>7) m=1;
            if(1<=m&&m<=5) ans+=a[m];
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
