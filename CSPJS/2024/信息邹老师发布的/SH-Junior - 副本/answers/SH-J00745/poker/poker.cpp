#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;cin>>n;
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		string s;cin>>s;
		if(mp[s] == 0){
			cnt++;
			mp[s] = 1;
		}
	}
	cout<<52-cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
