#include<bits/stdc++.h>
#define INF 1e9
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define Rep(i,l,r) for(int i=(l);i>=(r);i--)
#define gc getchar()
using namespace std;
typedef long long ll;
namespace fastIO{
	ll read(){
		ll x=0,f=1;char ch=gc;
		while(ch<'0'||ch>'9'){
			if(ch=='-'){
				f=-1;
			}
			ch=gc;
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc;
		return x*f;
	}
}
using namespace fastIO;
set<string> s;
int n;
signed main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	n=read();
	rep(i,1,n){
		string p;
		cin>>p;
		s.insert(p);
	}
	cout<<52-s.size()<<endl;
	return 0;
}

