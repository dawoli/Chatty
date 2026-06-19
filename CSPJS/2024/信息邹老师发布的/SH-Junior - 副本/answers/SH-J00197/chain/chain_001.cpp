#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = b;i >= a;--i)
const ll N = 1005,R = 105,L = 2005;
ll T,n,k,q,s[N],r,c,t[L],addd,Cnt,tt[L],Cnt2,dpp[N][N];
vector<ll> a[N];
map<ll,map<ll,map<ll,bool> > >Lk,dp;
void solve(ll r,ll c,ll pr){
	if(dp[r][c][pr] || r > 5)return;
	if(r != 0)dp[r][c][pr] = 1,dpp[r][c] = 1;
	rep(to,1,Cnt2){
		rep(i,1,n){
			if((i == pr || !Lk[c][to][i]))continue;
//			printf("from:%lld to:%lld, num1:%lld num2:%lld\n",pr,i,c,to);
			solve(r + 1,to,i);
		}
		ll i = 1001;
		if(i == pr || !Lk[c][to][i])continue;
//		printf("from:%lld to:%lld, num1:%lld num2:%lld\n",pr,i,c,to);
		solve(r + 1,to,i);
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		dp.clear();
		Cnt = Cnt2 = 0;
		scanf("%lld%lld%lld",&n,&k,&q);
		rep(i,1,n){
			scanf("%lld",&s[i]);
			a[i].clear();
			rep(j,1,s[i]){
				scanf("%lld",&addd);
				a[i].push_back(addd);
				t[++Cnt] = addd;
			}
		}
//		cout << q << endl;
//		cout << "testing" << endl; 
		sort(t + 1,t + Cnt + 1);
		rep(i,1,Cnt)if(t[i] != t[i - 1])tt[++Cnt2] = t[i];
		swap(Cnt,Cnt2);
		rep(i,1,n){
			rep(j,0,s[i] - 1){
				a[i][j] = lower_bound(tt + 1,tt + Cnt + 1,a[i][j]) - tt;
//				cout << a[i][j] << " ";
			}
//			cout << endl;
			rep(j,0,s[i] - 1){
				rep(f,1,k - 1){
					if(j + f >= s[i])break;
					Lk[a[i][j]][a[i][j + f]][i] = 1;
//					cout << a[i][j] << "->" << a[i][j + f] << " by:" << i << endl; 
				}
			}
		}
		Lk[0][lower_bound(tt + 1,tt + Cnt + 1,1) - tt][1001] = 1;
		solve(0,1,1001);
		Lk[0][lower_bound(tt + 1,tt + Cnt + 1,1) - tt][1001] = 0;
		rep(i,1,n){
			rep(j,0,s[i] - 1){
				rep(f,1,k - 1){
					if(j + f >= s[i])break;
					Lk[a[i][j]][a[i][j + f]][i] = 0;
//					cout << a[i][j] << "->" << a[i][j + f] << " by:" << i << endl; 
				}
			}
		}
//		rep(i,1,1){
//			rep(j,1,Cnt){
//				cout << dp[i][j] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
		while(q--){
//			cout << q << endl;
			scanf("%lld%lld",&r,&c);
			printf("%lld\n",dpp[r][lower_bound(tt + 1,tt + Cnt + 1,c) - tt]);
		}
	}
	return 0;
}
/*
注意到这个游戏轮数为100
O(nrLk)期望得分10分
O(好慢)期望得分60分 
*/
