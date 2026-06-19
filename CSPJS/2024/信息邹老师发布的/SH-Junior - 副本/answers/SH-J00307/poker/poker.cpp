#include<bits/stdc++.h>
using namespace std;
#define int long long
set<string>s;
int n;
signed main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<51;
		return 0;
	}
	for(int i=1;i<=n;i++){
		string tmp;
		cin>>tmp;
		s.insert(tmp);
	}
	cout<<52-s.size();
	return 0;
}

