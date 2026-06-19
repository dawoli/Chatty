#include<bits/stdc++.h>
using namespace std;
int T;
int a,b,c,d,e;
long long ans;
int n,m;
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    cin>>T;
    while(T--){
        ans=a=b=c=d=e=0;
        string s;
        for(int j=0;j<8;j++){
            cin>>s;
            if(s=="math")a++;
        }
        for(int j=0;j<8;j++){
            cin>>s;
            if(s=="math")b++;
        }
        for(int j=0;j<8;j++){
            cin>>s;
            if(s=="math")c++;
        }
        for(int j=0;j<8;j++){
            cin>>s;
            if(s=="math")d++;
        }
        for(int j=0;j<8;j++){
            cin>>s;
            if(s=="math")e++;
        }
        cin>>n>>m;
        ans+=(a+b+c+d+e)*int(n/7);
        n=n%7;
        for(int day=m,i=1;i<=n;day++,i++){
            if(day==8)day=1;
            else if(day==1)ans+=a;
            else if(day==2)ans+=b;
            else if(day==3)ans+=c;
            else if(day==4)ans+=d;
            else if(day==5)ans+=e;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
