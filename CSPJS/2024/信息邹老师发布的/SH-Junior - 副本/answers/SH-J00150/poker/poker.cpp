#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
char t[120];
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n*2;i+=2) {
		cin>>t[i]>>t[i+1];
		ans--;
		for(int j=0;j<i;j+=2) {
			if(t[i]==t[j]&&t[i+1]==t[j+1]) {
				ans++;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
} 
