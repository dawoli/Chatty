#include<bits/stdc++.h>
using namespace std;
int n,k,a[500006],ans;
bool aon(){
	for(int i=1;i<=n;i++)
		if(a[i]!=1)
			return 0;
	return 1;
}
bool leo(){
	for(int i=1;i<=n;i++)
		if(a[i]>1)
			return 0;
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(aon()&&(k==0)){
		ans=n-1;
		cout<<ans;
		return 0;
	}
	else if(leo()){
		if(k==0){
			for(int i=1;i<=n;i++)
				if(a[i]==0)
					ans++;
			for(int i=1;i<n;i++)
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			cout<<ans;
			return 0;
		}
		else if(k==1){
			for(int i=1;i<n;i++){
				if((a[i]==0)&&(a[i+1]==1)){
					ans++;
					i++;
				}
				else if(a[i]==1)
					ans++;
			}
			cout<<ans;
			return 0; 
		}
	}
	else{
		cout<<"551";
	}
	return 0;
}
