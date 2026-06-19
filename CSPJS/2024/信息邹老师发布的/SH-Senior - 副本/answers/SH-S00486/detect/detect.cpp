#include<bits/stdc++.h>
using namespace std;
inline long long red(){
    long long   s=0;
    long long  pu=0;
    long long flag=1;
    char ch=getchar();
    while(ch<'0'||'9'<ch){
        if(ch=='-') flag=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        s=s*10+(ch-'0');
        ch=getchar();
    }
    pu=s*flag;
    return pu;
}
struct node{
    long long  id;
    long long ins;
    long long vi;
    long long ai;
    bool flag=0;
}car[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
    int T;
    T=red();
    for (int i=1;i<=T;i++){
        bool ask=1;
        long long n,m,L,V;
        n=red();
        m=red();
        L=red();
        V=red();
        long long monitor[100005];
        memset(monitor,0,sizeof(monitor));
        for(long j=1;j<=n;j++){
            long long  d,v,a;
            d=red();
            v=red();
            a=red();
            if (a<0) ask=0;
            car[j].id=j;
            car[j].ins=d;
            car[j].vi=v;
            car[j].ai=a;
        }
        for(long long k=1;k<=m;k++){
            monitor[k]=red();
        }
        if(ask!=0){
            long long ans1=0;
            long long ans2=m-1;
            long long  last=monitor[m];
            long long  limit=V*V;
            for( long long al=1;al<=n;al++){
                long long speed=car[al].vi*car[al].vi+2*car[al].ai*(last-car[al].ins);
                if(last<car[al].ins) continue;
                if (speed>limit) ans1++;
            }
            if(ans1==0) ans2++;
            cout<<ans1<<' '<<ans2<<endl;
        }
        else{
            long long ans1=0;
            long long ans2=m+2;
            long long  limit=V*V;
            for( long long al=1;al<=n;al++)
            {
                for(long long ap=1;ap<=m;ap++){
                    long long speed=car[al].vi*car[al].vi+2*car[al].ai*(monitor[ap]-car[al].ins);
                    if(monitor[ap]<car[al].ins) continue;
                    if (speed>limit) car[al].flag=1;

                }
                if(car[al].flag==1) ans1++;
                if(car[al].ai<0) ans2--;
            }
            if(ans1==0) ans2++;
            cout<<ans1<<' '<<ans2<<endl;
        }
    }
    return 0;
}
