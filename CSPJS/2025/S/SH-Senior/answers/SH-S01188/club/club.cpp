#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5 + 10;

struct per {
	ll a, b, c;
	ll d, e, f;
	ll times;
	bool operator<(const per &p) const {
		if(a != p.a) return a > p.a;
		if(b != p.b) return b > p.b;
		return c > p.c;
	}
};

per s[N];
int rd[10][10];
int want[N];

void init() {
	//1 2 3    1 3 2     2 1 3    2 3 1     3 1 2    3 2 1
	rd[0][0] = 1;
	rd[0][1] = 2;
	rd[0][2] = 3;
	rd[1][0] = 1;
	rd[1][1] = 3;
	rd[1][2] = 2;
	rd[2][0] = 2;
	rd[2][1] = 1;
	rd[2][2] = 3;
	rd[3][0] = 2;
	rd[3][1] = 3;
	rd[3][2] = 1;
	rd[4][0] = 3;
	rd[4][1] = 1;
	rd[4][2] = 2;
	rd[5][0] = 3;
	rd[5][1] = 2;
	rd[5][2] = 1;
}

void solve1(ll n) {
	queue <per> q;
	per k = {0, 0, 0, 0, 0, 0, 1};
	q.push(k);
	ll ans = -1;
	while(!q.empty()) {
		k = q.front();
		q.pop();
		if(k.times > n) {
			ans = max(ans, k.a + k.b + k.c);
			continue;
		}
		per mid1 = {k.a + s[k.times].a,k.b,k.c,k.d + 1,k.e,k.f,k.times + 1};
		if(k.d + 1 <= n / 2) q.push(mid1);
		per mid2 = {k.a,k.b + s[k.times].b,k.c,k.d,k.e + 1,k.f,k.times + 1};
		if(k.e + 1 <= n / 2) q.push(mid2);
		per mid3 = {k.a,k.b,k.c + s[k.times].c,k.d,k.e,k.f + 1,k.times + 1};
		if(k.f + 1 <= n / 2) q.push(mid3);
		//if(k.d == k.e && k.e == k.f && k.f == 1) printf("%d,",k.times);
	}
	printf("%lld\n",ans);
	return;
}

int get(per f, int id) {
	if(id == 1) return f.a;
	if(id == 2) return f.b;
	return f.c;
}

void repl(per& f,int id) {
	if(id == 1) f.a = 0;
	else if(id == 2) f.b = 0;
	else if(id == 3) f.c = 0;
	else f.a = f.b = f.c = 0;
}

int main() {
	init();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--) {
		ll n;
		scanf("%lld",&n);
		bool only = true,twice = true;
		for(ll i = 1;i <= n;i++) {
			scanf("%lld%lld%lld",&s[i].a,&s[i].b,&s[i].c);
			if(s[i].b != 0 || s[i].c != 0) only = false;
			if(s[i].c != 0) twice = false;
		}
		if(n <= 14) {
			solve1(n);
		}
		else if(only == true) {
			sort(s + 1,s + n + 1);
			int ans = 0;
			for(int i = 1;i <= n / 2;i++) {
				ans += s[i].a;
			}
			printf("%lld",ans);
		}
		else {
			int a[10] = {0, 0, 0, 0};
			int f[10] = {0, 0, 0, 0};
			for(int r = 0;r < 6;r++) {
				for(int g = 0;g < 3;g++) {
					for(int q = 0;q < 3;q++) {
						bool in = true;
						sort(s + 1,s + n + 1);
						for(int i = 1;i <= n;i++) {
							if(s[i].a == s[i].b && s[i].b == s[i].c && s[i].c == 0) want[i] = 0;
							else if(s[i].a >= s[i].b && s[i].a >= s[i].c) want[i] = 1;
							else if(s[i].b >= s[i].a && s[i].b >= s[i].c) want[i] = 2;
							else want[i] = 3;
						}
						for(int i = 1;i <= n;i++) {
							if(f[rd[r][q]] >= n / 2) in = false;
							if(want[i] == rd[r][q] && in) {
								a[rd[r][q]] += get(s[i], rd[r][q]);
								f[rd[r][q]]++;
								s[i].a = s[i].b = s[i].c = 0;
							}
							else {
								repl(s[i], rd[r][q]);
							}
						}
					}
				}
			}
			
			printf("%lld\n",a[1] + a[2] + a[3]);
		}
	}
	return 0;
}
