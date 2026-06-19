#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ans=52;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		bool flag=1;
		for(int j=1;j<i;j++)
			if(s[j]==s[i]) flag=0;
		if(flag) ans--;
	} 
	cout<<ans<<'\n';
	return 0;
}
