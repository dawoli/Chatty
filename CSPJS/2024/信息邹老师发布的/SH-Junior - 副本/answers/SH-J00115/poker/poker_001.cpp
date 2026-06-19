#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans=52;
string s;
map<string,bool>mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>s;
		if(mp.count(s)==0){
			ans--;
			mp[s]=true;
		}
	}cout<<ans;
	return 0;
}
