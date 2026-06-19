#include<bits/stdc++.h>
using namespace std;
map<string,bool> mp;
signed main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	int cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(!mp[s]){
			cnt++;
		}
		mp[s]=true;
	} 
	if(cnt>52){
		cnt=52;
	}
	cout<<52-cnt;
	return 0;
}
