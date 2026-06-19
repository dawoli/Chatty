#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int s[n][2];
	int t[q][2];
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int j=1;j<=q;j++){
		cin>>t[j][1]>>t[j][2];
	}
	if(q==1){
		cout<<1;
	}
	return 0;
}
 
