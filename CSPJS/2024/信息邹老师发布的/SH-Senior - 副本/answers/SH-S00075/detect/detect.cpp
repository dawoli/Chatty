#include <cstdio>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar((x%10)^48);
}
const int N=1e5+5;
const int M=1e5+5;
int n,m,len,lim,d[N],v[N],a[N],p[M],cnt1,cnt2,BiT[M];
inline int lowbit(int x) {return x&-x;}
inline void add(int i,int x) {
	while(i<=m) {
		BiT[i]+=x;
		i+=lowbit(i);
	}
}
inline int ask(int End) {
	int sum=0;
	while(End) {
		sum+=BiT[End];
		End-=lowbit(End);
	}
	return sum;
}
struct Section {
	int l,r;
	bool operator<(const Section &s) const {
		return r<s.r or r==s.r and l<s.l;
	}
} sec[N];
void init() {
	for(int i=1;i<=n;i++) sec[i]={0,0};
	fill(BiT+1,BiT+m+1,0);
	cnt1=cnt2=0;
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t=read();
	while(t--) {
		n=read(),m=read(),len=read(),lim=read();
		for(int i=1;i<=n;i++)
			d[i]=read(),v[i]=read(),a[i]=read();
		for(int i=1;i<=m;i++) p[i]=read();
		for(int i=1;i<=n;i++) {
			if(a[i]==0) {
				if(v[i]>lim and p[m]>=d[i])
					sec[++cnt1]={lower_bound(p+1,p+m+1,d[i])-p,m};
			} else if(a[i]>0) {
				int l=lower_bound(p+1,p+m+1,d[i])-p,r=m,ans=0;
				while(l<=r) {
					int mid=(l+r)>>1;
					double vNow=sqrt(v[i]*v[i]+2*a[i]*(p[mid]-d[i]));
					if(vNow>lim) r=mid-1,ans=mid;
					else l=mid+1;
				}
				if(ans) sec[++cnt1]={ans,m};
			} else if(a[i]<0) {
				if(v[i]>lim) {
					int l=lower_bound(p+1,p+m+1,d[i])-p,r=m,ans=0;
					int k=l;
					while(l<=r) {
						int mid=(l+r)>>1;
						int k=v[i]*v[i]+2*a[i]*(p[mid]-d[i]);
						if(k<0) {r=mid-1; continue;}
						double vNow=sqrt(k);
						if(vNow<=lim) r=mid-1;
						else l=mid+1,ans=mid;
					}
					if(ans) sec[++cnt1]={k,ans};
				}
			}
		}
		write(cnt1);putchar(' ');
		sort(sec+1,sec+cnt1+1);
		for(int i=1;i<=cnt1;i++) {
			if(ask(sec[i].r)-ask(sec[i].l-1)==0) {
				cnt2++;
				add(sec[i].r,1);
			}
		}
		write(m-cnt2); putchar('\n');
		init();
	}
	return 0;
}
