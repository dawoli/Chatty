#include<bits/stdc++.h>
using namespace std;
const int NM=109;
int n,m;
int a[NM],scr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	scr=a[1];
	sort(a+1,a+n*m+1);
	int rnk=lower_bound(a+1,a+n*m+1,scr)-a;
	rnk=n*m-rnk+1;
	int r,c;
	r=(rnk-1)/n+1;
	c=rnk%n;
	if(!c){
		c=n;
	}
	if(!(r&1)){
		c=n-c+1;
	}
	cout<<r<<" "<<c;
	return 0;
}
