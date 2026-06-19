#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool m0=true,m1=true,m01=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0) m0=false;
		if(a[i]!=1) m1=false;
		if(a[i]!=1&&a[i]!=0) m01=false;
	}
	if(m0==true&&k==0){
		cout<<n;
		return 0;
	}
	if(m0==true&&k==1){
		cout<<0;
		return 0;
	}
	if(m1==true&&k==0){
		cout<<n/2;
		return 0;
	}
	if(m1==true&&k==1){
		cout<<n;
		return 0;
	}
	if(m01=true&&k==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) sum++;
		}
		cout<<sum;
		return 0;
	}
	int t;
	int cnt=0,mx=0;
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			t=a[i];
			for(int j=i;j<=n;j++){
				if(i==j){
					t=a[i];
				}
				else t^=a[j];
				if(t==k){
					cnt++;
					i=j+1;
					break;
				}
			}
		}
		mx=max(mx,cnt);
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
