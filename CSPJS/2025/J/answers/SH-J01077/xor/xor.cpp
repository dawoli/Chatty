#include<bits/stdc++.h> 
using namespace std;
int a[5010];
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k,ans=0,asn=0;
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]==1)ans++;
	if(a[i]==0)asn++;
}
	if(k==0&&ans==n)cout<<n/2;
	else if(k==0){
	int r=1000,cou=0;
		for(int i=0;i<n;i++){
			if(a[i]==0){
				cou++;
				r=100;
			}
			else if(r==1&&a[i]==1){
				cou++;
				r=100; 
			}
			else r=1;
		}
		cout<<cou;
	}
	else if(k==1)cout<<ans;
	return 0;
}
