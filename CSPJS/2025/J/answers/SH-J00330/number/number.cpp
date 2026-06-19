#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl "\n"
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	s=" "+s;
	for(int i=1;i<s.size();i++){
		char c=s[i];
		if(c>='0'&&c<='9')a[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
} 
