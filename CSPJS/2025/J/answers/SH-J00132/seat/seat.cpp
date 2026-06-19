#include<bits/stdc++.h>
using namespace std;
int n,m;
int sc;
int x,y;
int pos;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	sc=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--){
		if(a[i]==sc) pos=n*m-i+1;
	}
	x=(pos-1)/n+1;
	y=(pos-1)%n+1;
	if(x%2==0) y=n-(y-1)%n;
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
		
	return 0;
}
