#include<bits/stdc++.h>
using namespace std;
int m,n,a[200],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
	int r=cnt/n+1;
	cout<<r<<' '<<(r%2?cnt%n+1:n-cnt%n);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
