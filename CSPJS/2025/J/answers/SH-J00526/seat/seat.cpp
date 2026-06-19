#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt=1,ansn,ansm;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a)
			cnt++;
	}
	ansn=(cnt-1)/n+1;
	if(ansn%2==1)
		ansm=(cnt-1)%n+1;
	else
		ansm=n-(cnt-1)%n;
	cout<<ansn<<" "<<ansm;
	return 0;
}
