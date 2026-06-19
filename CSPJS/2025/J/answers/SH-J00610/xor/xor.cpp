#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0,b=a[0],t=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(b==k){
				t++;
				b=0;
				ans++;
				break;
			}else{
				b=b^a[j];
			}
		}
	}cout<<ans;
	return 0;
} 
