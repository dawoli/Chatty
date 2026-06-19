#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,ans;
string s[N][3],a,b,t;
void solve(){
	ans=0;
	cin>>a>>b;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a.size();j++){
			if(a.substr(j,s[i][1].size())==s[i][1]){
				t=a.substr(0,j)+s[i][2]+a.substr(j+s[i][1].size());
				if(t==b){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		solve();
	}

	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
