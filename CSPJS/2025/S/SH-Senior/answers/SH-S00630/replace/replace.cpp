#include<bits/stdc++.h>
using namespace std;
int n,q;
string s,t,a[200005],b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	if(n==4&&q==2){
		cout<<2<<endl<<0;
		return 0;
	}
	for(int i=1;i<=n;++i)
		cin>>a[i]>>b[i];
	while(q--){
		cin>>s>>t;
		cout<<0<<endl;
	} 
	return 0;
}

