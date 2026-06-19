#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define Rep(i,l,r) for(int i=(l);i>=(r);--i)
#define gc getchar()
#define INF 1e18
using namespace std;
namespace fastIO{
	int read(){
		int x=0,f=1;
		char ch=gc;
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=-1;
			ch=gc;
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+(ch-'0');
			ch=gc;
		}
		return x*f;
	}
}
using namespace fastIO;
int n,m;
int a[109];
map<int,int> mp;
int rt;
void solve(int x){
	int c=(x+m-1)/m;
	int r=(x-1)%m+1;
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r<<endl;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	rep(i,1,n*m){
		a[i]=read();
	}
	rt=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	rep(i,1,n*m){
		mp[a[i]]=i;
	}
	int nw=mp[rt];
//	cout<<nw<<endl;
	solve(nw);
	return 0;
}

