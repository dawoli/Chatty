#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],pos[500050];
bool flag=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	if(k!=0&&k!=1){
		cout<<0;
		return 0;
	}
	if(flag){
		if(k==1){
			cout<<n;
			return 0;
		}
		if(k==0){	
			if(n%2==0){
				cout<<n/2;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
	}
	else{
		int cnt0=0,cnt1=0;
		int last=0,sum=0;;
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt0++;
			if(a[i]==1){
				cnt1++;
				if(cnt1==1)last=i;
				else{
					sum+=(i-last-1);
					last=i;
				}
			}
		}
		if(k==1){
			cout<<cnt1;
			return 0;
		}
		if(k==0){
			if(cnt1%2==1){
				cout<<0;
				return 0;
			}
			else{
				cout<<cnt1/2+cnt0-sum;
				return 0;
			}
		}
	}
	return 0;
}
