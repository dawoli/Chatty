#include<bits/stdc++.h>
using namespace std;
int n,m,sc,li=1,hang,lie;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>sc;
	int k=n*m-1;
	while(k--){
		int hi;
		cin>>hi;
		if(sc<hi) li++;
	}
	if(li%n==0){
		lie=li/n;
	}
	else{
		lie=li/n+1;
	}
	if(lie%2==1){
		hang=li%n;
		if(li%n==0) hang=n;
	}
	else{
		hang=n-li%n+1;
	}
	cout<<lie<<' '<<hang;
	return 0;
}
