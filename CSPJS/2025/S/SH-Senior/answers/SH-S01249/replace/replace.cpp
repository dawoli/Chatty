#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string a,b;
}s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	while(q--){
		int ans=0;
		string x,y;
		cin>>x>>y;
		cout<<ans<<endl;
	}
	return 0;
}
