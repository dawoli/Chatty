#include <iostream>
#include <cstdio>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N],t[N];
int st[N];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s[i]>>t[i];
		for(int j=0;j<s[i].size();j++)if(s[i][j]!=t[i][j]) {
			st[i]=j;
			break;
		}
	}
	for(string a,b;q--;) {
		cin>>a>>b;
		int ans=0;
		for(int i=0;i<a.size();i++)if(a[i]!=b[i]) {
			for(int k=1;k<=n;k++) {
				bool ok=true;
				int _i=i;
				for(int j=st[k];j<s[k].size();j++,i++) {
					if(i>=a.size()) {
						ok=false;
						break;
					} else if(s[k][j]!=a[i] or t[k][j]!=b[i]) {
						ok=false;
						break;
					}
				}
				for(;i<a.size();i++)if(a[i]!=b[i]) {
					ok=false;
					break;
				}
				i=_i;
				ans+=ok;
			}
			break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
