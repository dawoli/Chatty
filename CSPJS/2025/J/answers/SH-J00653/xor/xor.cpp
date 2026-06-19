#include<iostream>
#include<cstdio>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0&&a[1]==1){
		bool f=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=1){
				f=0;
				break;
			}
		}
		if(f) cout<<n/2;
	}
	else if(k<=1&&a[1]<=1){
		bool f=1;
		for(int i=1;i<=n;i++){
			if(a[i]>1){
				f=0;
				break;
			}
		}
		if(f){
			int sum=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(a[i]^a[j]==k) sum++;
				}
			}
			cout<<sum;
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
