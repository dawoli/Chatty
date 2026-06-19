#include<bits/stdc++.h>
using namespace std;
int b[10000],n,m,o,p,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>b[i];
	}
	o=b[1];
	sort(b+1,b+n*m+1,greater<int>());
	for(int i=1;i<=n*m;++i){
		if(b[i]==o){
			p=i;
			break;
		}
	}
	x=int(ceil(double(p)/n));
	if(x%2){
		y=p%n;
	}
	else y=n-p%n+1;
	cout<<x<<' '<<y;
	return 0;
}
