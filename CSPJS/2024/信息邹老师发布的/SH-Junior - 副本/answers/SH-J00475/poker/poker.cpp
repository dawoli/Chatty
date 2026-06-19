#include<bits/stdc++.h>
using namespace std;
int n;
string s;
map<string,int>mp;
int main(){
//	freopen("D:\\9_CSP-J\\CSP-J\\poker\\poker3.in","r",stdin);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>s;
		mp[s]++;
	}
	int len=mp.size();
	cout<<(52-len);
	return 0;
}
