#include<bits/stdc++.h>
using namespace std;
int n,m,r,x;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	int k=n*m;
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--){
		x++;
		if(a[i]==r){
			break;
		}
	}
	int ans1=x/n;
	int ans2=x%n;
	if(x%n!=0){
		ans1++;
	}
	else{
		ans2=n;
	}
	if(ans1%2==0){
		ans2=n-ans2+1;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
