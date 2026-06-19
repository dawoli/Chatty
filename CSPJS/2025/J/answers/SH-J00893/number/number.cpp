#include<bits/stdc++.h>
using namespace std;
string cnt[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	cin>>s;
	for(auto x:s){
		if('0'<=x&&x<='9') cnt[x-'0']+=x;
	}
	string ans;
	for(int i=9;i>=0;i--) ans+=cnt[i];
	cout<<ans;
	return 0;
}
