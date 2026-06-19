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
#define N 105 
ll n,m,a[N],sc;
#undef N
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n = read(),m = read();
	a[1] = sc = read();
	rep(i,2,n * m)a[i] = read();
	sort(a + 1,a + n * m + 1);
	ll pos = 0;
	per(i,1,n * m){
		++pos;
		if(a[i] == sc)break;
	}
	cout << (pos - 1) / n + 1 << " ";
	if(((pos - 1) / n + 1) % 2 == 1)cout << (pos - 1) % n + 1 << "\n";
	else cout << n + 1 - (pos - 1) % n - 1 << "\n";
	return 0;
}

