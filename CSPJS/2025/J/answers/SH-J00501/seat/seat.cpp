#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y;
long long cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long sc;
	for(int i=1;i<=n*m;i++){
		int x; cin>>x;
		if(i==1) sc=x;
		if(x>sc) cnt++;
	}
	cnt++;
	y=cnt/n+(cnt%n!=0);
	if(y%2==1){
		if(cnt%n!=0) x=cnt%n;
		else x=n;
	}else{
		if(cnt%n!=0) x=n-cnt%n+1;
		else x=1;
	}
	cout<<y<<" "<<x<<endl;
	return 0;
}
