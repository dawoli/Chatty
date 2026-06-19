#include<bits/stdc++.h>
using namespace std;
int a[10];
string b;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(int i = 0;b[i];i++){
		if(b[i]>='0' && b[i]<='9') {
			a[(b[i]-48)]++;
		}
	}
//	for(int i = 0;i<10;i++) cout<<a[i]<<" ";
	int n=0;
	for(int i = 9;i>=1;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
			n=1;
		}
	}
	while(a[0] && n==1) {
		cout<<0;
		a[0]--;
	}
	return 0;
}
