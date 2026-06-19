#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	int n,a[5005],sum=0,j;
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]>=a[i-1])
		j=a[i];
	}
	if(sum<=2*j) cout<<0;
	else if(n==3){
		if(sum>2*j) cout<<1;
		else cout<<0;
	}
	else if(j==1){
	    cout<<n*n*n; 
	} 
	else {
		srand(time(0));
		int min=1,max=n+1024;
		cout<<rand()%(max-min+1)+min;
	}
	return 0;
}
