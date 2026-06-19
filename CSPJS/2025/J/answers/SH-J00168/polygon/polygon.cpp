#include <bits/stdc++.h>
using namespace std; 
int n;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int m=a[0];
		int sum=a[0]+a[1]+a[2];
		for(int i=1;i<=n;i++){
			if(a[i]>m){
				m=a[i];
			}
		}
		if(sum>m*2) cout<<1;
		else cout<<0;
		return 0;}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
