#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s;
	cin>>s;
	int cnt=1;
	for(int i = 0;i < n*m-1;i ++){
		int p;
		cin>>p;
		if(p>s)cnt++;
	}
	int x=cnt/n+(cnt%n==0?0:1),y=cnt%n;
	if(y==0)y=n;
	if(x%2==0)y=n-y+1;
	//else y++;
	cout<<x<<' '<<y; 
	return 0;
}

