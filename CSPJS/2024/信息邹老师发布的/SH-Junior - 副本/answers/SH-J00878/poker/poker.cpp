#include <bits/stdc++.h>
using namespace std;

int colour (char x){
	if (x=='D') return 0;
	if (x=='C') return 1;
	if (x=='H') return 2;
	if (x=='S') return 3;
}

int num (char x) {
	if (x=='A') return 1;
	if (x=='T') return 10;
	if (x=='J') return 11;
	if (x=='Q') return 12;
	if (x=='K') return 13;
	return x-'0';
}

int main () {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int pork[5][15]={},A=0;
	int n;
	cin>>n;
	string a;
	for(int i=0;i<n;i++){
		cin>>a;
		if(pork[colour(a[0])][num(a[1])]==0){
			pork[colour(a[0])][num(a[1])]=1;
			A++;
		}
	}
	cout<<52-A<<endl;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
