#include<bits/stdc++.h>
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
int read(){
    int x=0;
    bool neg=0;
    char ch=gc();
    while(ch<'0'||ch>'9')
        neg|=(ch=='-'),
        ch=gc();
    while(ch>='0'&&ch<='9')
        x=x*10+(ch^48),
        ch=gc();
    return neg?-x:x; //             -2147483648 bug
}
int n;
int cnt[3],val[3];
int ans;
vector<int>V[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--){
        n=read();
        memset(cnt,0,sizeof(cnt));
        ans=0;
        for(int i=0;i<3;i++)
            V[i].clear();
        for(int j=0;j<n;j++){
            int b=0;
            for(int i=0;i<3;i++){
                val[i]=read();
                if(val[i]>val[b])
                    b=i;
            }
            ans+=val[b];
            cnt[b]++;
            int x=20004;
            for(int i=0;i<3;i++)
                if(i!=b&&x>val[b]-val[i])
                    x=val[b]-val[i];
            V[b].push_back(x);
        }
        for(int i=0;i<3;i++)
            if(cnt[i]>(n>>1)){
                sort(V[i].begin(),V[i].end());
                n=cnt[i]-(n>>1);
                while(n--)
                    ans-=V[i][n];
                break;
            }
        printf("%d\n",ans);
    }
    return 0;
}