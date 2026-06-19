#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N];
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(k==0){
		for(int i=0;i<n;i++){
			if(i==n-1){
				if(a[i]==0){
					ans++;
				}
			}
			else{
				if(a[i]==0){
					ans++;
				}
				if(a[i]==a[i+1]){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
