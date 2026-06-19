#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int ma_x=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(ma_x<a[i]) ma_x=a[i];
	}
	sort(a,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int y=a[1]+a[2]+a[3];
		if(y>ma_x*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
