#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> m;
string s[200009];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string b;
		cin>>s[i]>>b;
		m[s[i]]=b;
	}
	for(int x=1;x<=q;x++){
		int ans;
		string t,tt;
		cin>>t>>tt;
		for(int i=0;i<t.size();i++){
			for(int j=1;j<=n;j++)
				if(t.find(s[j])==tt.find(m[s[j]])&&t.find(s[j])!=t.size()){
					t.erase(t.find(s[j]),t.find(s[j])+s[j].size());
					tt.erase(tt.find(m[s[j]]),tt.find(m[s[j]])+m[s[j]].size());
					if(t==tt) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
