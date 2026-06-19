#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q;
string s[maxn][5];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(q--){
		int ans=0;
		string x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			int id=0;
			while(true){
				id=x.find(s[i][1],id);
				if(id==x.npos||id==-1) break;
				string tmp=x;
				tmp.replace(id,s[i][1].size(),s[i][2]);
				if(tmp==y) ans++;
				id++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

