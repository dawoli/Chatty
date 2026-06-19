#include <bits/stdc++.h>
using namespace std;

long long n,k,cnt;
long long a[100050];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
	
		long long xorr=a[i];
		if(xorr==k){
			cnt++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			xorr=xorr xor a[j];
			if(xorr==k){
				cnt++;
				i=j;
				break;
			}
			
			
		}
	}
	cout<<cnt;
	return 0;

}
