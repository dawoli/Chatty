#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,q;
string s[N][2],t0,t1;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		int ans=0;
		cin>>t0>>t1;
		for(int i=1;i<=n;i++){
			string now="";
			for(int j=0;j<t0.size();j++){
				bool flag=0;
				for(int k=0;k<s[i][0].size();k++){
					if(t0[j+k]!=s[i][0][k]){
						flag=1;
						break;
					}
				}
				if(!flag){
					string cur=now;
					for(int k=0;k<s[i][1].size();k++){
						cur+=s[i][1][k];
					}
					for(int k=j+s[i][0].size()+1;k<=t0.size();k++){
						cur+=t0[k];
					}
					if(cur==t1){
						ans++;
					}
				}
				now+=t0[j];
			}
		}
		cout<<ans<<endl;;
	}
	
}
