#include<bits/stdc++.h>
#define N 105
typedef long long ll;
using namespace std;
bool cmp(const ll&a,const ll&b){
	return a>b;
}
ll n,m,tgt,a[N*N];
bool down=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>a[i];
	tgt=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(ll i=1,j=1,c=1;i*j<=n*m;c++){
		if(a[c]==tgt){
			cout<<j<<" "<<i;
			return 0;
		}
		if(down) i++;
		else i--;
		if(i>n) i=n,j++,down=0;
		if(i<1) i=1,j++,down=1;
	}
	return 0;
}
