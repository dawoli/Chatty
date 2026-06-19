#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	const int N=1e6+5;
	int a[N], z=0;
	cin >> s;
	for(int i=0; i<=s.length(); i++){
		if('0'<=s[i]&&'9'>=s[i]){
			a[z]=s[i]-'0';z++;
		}
	}
	sort(a,a+z);
	while(z--){
		cout<<a[z];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
