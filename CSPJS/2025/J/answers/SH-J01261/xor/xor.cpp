#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1145141];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)sum++;
		}
		cout<<sum;
		return 0;
	}
	if(k==1){
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)sum++;
	}
		cout<<sum;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
