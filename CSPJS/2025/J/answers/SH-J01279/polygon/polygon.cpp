#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int sum=0;
	int max=0;
	int ans=0;
	if(n==3){
		for(int i=1;i<=n;i++){
			if(max<=a[i])max=a[i];
			sum+=a[i];
		}
		if(sum>(max*2)){
			ans=1;
		}
		else{
			ans=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
