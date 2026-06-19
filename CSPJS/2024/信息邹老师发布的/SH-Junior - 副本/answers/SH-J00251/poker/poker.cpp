#include<bits/stdc++.h>
using namespace std;
int n;
set<string>S;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		S.insert(s);
	}
	cout<<52-S.size();
	return 0;
}
