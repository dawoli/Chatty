#include<bits/stdc++.h>

using namespace std;

const unsigned long long BASE = 1145141;
int n,q,l,r,lu,lv,lc[200050],rc[200050],cha[200050];
unsigned long long p[200050],hs[200050];
string s[200050][5],u,v;
unordered_map<string,string> mp;
unordered_map<string,int> cnt;
bool ok(){
	for(int i = 1;i <= n;++i){
		for(int j = 0;j < s[i][1].size();++j){
			if(s[i][1][j] != 'a' && s[i][1][j]!='b') return false;
		}
		for(int j = 0;j < s[i][2].size();++j){
			if(s[i][2][j] != 'a' && s[i][2][j]!='b') return false;
		}
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;++i) cin>>s[i][1]>>s[i][2];
	if(ok()){
		for(int i = 1;i <= n;++i){
			for(int j = 0;j < s[i][1].size();++j){
				if(s[i][1][j] == 'b'){
					lc[i] = j;
					rc[i] = s[i][1].size()-j-1;
				}
				if(s[i][2][j] == 'b') cha[i] = j;
			}
			cha[i]-=lc[i];
		}
		while(q--){
			cin>>u>>v;
			if(u.size()!=v.size()){
				cout<<0<<endl;
				continue;
			}
			int ln,rn,chn;
			for(int i = 0;i < u.size();++i){
				if(u[i] == 'b') ln = i,rn = u.size()-i-1;
				if(v[i] == 'b') chn = i;
			}
			chn-=ln;
			int ans = 0;
			for(int i = 1;i <= n;++i){
				if(cha[i] == chn && lc[i] >= ln && rc[i] >= rn) ++ans;
			}
			cout<<ans<<endl;
		}
		return 0;
	} 
	for(int i = 1;i <= n;++i){
		s[i][1] = " "+s[i][1];
		s[i][2] = " "+s[i][2];
		mp[s[i][1]] = s[i][2];
		cnt[s[i][1]]++;
	}
	while(q--){
		cin>>u>>v;
		lu = u.size(),lv = v.size();
		u = " "+u,v = " "+v;
		if(lu != lv){
			cout<<0<<endl;
			continue;
		}
		for(int i = 1;i <= lu;++i){
			if(u[i]!=v[i]){
				l = i;
				break;
			}
		}
		for(int i = lu;i >= 1;--i){
			if(u[i]!=v[i]){
				r = i;
				break;
			}
		}
		int ans = 0;
		for(int i = 1;i <= l;++i){
			for(int j = r;j <= lu;++j){
				string lin = " ",to = " ";
				for(int k = i;k <= j;++k){
					lin+=u[k];
					to+=v[k];
				}
				if(mp[lin] == to) ans+=cnt[lin];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
