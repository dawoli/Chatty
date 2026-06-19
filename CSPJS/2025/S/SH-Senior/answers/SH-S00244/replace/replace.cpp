#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define B 71
#define N 200209
#define M 5000509
int n,m,typ,len,K[N],ans[N],num[M],cnt[M];
ull H[N],HX[M];
string S[N],s1,s2;
map<pair<ull,ull>,int> mp;
struct query{ int num,id; };
struct Trie{
	int V;
	struct node{
		int son[27];
		vector<int> num;
		vector<query> q;
		node(){
			memset(son,0,sizeof(son));
			num.clear(); q.clear();
		}
	};
	vector<node> tr;
	Trie(){
		tr.emplace_back();
		tr.emplace_back();
		tr.emplace_back();
		V = 1;
	}
	inline void ins(int idx,int pre){
		// cout<<"ID "<<idx<<"  "<<"Hash "<<pre<<endl;
		int u = 1;
		for(int i = 0;i < S[idx].size();i++){
			int c = S[idx][i] - 'a' + 1;
			if(!tr[u].son[c]){
				tr.emplace_back();
				tr[u].son[c] = ++V;
			}
			u = tr[u].son[c];
		}
		tr[u].num.emplace_back(pre);
	}
	inline int find(int l){
		int u = 1;
		for(int i = l - 1;i >= 0;i--){
			int c = s1[i] - 'a' + 1;
			if(!tr[u].son[c]) return u;
			u = tr[u].son[c];
		}
		return u;
	}
	inline void dfs(int u){
		for(int i = 0;i < tr[u].num.size();i++) cnt[tr[u].num[i]]++;
		for(int i = 0;i < tr[u].q.size();i++) ans[tr[u].q[i].id] += cnt[tr[u].q[i].num];
		for(int i = 1;i <= 26;i++)
			if(tr[u].son[i]) dfs(tr[u].son[i]);
		for(int i = 0;i < tr[u].num.size();i++) cnt[tr[u].num[i]]--;
	}
} T[N];
inline ull F1(int l,int r){
	ull h = 0;
	for(int i = l;i <= r;i++) h = h * B + (s1[i] - 'a' + 1);
	return h;
}
inline ull F2(int l,int r){
	ull h = 0;
	for(int i = l;i <= r;i++) h = h * B + (s2[i] - 'a' + 1);
	return h;
}
inline void work(){
	cin>>n>>m;
	int tmp = n;
	n = 0;
	H[++len] = 0;
	for(int i = 1;i <= tmp;i++){
		cin>>s1>>s2;
		if(s1 == s2) continue;
		int l = 1e9,r = 0;
		for(int j = 0;j < s1.size();j++)
			if(s1[j] != s2[j]) l = min(l,j),r = max(r,j);
		int u = 0;
		ull res1 = F1(l,r),res2 = F2(l,r);
		if(!mp.count(make_pair(res1,res2)))
			mp[make_pair(res1,res2)] = ++typ;
		u = mp[make_pair(res1,res2)];
		
		ull h = 0;
		for(int j = r + 1;j < s1.size();j++){
			h = h * B + (s1[j] - 'a' + 1);
			HX[++len] = h;
		}
		n++;
		H[n] = h; S[n] = s1.substr(0,l); K[n] = u;
		reverse(S[n].begin(),S[n].end());
		// cout<<H[n]<<" "<<S[n]<<" "<<K[n]<<endl;
	}
	sort(HX + 1,HX + len + 1);
	len = unique(HX + 1,HX + len + 1) - HX - 1;
	
	for(int i = 1;i <= n;i++) T[K[i]].ins(i,lower_bound(HX + 1,HX + len + 1,H[i]) - HX);
	
	for(int i = 1;i <= m;i++){
		cin>>s1>>s2;
		int l = 1e9,r = 0;
		for(int j = 0;j < s1.size();j++)
			if(s1[j] != s2[j]) l = min(l,j),r = max(r,j);
		ull res1 = F1(l,r),res2 = F2(l,r);
		int idx = mp[make_pair(res1,res2)];
		if(!idx) continue;
		int u = T[idx].find(l);
		if(u == -1) continue;
		ull h = 0;
		T[idx].tr[u].q.emplace_back((query){1,i});
		for(int j = r + 1;j < s1.size();j++){
			h = h * B + (s1[j] - 'a' + 1);
			int tmp = lower_bound(HX + 1,HX + len + 1,h) - HX;
			if(HX[tmp] == h) T[idx].tr[u].q.emplace_back((query){tmp,i});
		}
	}
	for(int i = 1;i <= typ;i++) T[i].dfs(1);
	for(int i = 1;i <= m;i++) cout<<ans[i]<<"\n";
}
signed main(){
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	work();
}
