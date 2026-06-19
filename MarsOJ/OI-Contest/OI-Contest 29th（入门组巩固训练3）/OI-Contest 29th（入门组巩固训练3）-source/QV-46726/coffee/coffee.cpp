#include <bits/stdc++.h>
using namespace std;
int a[6]={},n,m,t;
long long ans;
string s;
char c;
void read(){
    while(c<'a'||c>'z') c=getchar();
    for(s="";c>='a'&&c<='z';c=getchar()) s+=c;
}
int read1(){
    while(c<'0'||c>'9') c=getchar();
    int x=0;
    for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    return x;
}
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    t=read1();
    while(t--){
        for(int i=1;i<=5;i++){
            a[i]=a[i-1];
            for(int j=8;j;j--){
                read();
                if(s=="math") a[i]++;
            }
        }
        n=read1();
        m=read1();
        if(m+n<7){
            cout<<(a[min(n+m-1,5)]-a[min(m-1,5)])<<endl;
            continue;
        }
        n-=8-m;
        if(m<6) ans=a[5]-a[m-1];
        else ans=0;
        if(n<=0){
            cout<<ans<<endl;
            continue;
        }
        ans+=(1ll*(n/7)*a[5]+a[min(n%7,5)]);
        cout<<ans<<endl;
    }
    return 0;
}
