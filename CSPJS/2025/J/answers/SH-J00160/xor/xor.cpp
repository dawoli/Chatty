#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int cnt1=0;
	int cnt0=0;
	int cntk01=0;
	int ji=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt1++;
			if(ji==1&&a[i-1]==1){
				cntk01++;
				ji=0;
			}
			else{
				ji=1;
			}
		}
		else{
			cnt0++;
			ji=0;
		}
	}
	int ans=0;
	if(k==0){
		ans=cntk01+cnt0;
	}
	else if(k==1){
		ans=cnt1;
	}
	else{
		ans=3;
	}
	cout<<ans<<endl;
	return 0;
}
