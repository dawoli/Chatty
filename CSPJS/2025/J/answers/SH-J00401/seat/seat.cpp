#include<bits/stdc++.h>
using namespace std;
int n,m,x,t,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>t;
	for(int i=0;i<n*m-1;i++){
		cin>>x;
		if(x>t)cnt++;
	}
	cnt++;
	int x,y;
	x=(cnt+n-1)/n;
	if(x%2){
		if(cnt%m)y=cnt%m;
		else y=m;
	}
	else{
		if(cnt%m)y=m-cnt%m+1;
		else y=1;
	}
	cout<<x<<' '<<y;
} 
