#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5010],f[5010];
long long i;
int c(int x,int y){
	return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n-2;l++){
		int r=l+1,s=a[l]+a[l+1],mx=max(a[l],a[l+1]);
		
		while(r<n){
			r++;
			s+=a[r];
			mx=max(mx,a[r]);
			if(s>2*mx){
			    ans++;
			    cout<<l<<' '<<r<<endl;
		    }
		    
		}
	}
	cout<<ans;
	return 0;
}
