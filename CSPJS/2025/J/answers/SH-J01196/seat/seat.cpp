#include<bits/stdc++.h> 
using namespace std;
int n,m,a[109],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0])cnt++;
	}
	cout<<cnt/n+1<<" ";
	if(cnt%(n*2)+1<=n)
		cout<<cnt%(n*2)+1;
	else cout<<2*n-(cnt%(n*2));
	return 0;
} 
