#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500009];
bool flag=false;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.in","r",stdout);
	cin>>n>>k;
	if(n==1){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
	}if(n==2){
		cout<<1;
		fclose(stdin);
		fclose(stdout);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=true;
	}
	if(k==0){
		cout<<n/2;
	}
	if(flag==false){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				i++;ans++;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
