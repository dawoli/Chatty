#include <bits/stdc++.h>
using namespace std;
int a[300][300];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n; cin>>n;
	int ans=52-n;
	for(int i=1;i<=n;i++){
		string s; cin>>s;
		if(a[s[0]][s[1]]) ans++;
		else a[s[0]][s[1]]=1;
	}
	cout<<ans;
	return 0;
}
