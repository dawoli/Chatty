#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed tr[30][5100000][2];
signed fail[5100000][2];
vector<signed> ed[5100000][2]; signed tp[5100000][2];
signed epos[300000][2];
int nd[2];
vector<int> yoimiya[300000][2];
int len[300000];
vector<signed> ftr[5100000][2];
void dfs(int pos,int id,int top){
	if(ed[pos][id].size()){
		yoimiya[top][id].push_back(ed[pos][id][0]);
		for(int i=0;i+1<ed[pos][id].size();i++){
			yoimiya[ed[pos][id][i]][id].push_back(ed[pos][id][i+1]);
		}
		top = ed[pos][id][ed[pos][id].size() - 1];
	}
	tp[pos][id] = top;
	for(int i=0;i<ftr[pos][id].size();i++){
		dfs(ftr[pos][id][i], id, top);
	}
} 
signed ft[30][300000][2],cntt;
void dfs2(int pos,int fa){
	ft[0][pos][0] = fa; 
	for(int i=1;i<=18;i++) ft[i][pos][0] = ft[i-1][ft[i-1][pos][0]][0];
	for(int i=0;i<yoimiya[pos][0].size();i++){
		dfs2(yoimiya[pos][0][i], pos);
	}
}
int l[300000], r[300000];
void dfs3(int pos,int fa){
	ft[0][pos][1] = fa; l[pos] = ++cntt;
	for(int i=1;i<=18;i++) ft[i][pos][1] = ft[i-1][ft[i-1][pos][1]][1];
	for(int i=0;i<yoimiya[pos][1].size();i++){
		dfs3(yoimiya[pos][1][i], pos);
	}
	r[pos] = ++cntt;
}
vector<array<int,4> > ask[300000];
int mavuika[500000];
int n,qu;
void add(int pos,int x){
	for(int i=pos;i<=n+n+5;i+=(i&(-i))) mavuika[i] += x;
}
int sum(int pos){
	int res = 0;
	for(int i=pos;i;i-=(i&(-i))) res += mavuika[i];
	return res;
}
int ans[300000];
void dfs4(int pos){
	add(l[pos], 1); add(r[pos], -1);
	for(int i=0;i<yoimiya[pos][0].size();i++){
		dfs4(yoimiya[pos][0][i]);
	}
	for(int i=0;i<ask[pos].size();i++){
		ans[ask[pos][i][2]] += ask[pos][i][3] * (sum(l[ask[pos][i][1]]) - sum(l[ask[pos][i][0]] - 1));
	}
	add(l[pos], -1); add(r[pos], 1);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin>>n>>qu;
	for(int i=1;i<=n;i++){
		string s,t;cin>>s>>t;
		int pos= 0;
		for(int j=0;j<s.size();j++){
			if(!tr[s[j]-'a'][pos][0]) tr[s[j]-'a'][pos][0] = ++nd[0];
			pos = tr[s[j]-'a'][pos][0];
		}
		ed[pos][0].push_back(i); epos[i][0] = pos; len[i] = s.size();
		pos = 0;
		for(int j=0;j<t.size();j++){
			if(!tr[t[j]-'a'][pos][1]) tr[t[j]-'a'][pos][1] = ++nd[1];
			pos = tr[t[j]-'a'][pos][1];
		}
		ed[pos][1].push_back(i); epos[i][1] = pos;
	}
	for(int ii=0;ii<2;ii++){
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			int pos = q.front(); q.pop();
			for(int i=0;i<26;i++){
				if(!pos){
					if(tr[i][pos][ii]) q.push(tr[i][pos][ii]);
					continue;
				}
				if(tr[i][pos][ii]) fail[tr[i][pos][ii]][ii] = tr[i][fail[pos][ii]][ii], q.push(tr[i][pos][ii]);
				else tr[i][pos][ii] = tr[i][fail[pos][ii]][ii];
			}
		}
		for(int i=1;i<=nd[ii];i++) ftr[fail[i][ii]][ii].push_back(i);
	}
	dfs(0, 0, 0); dfs(0, 1, 0);dfs2(0, 0); cntt = 0;dfs3(0, 0);
	for(int i=1;i<=qu;i++){
		string s,t;cin>>s>>t;
		int l, r;
		for(int j=0;j<s.size();j++){
			if(s[j] != t[j]){
				l = j; break;
			}
		}
		for(int j=s.size()-1;j>=0;j--){
			if(s[j] != t[j]){
				r = j; break;
			}
		}
		int pos = 0, poss = 0;
		for(int j=0;j<s.size();j++){
			pos = tr[s[j]-'a'][pos][0];
			poss = tr[t[j]-'a'][poss][1];
			if(j >= r){
				int tmp = tp[pos][0], tmd = tp[poss][1], tmpp = tmp, tmdd = tmd;
				for(int k=18;k>=0;k--){
					if(len[ft[k][tmp][0]] >= j-l+1) tmp = ft[k][tmp][0];
				}
				for(int k=18;k>=0;k--){
					if(len[ft[k][tmd][1]] >= j-l+1) tmd = ft[k][tmd][1];
				}
				if(len[tmp]>=j-l+1 && len[tmd]>=j-l+1){
					if(tmp)ask[ft[0][tmp][0]].push_back({tmd, tmdd, i, -1});
					ask[tmpp].push_back({tmd, tmdd, i, 1});
				}
			}
		}
	}
	dfs4(0);
	for(int i=1;i<=qu;i++){
		cout << ans[i] << endl;
	}
	return 0;
}
