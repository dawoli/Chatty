#include<iostream>
using namespace std;
int n,k,ans=0;
int main(){
	cin>>n>>k;
	int a[n]={},p=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			p=i;
			continue;
		}
		for(int j=p+1;j<i;j++){
			a[j]^=a[i];
			if(a[j]==k){
				ans++;
				p=i;
				break;
			}
		}
	}
	cout<<ans;
}
