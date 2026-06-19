#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,c=0;
	string s;
	cin>>n;
	while(n--){
		getline(cin,s);
		if(mp[s]==0)c++;
		mp[s]=1;
	}
	cout<<52-c;
	return 0;
}
