#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+7;
int b[N];
int main() {
	string a;
	int k=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0; i<a.length(); i++) {
		if('0'<=a[i] && a[i]<='9') {
			b[++k] = a[i]-'0';
		}
	}
	sort(b+1,b+k+1);
	for(int i=k; i>=1; i--) {
		cout<<b[i];
	}
	return 0;
} 
