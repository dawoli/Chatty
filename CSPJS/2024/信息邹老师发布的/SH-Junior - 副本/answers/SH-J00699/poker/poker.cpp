#include<bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define all(x) x.begin(),x.end()
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define Rset(x) Set(x,0)
#define cll const long long 
using namespace std;
cll N=60;
bool hv[N];
set<string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ll n;cin>>n;
	rep(i,1,n){string x;cin>>x;s.insert(x);}
	cout<<52-s.size()<<endl;
	return 0;
}
