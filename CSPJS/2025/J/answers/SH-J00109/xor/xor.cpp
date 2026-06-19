#include<bits/stdc++.h>
using namespace std;

long long n,k,a[500005],cnt;

int main(){
	//²»ÄÜÉ¾£¡£¡£¡£¡£¡£¡ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
				continue;
			}
			if(a[i]==a[i+1]){
				cnt++;
				i++;
			}
		}
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

