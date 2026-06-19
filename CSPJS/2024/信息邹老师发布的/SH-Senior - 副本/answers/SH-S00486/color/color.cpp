#include<bits/stdc++.h>
using namespace std;
inline long long red()
{
    long long   s=0;
    long long  pu=0;
    char ch=getchar();
    while(ch<'0'||'9'<ch){
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        s=s*10+(ch-'0');
        ch=getchar();
    }
    pu=s;
    return pu;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    long long  T;
    T=red();
    for(int i=1;i<=T;i++){
        long long n;
        n=red();
        long long Ai[20];
        long long maxans=0;
        long long a1[20];
        long long b1[20];
        long long c1[20];
        memset(Ai,0,sizeof(Ai));
        memset(a1,0,sizeof(a1));
        memset(b1,0,sizeof(b1));
        memset(c1,0,sizeof(c1));
        int cnta=0;
        int cntb=0;
        long long tr;
        tr=(1<<n)-(long long)1;
        for(long long j=0;j<n;j++)
		{
            Ai[j]=red();
        }
        for(long long p=0;p<=tr;p++)
		{
            long long ans=0;
            memset(a1,0,sizeof(a1));
            memset(b1,0,sizeof(b1));
            memset(c1,0,sizeof(c1));
            cnta=0;
            cntb=0;
            for (long long q=0;q<n;q++){
                if(((1<<q)&p)==0) {
                	if (cntb==0){
                		b1[++cntb]=Ai[q];
                		continue;
					}
                    long long tt=b1[cntb];
                    if(tt==Ai[q]) {
                        ans+=Ai[q];
                    }
                    b1[++cntb]=Ai[q];
                }
                else{
                	if (cnta==0){
                		a1[++cnta]=Ai[q];
                		continue;
					}
                    long long  tt=a1[cnta];
                    if(tt==Ai[q]) {
                        ans+=Ai[q];
                    }
                    a1[++cnta]=Ai[q];
                }
            }
            maxans=max(maxans,ans);
        }
        cout<<maxans<<endl;
    }
    return 0;
}
