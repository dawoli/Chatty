#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","I",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10007];
	for(int i=1;i<=n*m;i++)cin>>a[i];
	if(a[1]>a[2])cout<<n<<m;
	else cout<<"1 1";
}
