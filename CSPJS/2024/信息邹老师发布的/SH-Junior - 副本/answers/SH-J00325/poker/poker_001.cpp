#include <bits/stdc++.h>
using namespace std;
string c[100001],p;
int n,s,b,cnt=0;
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++) {
		b=1;
		cin>>p;
		for (int j=0;j<i;j++) {
			if (c[j]==p) b=0;
		}
		if (b!=0) {c[i]=p;cnt++;}
	}
	cout<<52-cnt;
	return 0;
} 
