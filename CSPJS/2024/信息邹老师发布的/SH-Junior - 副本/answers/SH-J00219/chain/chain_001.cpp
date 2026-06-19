#include<bits/stdc++.h>
using namespace std;
#define N 200009
int n,k,m,X,R,ans[N],sum[2][N];
bool f[2][2009][2009];
vector<int> to[N],w[N],s[N];
map<int,int> mp;
struct query{ int c,id; };
vector<query> q[109];
void upd(int &x){
	if(!mp.count(x)) mp[x] = ++X;
	x = mp[x];
}
void input(){
	scanf("%d %d %d",&n,&k,&m); X = 0; R = 0; mp.clear();
	for(int i = 1;i <= n;i++) s[i].clear();
	for(int i = 1;i <= n;i++){
		int len,x;
		scanf("%d",&len);
		for(int j = 0;j < len;j++){
			scanf("%d",&x); upd(x);
			s[i].push_back(x);
		}
	}
	for(int i = 1;i <= 100;i++) q[i].clear();
	for(int i = 1;i <= m;i++){
		int r,c;
		scanf("%d %d",&r,&c); upd(c);
		R = max(R,r);
		q[r].push_back((query){c,i});
	} 
}
void build(){
	for(int i = 1;i <= X;i++) to[i].clear(),w[i].clear();
	for(int i = 1;i <= n;i++)
		for(int j = 0;j < s[i].size();j++)
			for(int l = max(j - k + 1,0);l < j;l++)
				to[s[i][l]].push_back(s[i][j]),w[s[i][l]].push_back(i);
}
void solve(){
	memset(f,0,sizeof(f)); memset(sum,0,sizeof(sum));
	memset(ans,0,sizeof(ans)); 
	f[0][mp[1]][0] = 1; sum[0][mp[1]] = 1;
	for(int r = 1;r <= R;r++){
		int now = (r & 1),lst = ((r & 1) ^ 1);
		memset(f[now],0,sizeof(f[now])); memset(sum[now],0,sizeof(sum[now]));
		for(int u = 1;u <= X;u++){
			if(sum[lst][u] == 0) continue;
			for(int i = 0;i < to[u].size();i++){
				int v = to[u][i],c = w[u][i];
				if(sum[lst][u] - f[lst][u][c] >= 1){
					if(f[now][v][c] == 0) sum[now][v]++;
					f[now][v][c] = 1;
				}
			}
		}
		for(int i = 0;i < q[r].size();i++)
			ans[q[r][i].id] = (sum[now][q[r][i].c] >= 1);
	}
	for(int i = 1;i <= m;i++) printf("%d\n",ans[i]);
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		input(); build(); solve();
	}
	return 0;
}
