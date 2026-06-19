#include<bits/stdc++.h>
using namespace std;
int vis[105];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<s.size();i++)
		if(s[i]<='9'&&s[i]>='0')
			vis[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(vis[i]>0){
			cout<<i;
			vis[i]--;
		}
	}
	return 0;
} 
