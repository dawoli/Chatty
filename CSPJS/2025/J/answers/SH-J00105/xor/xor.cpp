#include<bits/stdc++.h>
using namespace std;
long long int a[101010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int n,k,cnt=0,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
		}
	}
	if(k!=0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i] && sum!=k && sum+a[i]<=k) sum++;
				if(k==sum){
					cnt++;
					sum=0;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
