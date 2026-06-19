#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,r[N];
int cnt1[N],cnt2[N],rd[N],cntd,ans;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x*f;
}

void solve(){
	n=read();
	for(int i=1;i<=n;++i){
		r[i]=read();
		++cnt1[r[i]]; ++cnt2[r[i]];
	}
	sort(r+1,r+1+n);
	for(int i=1;i<=n;++i){
		if(r[i]!=rd[cntd]) rd[++cntd]=r[i];
		if(r[i]==r[n]) break;
	}
//	for(int i=1;i<=rd[cntd];++i)cout<<cnt1[i]<<' '<<cnt2[i]<<endl;
	int c1=1,c2=2;
	while(c2<=cntd){
		while(c1<c2&&cnt1[rd[c1]]<=cnt2[rd[c2]]){
			ans+=cnt1[rd[c1]];
			cnt2[rd[c2]]-=cnt1[rd[c1]];
			++c1;
		}
		if(c1==c2){
			++c2;
			continue;
		}
		if(cnt2[rd[c2]]!=0){
			ans+=cnt2[rd[c2]];
			cnt1[rd[c1]]-=cnt2[rd[c2]];
		}
		++c2;
	}
	ans=n-ans;
	cout<<ans<<endl;
}

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	solve();
	return 0;
}
