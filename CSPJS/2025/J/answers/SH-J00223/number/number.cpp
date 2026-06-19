#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = b;i >= a;--i)
typedef long long ll;
inline ll read(){
	ll x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9')x = x * 10 + ch - '0',ch = getchar();
	return x * f;
}
string s;
vector<ll> res;
ll n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n = s.size();
	s = " " + s;
	rep(i,1,n)if('0' <= s[i] && s[i] <= '9')res.push_back(s[i] - '0');
	sort(res.begin(),res.end());
	if(res.size())per(i,0,res.size() - 1)putchar(res[i] + '0');
	puts("");
	return 0; 
}
