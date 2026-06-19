#include<bits/stdc++.h>
using namespace std;
int a[100015],o[225][225];
int d,m=1,n=0,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r;
	cin>>c>>r;
	int s=c*r;
	for (int i=0;i<s;i++){
		cin>>a[i];
	}
	int b=a[0];
	sort (a,a+s);
	for (int i=1;i<=s;i++){
		if(a[i]==b) d=s-i;
	}
	for (int i=1;i<=d;i++){
		if (m%2!=0) {
			n++;
			if (n==r+1) m++,n--;
		}
		else {
			n--;
			if (n==0) m++,n++;
		}
	}
	cout<<m<<' '<<n;
	return 0;
}
