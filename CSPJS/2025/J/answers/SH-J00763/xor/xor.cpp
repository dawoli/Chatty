#include<bits/stdc++.h>
using namespace std;
int op(int k){
	for(int i = 1;i<=20;i++){
		if(k<=(1<<i)) return i-1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[500005];
	cin>>n>>k;
	int sum = 0;
	int s = k;
	int m = op(k);
	int ans = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=(1<<(m-1)) && a[i]<(1<<(m+1))) ans++;
	}
	if(k==1){
		int t = a[1];
		for(int i = 2;i<=n;i++){
			if(a[i]!=t && t!=-1){
				sum++;
				t = -1;
			}else if(t==-1){
				t = a[i];
			}
		}
		cout<<sum;
	}else if(k==0){
		int t = a[1];
		for(int i = 2;i<=n;i++){
			if(a[i]==t){
				sum++;
				t = -1;
			}else if(t==-1){
				t = a[i];
			}else t = a[i];
		}
		cout<<sum;
	}else{
		cout<<ans;
	}
	 
	return 0;
	fclose(stdin);
	fclose(stdout);
}
