#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(k==1) if(a[i]==1) cnt++;
		else if(k==0){
			if(a[i]==0) cnt++;
			else if(a[i]==a[i-1]) cnt++,a[i]=2;
		}
	}cout<<cnt;
	return 0;
}//41m(%25)
