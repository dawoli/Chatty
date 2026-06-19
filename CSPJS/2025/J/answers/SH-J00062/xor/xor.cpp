#include <bits/stdc++.h>
using namespace std;
int n,k,a,s[500005],ans,t = 1,p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a;
		s[i] = a^s[i-1];
	}
	for(int i = 1;i<=n;i++){
		p = k^s[i];
		if(s[i-1]==p){
			ans++;
			t = i+1;
			continue;
		}
		else if(s[i-1]==s[i]) continue;
		for(int j = t;j<=i;j++){
			if(s[j-1]==p){
				ans++;
				t = i+1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
