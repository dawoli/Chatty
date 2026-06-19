#include<bits/stdc++.h>
using namespace std;
long long t,n,m,d[10],sum,ans;
string s[10];
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    cin>>t;
    cout<<t;
    for(int k=0;k<t;k++){
        getchar();
        ans=0;
        sum=0;
        memset(d,0,sizeof(d));
        for(int i=0;i<5;i++){
            getline(cin,s[i]);
        }
        scanf("%d%d",&n,&m);
        for(int j=0;j<5;j++){
            for(int i=0;i<s[j].size();i++){
                if(s[j][i]=='m'){
                    d[j]++;
                    i+=4;
                }else i+=7;
            }
            sum+=d[j];
        }
        while(m!=1&&m!=8){
            ans+=d[m];
            m++;
            n--;
        }
        ans+=n/7*sum;
        n%=7;
        while(n){
            ans+=d[m];
            m++;
            n--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
