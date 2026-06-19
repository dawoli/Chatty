#include<bits/stdc++.h>
using namespace std;
int q,n,ans=0;
string s[200005][2];
string t[2];
bool typeb=true;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(int j=0;j<s[i][0].size();j++)
			if(s[i][0][j]!='a'&&s[i][0][j]!='b')
				typeb=false;
		for(int j=0;j<s[i][1].size();j++)
			if(s[i][1][j]!='a'&&s[i][1][j]!='b')
				typeb=false;
	}
	while (q--){
		cin>>t[0]>>t[1];
		for(int j=0;j<t[0].size();j++)
			if(t[0][j]!='a'&&t[0][j]!='b')
				typeb=false;
		for(int j=0;j<t[1].size();j++)
			if(t[1][j]!='a'&&t[1][j]!='b')
				typeb=false;
		if(typeb){
			int xt1,xt2,st1,st2;
			for(int i=0;i<t[0].size();i++)
				if(t[0][i]=='b'){
					xt1=i;
					break;
				}
			for(int i=0;i<t[1].size();i++)
				if(t[1][i]=='b'){
					xt2=i;
					break;
				}
			for(int j=1;j<=n;j++){
				if(s[j][0].size()>t[0].size())
					continue;
				for(int i=0;i<s[j][0].size();i++)
					if(s[j][0][i]=='b'){
						st1=i;
						break;
					}
				for(int i=0;i<s[j][1].size();i++)
					if(s[j][1][i]=='b'){
						st2=i;
						break;
					}
				if((st2-st1==xt2-xt1)&&(xt1>=st1)){
					ans++;
				}
			}
			cout<<ans<<endl;
			return 0;
		}
		for(int i=0;i<t[0].size();i++){
			for(int j=1;j<=n;j++){
				if(t[0].size()-i<s[j][0].size()) continue;
//				cout<<j<<endl;
				string str[2]={t[0],t[1]};
//				bool same=true;
				for(int k=0;k<s[j][0].size();k++){
//					if(t[0][i+k]!=s[j][0][k]||t[1][i+k]!=s[j][1][k]){
//						same=false;
//						break;
//					}
					str[0][i+k]=s[j][1][k];
				}
				if(str[0]==str[1]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
