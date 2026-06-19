#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+10;

int T,n;
int f[20]={6,2,5,5,4,5,6,3,7,6};

string calc(int num) {
	string ljy="";
	if(num==1) {
		ljy="-1";
		return ljy;
	}
	if(num==2) {
		ljy="1";
		return ljy;
	}
	if(num==3) {
		ljy="7";
		return ljy;
	}
	if(num==10) {
		ljy="22";
		return ljy;
	}
	if(num==4) {
		ljy="4";
		return ljy;
	}
	if(num>=7 && num%7==0) {
		for(int i=1;i<=num/7;i++) {
			ljy=ljy+"8";
		}
		return ljy;
	}
	if(num>=8 && num%7==1) {
		ljy="10";
		for(int i=1;i<=(num-8)/7;i++) {
			ljy=ljy+"8";
		}
		return ljy;
	}
	if(num>=9 && num%7==2) {
		ljy="1";
		for(int i=1;i<=(num-2)/7;i++) {
			ljy=ljy+"8"; 
		}
		return ljy;
	}
	if(num>=17 && num%7==3) {
		ljy="200";
		for(int i=1;i<=(num-17)/7;i++) {
			ljy=ljy+"8"; 
		}
		return ljy;
	}
	if(num>=11 && num%7==4) {
		ljy="20";
		for(int i=1;i<=(num-11)/7;i++) {
			ljy=ljy+"8";
		}
		return ljy;
	}
	if(num>=5 && num%7==5) {
		ljy="2";
		for(int i=1;i<=(num-5)/7;i++) {
			ljy=ljy+"8";
		}
		return ljy;
	}
	if(num>=6 && num%7==6) {
		ljy="6";
		for(int i=1;i<=(num-6)/7;i++) {
			ljy=ljy+"8";
		}
		return ljy;
	}
}

int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		cout<<calc(n)<<endl;
	}
	return 0;
}
