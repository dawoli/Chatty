#include <bits/stdc++.h>
using namespace std;	
const int N = 1e6 + 5;
#define int long long
int a[11],n = 1;

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	for(int i = 0;i < s.size();i++){
		if(s[i] <= '9' && s[i] >= '0') a[s[i] - '0']++;
	}
	for(int i = 9;i >= 0;i--){
		for(int j = a[i];j > 0;j--){
			cout<<i;
		} 
	}
	
	return 0;
} 
