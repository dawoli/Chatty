#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+1;
int n,q;
string vc1[maxn],vc2[maxn];
bool vis[maxn];
ll dfs(string sr1,string sr2){
	if(sr1==sr2) return 1;
	ll ans=0;
	string s1;
	s1=sr1;
	
	for(int i=0;i<n;i++){
		if(vc1[i]==s1){
			ans+=dfs(vc2[i],sr2);
			continue;
		}
		for(int sc=0;sc+vc1[i].size()<s1.size();sc++){
			bool ok=1;
			for(int t=0;t<vc1[i].size()&&ok;t++){
				if(sr1[sc+t]!=vc1[i][t]){
					ok=0;
				}
			}
			if(ok){
				for(int t=0;t<vc1[i].size();t++){
					s1[sc+t]=vc2[i][t];
				}
				ans+=dfs(s1,sr2);
				s1=sr1;
			}
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>vc1[i]>>vc2[i];
	}
	
	while(q--){
		string str1,str2;
		cin>>str1>>str2;
		cout<<dfs(str1,str2)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
