#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	while(q--){
		ans=0;
		string a,b;
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			for(int j=i+1;j<=a.size();j++){
				string x="",y="",z="";
				for(int k=0;k<i;k++) x+=a[k];
				for(int k=i;k<j;k++) y+=a[k];
				for(int k=j;k<a.size();k++) z+=a[k];
//				cout<<x<<" "<<y<<" "<<z<<"\n";
				if(mp[y]=="") continue;
				
				string bb=x+mp[y]+z;
				if(bb==b){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
