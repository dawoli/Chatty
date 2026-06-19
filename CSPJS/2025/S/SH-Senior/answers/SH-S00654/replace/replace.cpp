#include<bits/stdc++.h>
using namespace std;
string s[200001][3],t[200001][3];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++)cin>>t[i][1]>>t[i][2];
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k+s[j][1].length()-1<t[i][1].length();k++){
				string temp=t[i][1];
				bool flag=1;
				for(int r=0;r<s[j][1].length();r++){
					if(temp[k+r]!=s[j][1][r]){
						flag=0;
						break;
					}
					temp[k+r]=s[j][2][r];
				}
				if(flag&&temp==t[i][2]){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

