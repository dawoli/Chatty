#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = a;i <= b;++i)
ll n,m,c[5005],q,T,ok[15][9005],x[5],a[9006],champ[9006],res;
pair<ll,ll> A[15][9006];
void update(ll pos,ll num,ll k1,ll H1){
	A[1][pos].first = num;
	rep(j,1,k1){
		rep(k,1,H1 / 2){
			if(ok[j][k] == 0){
				if(A[j][2 * k - 1].first < j)A[j + 1][k] = A[j][2 * k];
				else A[j + 1][k] = A[j][2 * k - 1];
			}
			else{
				if(A[j][2 * k].first < j)A[j + 1][k] = A[j][2 * k - 1];
				else A[j + 1][k] = A[j][2 * k];
			}
//			cout << A[j + 1][k].second << " ";
		}
		H1 /= 2;
//		cout << endl;
	}
//	cout << A[k1 + 1][1].second << "could be the champion!!!\n";
//	cout << "-------------------" << endl;
	champ[A[k1 + 1][1].second] = 1;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	rep(i,1,n)scanf("%lld",&a[i]);
	rep(i,1,m)scanf("%lld",&c[i]);
	ll k = 0,H = 1;
	while(H < n)++k,H *= 2;
	rep(i,1,k){
		string t;
		cin >> t;
		rep(j,1,H)ok[i][j] = t[j - 1] - '0';
		H /= 2; 
	}
	scanf("%lld",&T);
	while(T--){
//		cout << "T" << endl;
		rep(i,0,3)scanf("%lld",&x[i]);
		rep(i,1,m){
//			cout << "for i=" << i << "\n";
			ll k1 = 0,H1 = 1,HH1;
			rep(p,c[i - 1],c[i])A[1][p].first = a[p] ^ x[p % 4],A[1][p].second = p;
			while(H1 < c[i])++k1,H1 *= 2;
			HH1 = H1;
			rep(p,c[i] + 1,H1)A[1][p].first = 0,A[1][p].second = p;
//			rep(p,H1 + 1,9000)A[1][p].second = 0;
//			cout << H1 << " " << c[i] + 1 << endl;
			rep(j,1,k1){
				rep(k,1,H1 / 2){
					if(ok[j][k] == 0){
						if(A[j][2 * k - 1].first < j)A[j + 1][k] = A[j][2 * k];
						else A[j + 1][k] = A[j][2 * k - 1];
					}
					else{
						if(A[j][2 * k].first < j)A[j + 1][k] = A[j][2 * k - 1];
						else A[j + 1][k] = A[j][2 * k];
					}
//					cout << A[j + 1][k].second << " ";
				}
				H1 /= 2;
//				cout << endl;
			}
//			cout << A[k1 + 1][1].second << "could be the champion!!!\n";
			champ[A[k1 + 1][1].second] = 1;
//			cout << "----------------------" << endl;
			rep(p,c[i] + 1,HH1){
//				cout << "change:------------------->" << p << endl;
				update(p,1e12,k1,HH1);
				update(p,0,k1,HH1);
			}
			ll ans = 0;
			rep(p,1,HH1){
				if(champ[p])ans += p,champ[p] = 0; 
			}
//			cout << ans * i << endl;
			res ^= ans * i;
		}
//		cout << 8345791815813 << endl;
		printf("%lld\n",res);
		res = 0;
	}
	return 0;
}
/*
2 2 1 2 6
1 2 3 4 5

2 4 3 8 30

11110
01000
00011
00100
00010
*/
