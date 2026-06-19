#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int n,q,cnt;
string s,s2;
map<string,int>mp;
string a[N];
vector<string>c[N];
void solve() {
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s>>s2;
		if(!mp[s]) mp[s]=++cnt;
		a[mp[s]]=s;
//		cout<<mp[s]<<"\n";
		c[mp[s]].push_back(s2);
	}
	while(q--) {
		cin>>s>>s2;
		string s1=s;int ans=0;
		for(int i=1; i<=cnt; i++) {
			s=s1;
			for(auto s3:c[i]) {
				bool f=0;
				int sz=s3.size();
//				cout<<a[i]<<" "<<s3<<"\n";
				for(int j=0; j+sz<=s.size(); j++) {
//					cout<<s.substr(j,sz)<<" "<<s2.substr(j,sz)<<"\n";
					if(s.substr(j,sz)!=s2.substr(j,sz)){
						if(a[i]==s.substr(j,sz) && s3==s2.substr(j,sz)){
							for(int d=j;d<=j+sz-1;d++)
								s[d]=s2[d];
							f=1;break;
						}
					}
					if(f) break;
				}
				if(s==s2){
//					cout<<s<<" "<<s2<<"\n"; 
					ans++;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	ios::sync_with_stdio;
//	cin.tie(0);cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}

