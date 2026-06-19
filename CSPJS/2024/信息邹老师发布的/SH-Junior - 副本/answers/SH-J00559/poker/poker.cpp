#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string s,a[100];
	for(int i=0;i<100;i++)
		a[i]="?";
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>s;
		for(int j=1;j<=n;j++) {
			if(s==a[j]) s="!";
		}
		a[i]=s;
	}
	int cnt=0;
	for(int i=1;a[i]!="?";i++)
		if(a[i]!="!")
			cnt++;
	cout<<52-cnt; 
	return 0;
}
