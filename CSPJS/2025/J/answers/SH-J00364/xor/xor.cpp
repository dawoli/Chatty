#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		long long ans=0;
		for(int j=i;j<=n;j++){
			if(a[j]==k){
				cnt++;
				i=j;
				break;
			}
			ans=ans^a[j];
			if(ans==k){
				cnt++;
				i=j;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
