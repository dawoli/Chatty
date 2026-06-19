#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
#define int long long
#define N 1111111
string s;
int cnt[10];
signed main(){
	open("number");
	cin>>s;
	for(auto&i:s)if('0'<=i&&i<='9')++cnt[i-'0'];
	for(int i=9;i>=0;i--)
		while(cnt[i]--)cout<<i;
	cout<<endl;
}
