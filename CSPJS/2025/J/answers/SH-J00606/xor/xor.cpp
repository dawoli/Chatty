#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cnt=0;
	int sum=a[0];
	for(int i=1;i<n;i++){
		if(sum==k){
			cnt++;
			sum=a[i+1];
			i++;
			continue;
		}
		sum=sum^a[i];
		
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
} 
