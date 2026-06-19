#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	mp['0']=6;
	mp['1']=2;
	mp['2']=5;
	mp['3']=5;
	mp['4']=4;
	mp['5']=5;
	mp['6']=6;
	mp['7']=3;
	mp['8']=7;
	mp['9']=6;
	int n,x;
	cin>>n;
	while(n--){
		bool f=false;
		cin>>x;
		if(x==1){
			cout<<"-1\n";
			continue;
		}for(int i=1;i<=2e6;i++){
			string s=to_string(i);
			long long sm=0;
			for(int j=0;j<s.size();j++)sm+=mp[s[j]];
			if(sm==x){
				f=true;
				cout<<i<<'\n';
				break;
			}
		}if(f==false)cout<<"-1\n";
	}
}
