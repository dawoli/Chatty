#include<bits/stdc++.h>
using namespace std;
int phi[1000010];
int n,qq;
struct Node{
	string a,b;
};
vector<Node> a;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>qq;
	for(int i=1;i<=n;i++){
		string p,q;
		cin>>p>>q;
		a.push_back({p,q});
	}
	for(int i=1;i<=qq;i++){
		string p,q;
		cin>>p>>q;
		int ans=0;
		for(auto j:a){
			string s=j.a+"#"+p;
			phi[0]=0;
			for(int k=1;k<s.length();k++){
				int o=phi[k-1];
				while(o>0 && s[k]!=s[o]) o=phi[o-1];
				if(s[k]==s[o]) o++;
				phi[k]=o;
			}
			int len=j.a.length();
			for(int k=0;k<p.length();k++){
				if(phi[k+len+1]==len){
					if(p.substr(0,k-len+1)!=q.substr(0,k-len+1)) continue;
					if(q.substr(k-len+1,len)!=j.b) continue;
					if(p.substr(k+1)!=q.substr(k+1)) continue;
					ans++;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
