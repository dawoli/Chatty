#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
set<string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string t;
		cin>>t;
		s.insert(t);
	}
	for(auto x:s){
		cnt++;
	}
	cout<<52-cnt<<endl;
	return 0;
}
