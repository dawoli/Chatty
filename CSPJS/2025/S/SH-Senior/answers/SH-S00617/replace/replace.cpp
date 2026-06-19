#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(n>10000){
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
		return 0;
	}
	string s[n+1][3]={},t[q+1][3]={};
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++)cin>>t[i][1]>>t[i][2];
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(t[i][1].find(s[i][1])!=string::npos){
				int q=t[i][1].find(s[i][1]);
				t[i][1].erase(q,s[i][1].size());
				t[i][1].insert(q,s[i][2]);
				if(t[i][1]==t[i][2])ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
