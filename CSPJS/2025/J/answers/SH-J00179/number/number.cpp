#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int ans[15],k;
int main() {
	//freopen ("number.in ","r",stdin);
	//freopen ("number.out ","w",stdout);
	
	for (int i=1;i<=1000005;i++) {
		cin>>s[i];
		if (s[i]=='0') {
			ans[0]++;
		}
		if (s[i]=='1') {
			ans[1]++;	
			}
		if (s[i]=='2') {
			ans[2]++;	
		}
		if (s[i]=='3') {
			ans[3]++;	
			}
		if (s[i]=='4') {
			ans[4]++;	
		}
		if (s[i]=='5') {
			ans[5]++;	
		}
		if (s[i]=='6') {
			ans[6]++;	
		}
		if (s[i]=='7') {
			ans[7]++;	
		}
		if (s[i]=='8') {
			ans[8]++;	
			}
		if (s[i]=='9') {
			ans[9]++;	
		}
		}
	for (int i=9;i>=0;i--) {
		
		for (int j=1;j<=ans[i];j++) {
			cout<<i;
		}
	}
	return 0;
}
