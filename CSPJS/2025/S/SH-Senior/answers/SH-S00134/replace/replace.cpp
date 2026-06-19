#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD1 = 1e9 + 7,MOD2 = 998244353,base = 1e8 + 7;
const int INF = 1e18 + 7;
char buf[1<<21],*p1,*p2;
#define gc() getchar()
template <typename T>
inline void read(T& x){
	int f = 1;
	x = 0;
	char ch = gc();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = gc();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = gc();
	}
	x *= f;
}
int fac1[5000010],fac2[5000010];
int n,q;
string s[200010][2],t[200010][2];
int Ls[200010],Rs[200010],Lt[200010],Rt[200010],lens[200010],lent[200010];
int ans[200010];
bool bans[200010],bant[200010];
map<vector<int>,int>mp;
int tott = 0;
vector<int>oo[200010],pp[200010];
struct Triee{
	int tot = 0,timer = 0;
	int ch[200010][26],dfn[200010],sz[200010];
	void init(){
		for(int i = 0; i <= tot; i++) memset(ch[i],0,sizeof(ch[i])),dfn[i] = sz[i] = 0;
		tot = timer = 0;
	}	
	int ins(string ss){
		int len = (int)ss.size();
		int u = 0;
		for(int i = 0; i < len; i++){
			int it = ss[i] - 'a';
			if(!ch[u][it]) ch[u][it] = ++tot;
			u = ch[u][it];
		}
		return u;
	}
	void dfs(int u){
		dfn[u] = ++timer;
		sz[u] = 1;
		for(int i = 0; i < 26; i++){
			if(!ch[u][i]) continue;
			dfs(ch[u][i]);
			sz[u] += sz[ch[u][i]];
		}
	}
}A,B;
int possa[200010],possb[200010],posta[200010],postb[200010];
struct node{
	int l,r,v;
};
vector<node>vc[200010];
int bit[5000010];
int LSB(int i){
	return i & (-i);
}
int SZ;
void upd(int i,int v){
	while(i <= SZ){
		bit[i] += v;
		i += LSB(i);
	}
}
int psq(int i){
	int res = 0;
	while(i){
		res += bit[i];
		i -= LSB(i);
	}
	return res;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	fac1[0] = 1;
	for(int i = 1; i <= 5000005; i++) fac1[i] = fac1[i - 1] * base % MOD1;
	fac2[0] = 1;
	for(int i = 1; i <= 5000005; i++) fac2[i] = fac2[i - 1] * base % MOD2;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>s[i][0]>>s[i][1];
		Ls[i] = -1;
		lens[i] = (int)s[i][0].size();
		for(int j = 0; j < lens[i]; j++){
			if(s[i][0][j] != s[i][1][j]){
				Ls[i] = j;
				break;
			}
		}
		if(Ls[i] == -1){
			bans[i] = 1;
			continue;
		}
		Rs[i] = -1;
		for(int j = lens[i] - 1; j >= 0; j--){
			if(s[i][0][j] != s[i][1][j]){
				Rs[i] = j;
				break;
			}
		}
		int tmp0 = 0,tmp1 = 0,tmp2 = 0,tmp3 = 0;
		for(int j = Ls[i]; j <= Rs[i]; j++){
			tmp0 = (tmp0 * base + (int)s[i][0][j]) % MOD1;
			tmp1 = (tmp1 * base + (int)s[i][0][j]) % MOD2;
			tmp2 = (tmp2 * base + (int)s[i][1][j]) % MOD1;
			tmp3 = (tmp3 * base + (int)s[i][1][j]) % MOD2;
		}
		int tmp4 = Rs[i] - Ls[i] + 1;
		vector<int>vcc;
		vcc.push_back(tmp0),vcc.push_back(tmp1),vcc.push_back(tmp2),vcc.push_back(tmp3),vcc.push_back(tmp4);
		if(!mp[vcc]) mp[vcc] = ++tott;
		oo[mp[vcc]].push_back(i);
	}
	for(int i = 1; i <= q; i++){
		cin>>t[i][0]>>t[i][1];
		ans[i] = 0;
		if((int)t[i][0].size() != (int)t[i][1].size()){
			bant[i] = 1;
			continue;
		}
		lent[i] = (int)t[i][0].size();
		Lt[i] = -1;
		for(int j = 0; j < lent[i]; j++){
			if(t[i][0][j] != t[i][1][j]){
				Lt[i] = j;
				break;
			}
		}
		Rt[i] = -1;
		for(int j = lent[i] - 1; j >= 0; j--){
			if(t[i][0][j] != t[i][1][j]){
				Rt[i] = j;
				break;
			}
		}
		int tmp0 = 0,tmp1 = 0,tmp2 = 0,tmp3 = 0;
		for(int j = Lt[i]; j <= Rt[i]; j++){
			tmp0 = (tmp0 * base + (int)t[i][0][j]) % MOD1;
			tmp1 = (tmp1 * base + (int)t[i][0][j]) % MOD2;
			tmp2 = (tmp2 * base + (int)t[i][1][j]) % MOD1;
			tmp3 = (tmp3 * base + (int)t[i][1][j]) % MOD2;
		}
		int tmp4 = Rt[i] - Lt[i] + 1;
		vector<int>vcc;
		vcc.push_back(tmp0),vcc.push_back(tmp1),vcc.push_back(tmp2),vcc.push_back(tmp3),vcc.push_back(tmp4);
		if(!mp[vcc]){
			bant[i] = 1;
			continue;
		}
		pp[mp[vcc]].push_back(i);
	}
	for(int o = 1; o <= tott; o++){
		A.init(),B.init();
		for(auto x : oo[o]){
			if(Ls[x] == 0) possa[x] = 0;
			else{
				string tt = s[x][0].substr(0,Ls[x]);
				reverse(tt.begin(),tt.end());
				possa[x] = A.ins(tt);
			}
			if(Rs[x] == lens[x] - 1) possb[x] = 0;
			else{
				string tt = s[x][0].substr(Rs[x] + 1,lens[x] - Rs[x] - 1);
				possb[x] = B.ins(tt);
			}
		}
		for(auto x : pp[o]){
			if(Lt[x] == 0) posta[x] = 0;
			else{
				string tt = t[x][0].substr(0,Lt[x]);
				reverse(tt.begin(),tt.end());
				posta[x] = A.ins(tt);
			}
			if(Rt[x] == lent[x] - 1) postb[x] = 0;
			else{
				string tt = t[x][0].substr(Rt[x] + 1,lent[x] - Rt[x] - 1);
				postb[x] = B.ins(tt);
			}
		}
		A.dfs(0),B.dfs(0);
		for(int i = 1; i <= A.timer + 1; i++) vc[i].clear();
		SZ = B.timer;
		for(auto x : oo[o]){
			int xl = A.dfn[possa[x]],xr = A.dfn[possa[x]] + A.sz[possa[x]] - 1;
			int yl = B.dfn[possb[x]],yr = B.dfn[possb[x]] + B.sz[possb[x]] - 1;
			vc[xl].push_back((node){yl,yr,1});
			vc[xr + 1].push_back((node){yl,yr,-1});
		}
		for(auto x : pp[o]){
			int xx = A.dfn[posta[x]],yy = B.dfn[postb[x]];
			vc[xx].push_back((node){yy,x,0});
		}
		for(int i = 1; i <= A.timer + 1; i++){
			for(auto uu : vc[i]){
				if(uu.v){
					upd(uu.l,uu.v),upd(uu.r + 1,-uu.v);
				}
				else{
					ans[uu.r] = psq(uu.l);
				}
			}
		}
	}
	for(int i = 1; i <= q; i++) printf("%lld\n",ans[i]);
	return 0;
}
