#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n*m],score;
	for(int i=0;i<n*m;i++)
			cin>>a[i];
	score=a[0];
	sort(a,a+n*m,[](int a,int b){
		return a>b;
	});
	for(int i=0;i<n*m;i++)
		if(a[i]==score){
			cout<<i/n+1<<" "<<(i/n%2?n-i%n:i%n+1);
			return 0;
		}
}
