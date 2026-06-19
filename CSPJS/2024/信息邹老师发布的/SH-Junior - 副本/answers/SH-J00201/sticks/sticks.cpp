#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T,n,back[7]={6,2,5,4,6,3,7},ys[7]={0,1,2,4,6,7,8},l[10],hd[10];
string nm[10];

int pos(int i,int b) {
	return (i-back[b]+14)%7;
}

int main() {
	//可用的数字：1（2根），7（3根），4（4根），2（5根），0/6（6根），8（7根）。 
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    /*cin >> n;
    while (n>0) {
    	if (n%7==0) {
    		n-=7;
    		cout << 8;
		}
		if (n<42&&n%6==0) {
			n-=6;
			cout << 0;
		}
		if ()
	}*/
	cin >> T;
	while (T-->0) {
		cin >> n;
		if (n==1) {
			cout << -1 << endl;
			continue;
		}
		if (n==2) {
			cout << 1 << endl;
			continue;
		}
		if (n==3) {
			cout << 7 << endl;
			continue;
		}
		if (n==4) {
			cout << 4 << endl;
			continue;
		}
		if (n==5) {
			cout << 2 << endl;
			continue;
		}
		if (n==6) {
			cout << 6 << endl;
			continue;
		}
		if (n==7) {
			cout << 8 << endl;
			continue;
		}
		if (n==8) {
			cout << "01" << endl;
			continue;
		}
		nm[2]="1";
		nm[3]="7";
		nm[4]="4";
		nm[5]="2";
		nm[6]="0";
		nm[0]="8";
		nm[1]="01";
		l[2]=1;
		l[3]=1;
		l[4]=1;
		l[5]=1;
		l[6]=1;
		l[0]=1;
		l[1]=2;
		/*hd[2]=1;
		hd[3]=7;
		hd[4]=4;
		hd[5]=2;
		hd[6]=0;
		hd[0]=8;
		hd[1]=0;*/
		for (int i=9;i<n;i++) {
			int ad=0;
			if (l[pos(i,6)]<l[pos(i,0)]/*||(l[pos(i,k)]==l[pos(i,ad)]&&hd[pos(i,k)]<hd[pos(i,ad)])*/) {
				ad=6;
			}
			l[i%7]=l[pos(i,ad)]+1;
			nm[i%7]=(char)('0'+ys[ad])+nm[pos(i,ad)];
		}
		int ad=1;
		for (int k=1;k<7;k++) {
			if (l[pos(n,k)]<l[pos(n,ad)]/*||(l[pos(i,k)]==l[pos(i,ad)]&&hd[pos(i,k)]<hd[pos(i,ad)])*/) {
				ad=k;
			}
		}
		cout << (char)('0'+ys[ad]) << nm[pos(n,ad)] << endl;
	}
}
