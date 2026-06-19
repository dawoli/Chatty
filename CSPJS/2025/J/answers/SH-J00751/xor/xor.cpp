#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)sum++;
			else if(a[i]==1&&a[i+1]==1){
				sum++;
				a[i+1]=2;
			}
		}
	}else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
