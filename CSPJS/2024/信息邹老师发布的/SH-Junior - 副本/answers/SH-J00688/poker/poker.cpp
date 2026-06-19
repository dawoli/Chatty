#include <bits/stdc++.h>
using namespace std;
int n,ans=52;
string s;
map <string,bool> m;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s;
		if(m[s]==0)ans--;
		m[s]=1;
	}
	cout << ans;
	return 0;
} 
