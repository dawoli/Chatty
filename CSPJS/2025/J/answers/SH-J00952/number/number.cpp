#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char a[1000005];
int num[15]={0},len;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	len = strlen(a);
	for (int i=0;i<len;i++) {
		if ('0'<=a[i] && a[i]<='9') {
			int x=a[i]-'0';
			num[x] ++;
		} else {
			continue;
		}
	}
	bool f=1;
	for (int i=9;i>=0;i--) {
		if (i==0 && f==true) {
			cout << 0;
			break;
		} else {
			for (int j=1;j<=num[i];j++) {
				cout << i;
				f=false;
			}
		}
	}
	return 0;
}
