#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,r[N],dlt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+1+n);
	int lf=1,rf=2;
	while(rf<=n){
		if(r[lf]<r[rf]) dlt++,lf++,rf++;
		else rf++;
	}
	cout<<n-dlt;
	return 0;
}

