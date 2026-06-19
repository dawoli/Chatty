#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a) cnt++;
	}
	cout<<cnt/n+1<<" ";
	if(cnt%(2*n)>=n) cout<<n-(cnt%n);
	else cout<<(cnt%n)+1;
	return 0;
}
