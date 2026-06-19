#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f

const int maxn=1e5+5;

int d[maxn], v[maxn], a[maxn];
int p[maxn];
struct Seg {
    pair<int,int> lr;
    bool det;
} s[maxn];
int cnt=0;
int n,m,L,V,ans;
bool det[maxn];

bool cmp(Seg x, Seg y) {
    if(!x.det) return false;
    if(!y.det) return true;
    return x.lr<y.lr;
}

int read() {
    char c=getchar();
    int flag=1;
    while(!('0'<=c&&c<='9')) {
        if(c=='-') flag=-1;
        c=getchar();
    }
    int ans=0;
    while('0'<=c&&c<='9') {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*flag;
}

void print(int x) {
    if(!x) {
        putchar('0');
        return ;
    }
    char buf[100];
    int tot=0;
    while(x) {
        buf[++tot]=x%10+'0';
        x/=10;
    }
    for(int i=tot;i>=1;i--)putchar(buf[i]);
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    T=read();
    while(T--) {
        n=read(), m=read(), L=read(), V=read();
        ans=0;
        for(int i=1;i<=n;i++) d[i]=read(), v[i]=read(), a[i]=read();
        for(int i=1;i<=m;i++) p[i]=read();
        int t;
        cnt=0;
        for(int i=1;i<=n;i++) {
            if(v[i]<=V&&a[i]<=0) continue;
            if(v[i]>V&&a[i]>=0) {
                s[++cnt].lr=make_pair(d[i], L);
            }
            else if(v[i]<=V&&a[i]>0) {
                t=d[i]+(V*V-v[i]*v[i]+(a[i]<<1))/(a[i]<<1);
                if(t<=L) s[++cnt].lr=make_pair(t,L);
            } else {
                t=d[i]+(v[i]*v[i]-V*V-1)/abs(2*a[i]);
                s[++cnt].lr=make_pair(d[i], min(t,L));
                // cout<<t<<'\n';
            }
        }
        for(int i=1;i<=cnt;i++) {
            s[i].lr=make_pair(lower_bound(p+1,p+m+1,s[i].lr.first)-p, upper_bound(p+1,p+m+1,s[i].lr.second)-p-1);
            if(s[i].lr.first<=s[i].lr.second) ans++, s[i].det=true;
            else s[i].det=false;
        }
        print(ans); 
        putchar(' ');
        sort(s+1,s+cnt+1,cmp);
        int rit=-2;
        ans=0;
        for(int i=1;i<=cnt;i++) {
            if(!s[i].det) break;
            if(s[i].lr.first>rit) rit=s[i].lr.second, ans++;
            rit=min(rit, s[i].lr.second);
            // cout<<s[i].lr.first<<' '<<s[i].lr.second<<'\n';
        }
        print(m-ans);
        putchar('\n');
    }
    
    return 0;
}