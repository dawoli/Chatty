#include<bits/stdc++.h>
using namespace std;
int dig(int m) {
	switch(m) {
		case 1:
			return 2;
			break;
		case 2:
			return 5;
			break;
		case 3:
			return 5;
			break;
		case 4:
			return 4;
			break;
		case 5:
			return 5;
			break;
		case 6:
			return 6;
			break;
		case 7:
			return 3;
			break;
		case 8:
			return 7;
			break;
		case 9:
			return 6;
			break;
		case 0:
			return 6;
			break;
	}
}
int num(int a) {
	int cnt=0;
	while(a!=0) {
		cnt+=dig(a%10);
		a/=10;
	}
	return cnt;
}
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++) {
		cin>>n;
		if(n==1) {
			cout<<-1<<endl;
			continue;
		}
		for(int j=1;;j++) {
			if(num(j)==n) {
				cout<<j<<endl;
				break;
			}
		}
	}
	return 0;
}
