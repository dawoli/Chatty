#include<bits/stdc++.h>
using namespace std;
long long a[500100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long d=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==d){
			cout<<(n*m-i+1)/n+(n*m-i+1)%n<<" "<<(n*m-i+1)-(n*m-i+1)%n;
			return 0;
		}
	}
	return 0;
}
