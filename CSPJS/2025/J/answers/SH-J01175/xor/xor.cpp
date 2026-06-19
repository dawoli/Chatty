#include<bits/stdc++.h>
using namespace std;

// 0^1=1
// 0^0=0
// 1^0=1
// 1^1=0
int a[200005];
bool used[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	a[n]=0x3f3f3f3f;
	int ans=0;
	if(k==0) {
		
		for(int i=0;i<n;i++){
			if(a[i]==0) ans++;
			if(a[i]==1 && a[i+1]==1 && !used[i]){
				used[i]=1;
				used[i+1]=1;
				ans++;
				
			}
		}
	}
	if(k==1){
		for(int i=0;i<n;i++){
			if(a[i]==1) ans++;
		}
	}
	cout<<ans;
	
}
