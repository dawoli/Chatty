#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3)
		cout<<0;
	else{
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3])
			cout<<1;
		else
			cout<<0;
	}
}
