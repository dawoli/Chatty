#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<n*m;i++){
		int a;
		cin>>a;
		if(a>s){
			cnt++;
		}
	}
	int x,y;
	x=cnt/n+1;
	if(x%2==0){
		y=n-cnt%n;
	}else{
		y=cnt%n+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
