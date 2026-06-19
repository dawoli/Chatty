//目前考虑前i次有希望的考试，并且其中恰好有j场考试成功,i-j场考试放弃 
//那些成功的考试中恰好有k个人的耐心值是小于等于t的（t=pos[i]-j）的方案数（考虑放弃的考试的人员安排以及这k个成功的人的人员安排） 
 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(ll i=a;i<=b;i++)
#define rrep(i, a, b) for(ll i=a;i>=b;i--)
const ll N=109, MOD=998244353;
ll n, m;
string str;
ll c[N];

int f[19][19][(1LL<<18)+9]; 
ll pos[N];
ll jc[N], njc[N];
ll power(ll u, ll t){
	ll res=1;
	while(t){
		if(t&1)(res*=u)%=MOD;
		(u*=u)%=MOD;
		t>>=1;
	}
	return res;
}
ll ppc[(1<<18)+9];
ll A(ll a, ll b){
	if(b>a)return 0;
	return jc[a]*njc[a-b]%MOD;
} 
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	cin >> str;
	str=" "+str;
//	return 0; 
	ll cnt1=0;
	rep(i, 1, n)if(str[i]=='1'){
		cnt1++;
		pos[cnt1]=i;
	}
	rep(i, 1, n){
		cin >> c[i];
	}
	jc[0]=1;
	rep(i, 1, n){
		jc[i]=jc[i-1]*i%MOD;
	}
	njc[n]=power(jc[n], MOD-2);
	rrep(i, n-1, 0){
		njc[i]=njc[i+1]*(i+1)%MOD;
	}
	sort(c+1, c+n+1);
	if(m==n){
		if(cnt1!=n){
			cout << 0 << endl;
		}else if(c[1]==0){
			cout << 0 << endl;
		}else{
			cout << jc[n] << endl;
		}
		return 0;
	} 
	rep(s, 0, (1LL<<n)-1){
		rep(i, 0, n-1){
			if(s&(1<<i)){
				ppc[s]++;
			}
		}
	}
	f[0][0][0]=1;
	rep(i, 0, n){
		rep(j, 0, i){
			rep(s, 0, (1<<n)-1){
				if(ppc[s]!=i)continue;
				rep(k, 1, n){
					if((s&(1<<(k-1)))==0){
						if(str[i+1]=='1')(f[i+1][j+(c[k]<=i-j?0LL:1LL)][s+(1<<(k-1))]+=f[i][j][s])%=MOD;
						else (f[i+1][j][s+(1<<(k-1))]+=f[i][j][s])%=MOD;
					}
				}
//				cout << i << ' ' << j << ' ' << s << ' ' << f[i][j][s] << endl;
				
			}
		}
	}
	ll ans=0;
	rep(j, m, n){
		ans+=f[n][j][(1<<n)-1];
		ans%=MOD;
	}
	cout << ans << endl;
	
	return 0;
}//注意一定要滚动数组！！！ 
