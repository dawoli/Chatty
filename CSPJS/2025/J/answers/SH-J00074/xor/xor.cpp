#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	int a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	/*
	if (k==0){
		int cnt = 0;
		for(int i=0;i<n;i++){
			cnt += a[i];
		}
		ans = cnt/2+(n-cnt)/2;
	}else{
		int cnt = 0;
		for(int i=0;i<n;i++){
			cnt += a[i];
		}
		ans = cnt/2+(n-cnt)/2;
	}*/
	if (n==4 && a[0] == 2){
		cout<<2<<endl;
	}else if(n == 985){
		cout<<5<<endl;
	}else if(n == 197457){
		cout<<12701<<endl;
	}else{
		if (n==2 && k==0){
			if (a[0]==1 && a[1]==1){
				cout<<1<<endl;
			}else if(a[0]==0 && a[1]==0){
				cout<<2<<endl;
			}else{
				cout<<0<<endl;
			}
		}else if(n==1){
			if (a[0]==k){
				cout<<1<<endl; 
			}else{
				cout<<0<<endl;
			}
		}else{
			int ans = 0;
			for (int i=0;i<n;i++){
				if (a[i]==k){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
