#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sco,Id,a[105],c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	sco = a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i] == sco){
			Id = i;
			break;
		}
	}
	
	c = ceil(1.0*Id/n);
	r = Id%n;
	if(r == 0) r = n;
	if(c%2 == 0) r = n+1-r;
	cout<<c<<" "<<r;
	return 0;
}



