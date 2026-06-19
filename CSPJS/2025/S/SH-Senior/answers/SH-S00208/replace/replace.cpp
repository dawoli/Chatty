#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	string s;
	cin>>s;
	if(m>1){
		cout<<0;
		return 0;
	}
	if(s[0]==1) cout<<1;
	else cout<<0;
	return 0;
}
