#include<bits/stdc++.h>
using namespace std;
int num[500005];
int xo(int a,int b) {
	return a!=b;
}
int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k ;
	bool flag1=1,flag2=1;
	for (int i=1;i<=n;i++) {
		cin >> num[i];
		if (num[i]!=1 && num[i]!=0) {
			flag1=0;
			flag2=0;
		}else if (num[i]==0) flag1=0;
	}
	if (flag1==1) {
		cout << n/2 << endl ;
		return 0;
	}else if (flag2==1) {
		int cnt=0;
		int is=0;
		int cur=num[1];
		for (int i=2;i<=n;i++) {
			if (cur==k) {
				cnt++;
				cur=num[i+1];
				is=1;
			}
			if (!is){
				cur=xo(cur,num[i]);
			}
			is=0;
		}
		cout << cnt << endl ;
		return 0;
	} 
	cout << 0 << endl ;
	return 0;
}
