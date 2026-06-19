#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
int a[10];
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    cin>>t;
    while(t--){
        int sum=0;
        for(int i=1;i<=5;i++){
            a[i]=0;
            for(int j=1;j<=8;j++){
                string c;
                cin>>c;
                if(c=="math") a[i]++,sum++;
            }
        }
        cin>>n>>m;
        int b=7-m+1,ans=0;
        if(m!=1){
            n-=b;
            for(int i=m;i<=7;i++)
                ans+=a[i];
        }
        int c=n/7;
        ans+=c*sum;
        n-=c*7;
        for(int i=1;i<=n;i++){
            ans+=a[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
