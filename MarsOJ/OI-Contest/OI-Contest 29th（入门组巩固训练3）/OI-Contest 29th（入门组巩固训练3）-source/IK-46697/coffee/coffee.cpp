#include <bits/stdc++.h>
#define int long long
using namespace std;

int read();
void write(int n);
int t,a[10],n,m,w;string s;
signed main()
{
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
    t=read();
    for(int i=1;i<=t;i++){
		w=0;
        for(int j=1;j<=5;j++){
            a[j]=0;
            for(int k=1;k<=8;k++){

                cin>>s;
                if(s=="math"){
                    a[j]++;
                }
            }
            w+=a[j];
        }
        n=read();
        m=read();
        int x=n%7,ans=0,day=m;
        for(int i=1;i<=x;i++){
            if(day>=1&&day<=5){
                ans+=a[day];
            }
            day++;
            if(day>7){
                day-=7;
            }
        }
        write(ans+n/7*w);
        putchar('\n');
    }
    return 0;
}

int read(){
    int x,y=1;char c;
    while((c=getchar())<'0'||c>'9') if(c=='-') y=-1;
    x=(c^48);
    while((c=getchar())>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48);
    return x*y;
}

void write(int n){
    if(n<0) putchar('-'),n=-n;
    if(n>9) write(n/10);
    putchar(n%10+48);
}
