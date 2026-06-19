#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[109];

bool cmp (int a, int b) {
	return a>b;
}

int main ()
{
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	
	cin>>n>>m;
	
	int scr=0;
	
	for (int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	
	scr=a[1];
	
	sort(a+1,a+n*m+1,cmp);
	
	int plc=0;
	
	for (int i=1; i<=n*m; i++) {
		if (a[i]==scr) {
			plc=i;
			break;
		}
	}
	
	int r,c;
	
	if (plc%n==0) {
		c=plc/n;
	}
	
	else {
		c=plc/n+1;
	}

	if (c%2==0) {
		r=n-(plc-n*(c-1))+1;
	}
	
	else {
		r=plc-n*(c-1);
	}
	
	cout<<c<<" "<<r;
	
	return 0;
}
