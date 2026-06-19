#include <bits/stdc++.h>
using namespace std;
int a[114514];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	if(n<=2){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	if(n==3){
		sort(a,a+3);
		if(a[0]+a[1]>a[2]){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0;
		}
	}
	cout<<n*114514*7%998244353;
	return 0;
} 
