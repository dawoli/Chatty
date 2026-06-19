#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
const int N=200009;
const int mod=998244353;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		s=s*10+(ch^48);
		ch=getchar();
	}
	return s*f;
}
int n,r[N],ans;
multiset<int> s;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)r[i]=read();
	sort(r+1,r+n+1);
	ans=n;
	s.insert(r[1]);
	for(int i=2;i<=n;i++){
		if(r[i]>*s.begin())s.erase(s.begin()),ans--;
		s.insert(r[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
