#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s[60];
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>s[i];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(s[i]==s[j] and i!=j) {
				ans++;
			}
		}
	}
	ans/=2;
	cout<<52-n+ans<<endl;
	return 0;
}
