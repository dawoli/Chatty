#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010];
map<string,string>mp;
set<string>st;
map<string,int>G;
long long bfs(string sx,string ex) {
	queue<string>q;
	q.push(sx);
	long long ans=0;
	while(!q.empty()) {
		string pos=q.front();
		if(pos==ex){
			ans++;
		} 
		q.pop();
		for(int i=0; i<pos.size(); i++) {
			for(int j=1; j<=n; j++) {
				bool flag=true;
				for(int k=i;k<i+(int)s[j].size();k++){
					if(k>=pos.size()){
						flag=false;
						break;
					}
					if(pos[i]!=s[j][k-i]){
						flag=false;
						break;
					}
				}
				if(flag==false)continue;
				string nxt;
				for(int k=0;k<i;k++){
					nxt[k]=pos[k];
				}
				nxt+=mp[s[j]];
				for(int k=i+s[j].size();k<pos.size();k++){
					nxt+=pos[k];
				}
				if(st.find(nxt)==st.end()){
					st.insert(nxt);
					//G[nxt]=1;
				}
				q.push(nxt);
			}
		}
	}
	return ans;
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++) {
		string a,b;
		cin>>a>>b;
		s[i]=a;
		mp[a]=b;
	}
	while(q--) {
		st.clear();
		string t1,t2;
		cin>>t1>>t2;
		printf("%lld\n",bfs(t1,t2));
	}
	return 0;
}
