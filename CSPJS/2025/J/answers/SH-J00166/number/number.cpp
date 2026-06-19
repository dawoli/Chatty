#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll k[19];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			k[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=k[i];j++)cout<<i;
	}
	return 0;
} 
