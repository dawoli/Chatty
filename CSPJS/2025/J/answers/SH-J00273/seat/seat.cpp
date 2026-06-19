#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int pos=1;
int x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) pos++;
	}
	x=pos/n;
	pos%=n;
	if(pos==0) {
		if(x%2) y=n;
		else y=1;
		cout<<x<<" "<<y;
	}
	else{
		if(x%2) y=n-pos+1;
		else y=pos;
		cout<<x+1<<" "<<y;
	}
	return 0;
} 
