#include<bits/stdc++.h>
using namespace std;
string s[10005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	while(q--){
		int ans=0;
		string t1,t2;cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			for(int j=0;j+s[i][1].length()<=t1.length();j++){
				bool tag=1;
				if(t1[j]!=t2[j]){
					for(int k=0;k<(int)s[i][1].length();k++){
						if (!tag)break;
						if(t1[k+j]==s[i][1][k] && t2[k+j]==s[i][2][k]);
						else tag=0;
					}
					for(int k=j+s[i][1].length();k<(int)t1.length();k++){
						if (!tag)break;
						if(t1[k]!=t2[k])tag=0;
					}
					ans+=tag;
					break;
				}else{
					for(int k=0;k<(int)s[i][1].length();k++){
						if (!tag)break;
						if(t1[k+j]==s[i][1][k] && t2[k+j]==s[i][2][k]);
						else tag=0;
					}
					for(int k=j+s[i][1].length();k<(int)t1.length();k++){
						if (!tag)break;
						if(t1[k]!=t2[k])tag=0;
					}
					ans+=tag;
				}
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}

