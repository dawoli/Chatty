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
void write(ll x){
	if(x < 0)putchar('-'),x = -x;
	write(x / 10);
	putchar(x % 10 + '0');
	return;
}
#define N 500005
ll n,k,a[N],s[N],res;
map<ll,bool> mp;
#undef N
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n = read(),k = read();
	rep(i,1,n)a[i] = read(),s[i] = s[i - 1] ^ a[i];
	rep(i,0,n){
		if(mp[s[i]])++res,mp.clear();
		mp[s[i] ^ k] = 1;
	}
	cout << res << endl;
	return 0;
}

