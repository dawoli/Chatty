#include<bits/stdc++.h>
using namespace std; 
int t,n,a[200005],sum; 
int main(){
	freopen("color.in","r",stdin); 
	freopen("color.out","w",stdout); 
	cin>>t; 
	for(int i=1; i<=t; i++){
		cin>>n; 
		for(int j=1; j<=n; j++){
			cin>>a[j]; 
		}
		sort(a+1,a+n+1); 
		for(int j=1; j<=n; j++){
			if(a[j]==a[j+1]) sum=sum+a[j],j+=1; 
		}
		cout<<sum<<endl; 
		sum=0; 
	}
	fclose(stdin); 
	fclose(stdout); 
	return 0; 
}
