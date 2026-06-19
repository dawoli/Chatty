#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = b;i >= a;--i)
const ll N = 100005;
ll n,cnt;
string s;
map<string,bool> mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%lld",&n);
	rep(i,1,n){
		cin >> s;
		if(!mp[s])++cnt;
		mp[s] = 1;
	}
	printf("%lld\n",52 - cnt);
	return 0;
}
