#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0;
	bool f=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f^=1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	if(f) return -x;
	return x;
}
void write(long long x){
	static int stk[23];
	int tp=0;
	if(x<0) putchar('-'),x=-x;
	do{
		stk[++tp]=x%10,x/=10;
	}
	while(x);
	while(tp) putchar(stk[tp]+'0'),--tp;
}
void we(long long x){
	write(x);
	putchar('\n');
}
int t,n,m,L,v;
struct car{
	long long di,vi,ai;
}ca[100010];
long long p[100010];
struct xd{
	int ll,rr;
}xdd[100010];
int tot,ans,ml,dp[100010];
bool flag,flag2;
int find(long long ds,long long st,long long acc){
	int l=1,r=m;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ds<(p[mid]-st)*acc*2) r=mid-1;
		else l=mid+1;
	}
	return l;
}
int find2(long long ds,long long st,long long acc){
	int l=1,r=m;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ds>(p[mid]-st)*acc*2) l=mid+1;
		else r=mid-1;
	}
	return r;
}
bool cmp(xd a,xd b){
	if(a.ll!=b.ll) return a.ll<b.ll;
	return a.rr<b.rr;
}
int que[200010],fr,tai;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		m=read();
		L=read();
		v=read();
		for(int i=1;i<=n;i++) ca[i]=(car){read(),read(),read()};
		for(int i=1;i<=m;i++) p[i]=read();
		flag=flag2=0;
		ml=-1;
		tot=ans=0;
		p[m+1]=2000000000;
		for(int i=1;i<=n;i++){
			if(ca[i].vi<=v&&ca[i].ai<=0) continue;
			if(ca[i].ai>0){
				if(ca[i].vi<=v){
					long long dis=v*v-ca[i].vi*ca[i].vi;
					if(dis<(p[m]-ca[i].di)*2*ca[i].ai){
						ml=max(ml,find(dis,ca[i].di,ca[i].ai));
						++ans;
					}
				}
				else{
					if(p[m]>=ca[i].di){
						++ans;
						int pp=lower_bound(p+1,p+m+1,ca[i].di)-p;
						ml=max(ml,pp);
					}
				}
			}
			else if(ca[i].ai==0){
				if(p[m]>=ca[i].di){
					++ans;
					int pp=lower_bound(p+1,p+m+1,ca[i].di)-p;
					ml=max(ml,pp);
				}
			}
			else{
				ca[i].ai=-ca[i].ai;
				long long dis=ca[i].vi*ca[i].vi-v*v;
				if(p[m]<ca[i].di) continue;
				int ll=lower_bound(p+1,p+m+1,ca[i].di)-p;
				if(dis<=(p[ll]-ca[i].di)*2*ca[i].ai) continue;
				int rr=find2(dis,ca[i].di,ca[i].ai);
				xdd[++tot]=(xd){ll,rr};
				++ans;
			}
			
		}
		if(ml!=-1) xdd[++tot]=(xd){ml,m};
		sort(xdd+1,xdd+tot+1,cmp);
		fr=1;
		tai=0;
		int now=0;
		for(int i=1;i<=tot;i++){
			while(fr<=tai&&xdd[que[fr]].rr<xdd[i].ll) now=que[fr],++fr;
			dp[i]=dp[now]+1;
			while(fr<=tai&&xdd[que[tai]].rr>xdd[i].rr) --tai;
			que[++tai]=i;
		}
		write(ans);
		putchar(' ');
		we(m-dp[tot]);
	}
	return 0;
} 
