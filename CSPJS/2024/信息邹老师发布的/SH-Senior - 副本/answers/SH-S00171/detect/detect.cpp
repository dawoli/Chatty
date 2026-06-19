#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    char ch=getchar();int x=0,y=1;
    while(!isdigit(ch)){
        if(ch=='-')y=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*y;
}
int T;
int n,m,L,V;
int d[100005];
int v[100005];
int a[100005];
int p[100005];
int nxt[100005];
int f[100005];
bool isOverSpeed(int x,int sv,int sa){
    //v^2-v0^2=2ax
    int sq=sv*sv+2*sa*x;
    return sq>V*V;
}
int stk[100005];
int dl=1,dr=0;
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    T=read();
    while(T--){
        n=read();m=read();L=read();V=read();
        for(int i=1;i<=n;i++)d[i]=read(),v[i]=read(),a[i]=read();
        for(int i=1;i<=m;i++)p[i]=read();
        p[0]=0;p[m+1]=L+1;
        for(int i=0;i<=m;i++)nxt[i]=m+1;
        int cnt=0;
        for(int i=1;i<=n;i++){//2 5 8 9 15
            int dl=lower_bound(p+1,p+m+1,d[i])-p;
            int dr;
            {
                if(a[i]>=0)dr=m;
                else{
                    int up=v[i]*v[i];
                    int down=-a[i]*2;
                    dr=upper_bound(p+1,p+m+1,d[i]+up/down)-p-1;
                }
            }
            if(a[i]<=0){
                int o=dl;
                if(o==m+1 or !isOverSpeed(p[o]-d[i],v[i],a[i]))continue;
                cnt++;int l=o,r=dr,res=o;
                while(l<=r){
                    int mid=(l+r)>>1;
                    if(isOverSpeed(p[mid]-d[i],v[i],a[i]))res=mid,l=mid+1;
                    else r=mid-1;
                }
                nxt[o-1]=min(nxt[o-1],res);
            }else if(a[i]>0){
                //v^2/2a
                int o=dr;
                if(dl==m+1 or !isOverSpeed(p[o]-d[i],v[i],a[i]))continue;
                cnt++;int l=dl,r=o,res=o;
                while(l<=r){
                    int mid=(l+r)>>1;
                    if(isOverSpeed(p[mid]-d[i],v[i],a[i]))res=mid,r=mid-1;
                    else l=mid+1;
                }
                nxt[res-1]=min(nxt[res-1],o);
            }
        }
        for(int i=m-1;i>=0;i--)nxt[i]=min(nxt[i],nxt[i+1]);
        for(int i=0;i<=m+1;i++)f[i]=0;
        dl=1,dr=1;stk[1]=m+1;
        for(int i=m;i>=0;i--){
            while(dl<=dr and stk[dl]>nxt[i])dl++;
            f[i]=f[stk[dl]]+1;
            while(dl<=dr and f[i]<=f[stk[dr]])dr--;
            stk[++dr]=i;
        }
        cout<<cnt<<" "<<m-f[0]+1<<endl;
    }
    return 0;
}
