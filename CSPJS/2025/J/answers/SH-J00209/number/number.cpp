#include<bits/stdc++.h>
//inclue<bits/extc++.h>
using namespace std;
string s;
long long k[2009],flag;
void solve(){
	cin>>s;
	for(int i=0;i<s.size();i++) if('0'<=s[i]&&s[i]<='9') k[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		if(k[i]){
			for(int j=1;j<=k[i];j++) cout<<i;
			flag=1;
		}
	}
	return ;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long T=1;//cin>>T;
	while(T--) solve();
}
//subscribe tasho11y in bilibili(in luogu)!!! 
//S rp++
//AK at 10:36 

