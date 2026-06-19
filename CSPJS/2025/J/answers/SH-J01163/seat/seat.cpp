#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,m,a1=1,b=1;
	cin>>x>>y;
	cin>>m;
	for(int i=0;i<x*y-1;i++){
		cin>>a[i];
	}
	sort(a,a+x*y);
	for(int i=1;i<=x*y-1;i++){
		if(a[i]>m&&a1!=y&&b%2==1) a1++;
		else if(a[i]>m&&a1!=1&&b%2==0) a1--;
		else if(a[i]>m&&a1==y&&b%2==1) b++;
		else if(a[i]>m&&a1==1&&b%2==0) b++;
	}
	cout<<b<<" "<<a1;
	return 0;
}
	
