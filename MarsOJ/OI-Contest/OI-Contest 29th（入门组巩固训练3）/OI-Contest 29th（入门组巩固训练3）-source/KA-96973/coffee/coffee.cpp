#include<bits/stdc++.h>
using namespace std;
long long a[10],ans,cnt,tmp;
string s;
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    int t,n,m;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        cnt=ans=0;a[1]=a[2]=a[3]=a[4]=a[5]=a[6]=a[0]=0;
        for(int j=1;j<=5;j++){
            for(int z=1;z<=8;z++){
                s="";
                cin>>s;
                for(int z=0;z<s.size();z++){
                    if(s[z]=='m') a[j]++;
                }
            }
            ans+=a[j];
        }
        scanf("%d%d",&n,&m);
        cnt=n/7*ans;
        if(m==6&&n>=2)n-=2,m=1;
        if(m==7&&n>=1)n-=1,m=1;
        n%=7;
        for(int j=0;j<n;j++){
            cnt+=a[(m+j)%7];
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
