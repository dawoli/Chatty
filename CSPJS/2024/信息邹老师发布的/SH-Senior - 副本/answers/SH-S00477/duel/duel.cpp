#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,r[maxn],t[maxn],maxr,sf[maxn],sh[maxn],cnt,ans;
bool flag;
inline int read(){
	int x(0),f(1);
	char c=getchar();
	while(c<'0' or c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0' and c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	ans=n;
	for(int i=1;i<=n;++i){
		r[i]=read();
		t[r[i]]++;
		maxr=max(maxr,r[i]);
	}
//	for(int i=1;i<=maxr;++i) sf[i]=sf[i-1]+t[i];
//	for(int i=1;i<=maxr;++i) sh[i]=sf[maxr]-sf[i-1];
	for(int i=1;i<=maxr;++i){
		if(flag==false) cnt=t[i],flag=true;
		else if(t[i]!=0) ans-=min(cnt,t[i]),cnt=t[i]+max(cnt-t[i],0);
	}
	cout<<ans<<'\n';
	return 0;
}

