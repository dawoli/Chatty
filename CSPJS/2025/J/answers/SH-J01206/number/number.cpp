#include<bits/stdc++.h>
using namespace std;
string s,t;
int n,cnt,a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n = s.size();
	for (int i=0;i<n;i++){
		if (s[i] >= '0' and s[i] <= '9'){
			cnt++;
			a[cnt] = s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt);
	for (int i=cnt;i>=1;i--) cout << a[i];
	return 0;
}
