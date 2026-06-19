#include<bits/stdc++.h>
using namespace std;
string s[200009][2],t[200009][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		int ans=0;
		for(int j=1;j<=n;j++){
			if(t[i][0].find(s[j][0])<t[i][0].size()){
				int y=t[i][0].find(s[j][0]);
				string x=t[i][0].substr(0,y);
				string yy=t[i][0].substr(y,s[j][0].size());
				string z=t[i][0].substr(y+s[j][0].size(),t[i][0].size()-(y+s[j][0].size()));
				yy=s[j][1];
				if(x+yy+z==t[i][1]) ans++;
			}
		}	
		cout<<ans<<endl;
	}
	return 0;
} 
