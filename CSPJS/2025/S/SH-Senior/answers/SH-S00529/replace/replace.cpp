#include<bits/stdc++.h>
using namespace std;
int n,q;
unordered_map<string,string>mp;
unordered_map<string,bool>vis;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		mp[a]=b;
	}
	while(q--){
		cin>>a>>b;
		int lena=a.length(),lenb=b.length();
		if(lena!=lenb){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		vis.clear();
		for(int i=0;i<lena;i++){
			for(int j=i;j<lena;j++){
				if(!vis[a.substr(i,j-i+1)]&&a.substr(0,i)+mp[a.substr(i,j-i+1)]+a.substr(j+1,lena-j)==b){
					ans++,vis[a.substr(i,j-i+1)]=1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
