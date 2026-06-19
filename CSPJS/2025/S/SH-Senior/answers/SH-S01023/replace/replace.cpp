#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005],ss[200005];
string S[200005],SS[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
	}
	for(int i=1;i<=q;i++){
		cin>>S[i]>>SS[i]; 
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			int k=S[i].find(s[j]);
			if(k==-1){
				continue;
			}
			string x=S[i].substr(0,k);
			int kaitou=k+s[j].size();
			int jiewei=S[i].size()-s[j].size()-k;
			string z=S[i].substr(kaitou,jiewei);
			string y=x+ss[j]+z;
			if(y==SS[i]){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
