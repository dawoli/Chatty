#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
string s;
set<string> cnt;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		cnt.insert(s);
	}
	ans=cnt.size();
	cout<<52-ans;
	return 0;
}
