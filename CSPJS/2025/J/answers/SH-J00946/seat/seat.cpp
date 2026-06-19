#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
string s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];int k=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) k++;
	}
	int l=(k+n-1)/n,h=0;
	if(l%2==1) h=k-n*(l-1);
	else h=n*l-k+1;
	cout<<l<<" "<<h;
	return 0;
}
