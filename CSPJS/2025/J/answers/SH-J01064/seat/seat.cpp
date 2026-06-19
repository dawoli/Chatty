#include<iostream>
#include<fstream>
using namespace std;
int n,m,c,r,yang,pre;
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>yang;
	for(int i=1;i<n*m;i++){
		int cur;
		cin>>cur;
		if(cur>yang){
			pre++;
		}
	}
	c=pre/n+1;
	if(c%2){
		r=pre%n+1;
	}else{
		r=n-pre%n;
	}
	cout<<c<<' '<<r;
	return 0;
}
