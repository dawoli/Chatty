#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int k=0;k<n;k++){
		for(int i=k;i<n;i++){
		long long x=0;
		for(int j=i;j<n;j++){
			x=x+a[j];
			if(x>2*a[j] and j>=2){
				ans++;
				x=0;
				}
			}
		}
	} 
	cout<<ans;
	return 0;
}
