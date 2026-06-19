#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[110],R1;
	cin>>n>>m;
	cin>>a[0];
	R1=a[0];
	for(int i=1;i<n*m;i++)
		cin>>a[i];
	sort(a,a+n*m);
	int cnt=0;
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==R1){
			cnt=n*m-i;
		}
	}
	cout<<(cnt+n-1)/n<<' ';
	int f=cnt%n;
	if(f==0){
		f=n;
	}
	if(((cnt+n-1)/n)%2==0)
		cout<<n-f+1;
	else
		cout<<f;
	return 0;
}

