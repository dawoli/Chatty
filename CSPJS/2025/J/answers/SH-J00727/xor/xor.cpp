#include <bits/stdc++.h>
using namespace std; 
 
// i cant ak csp-j because of this problem
// www 

int qz[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	
	if(k>n){ 
		cout<<0;
		return 0;
	} 
	
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0) qz[i]=a[i];
		else qz[i]=qz[i-1] xor a[i];
	}
	int last=0;int ans=0;
	for(int i=0;i<n;i++){
		for(int j=last;j<=i;j++){
			int x=0;
			if(j==0){
				x=0;
			}else{
				x=qz[j-1];
			}
			if((qz[i] xor x)==k){
			//	cout<<j<<" "<<i<<endl;
				ans++;
				last=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

//only n^2 
