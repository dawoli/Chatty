#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
bool q(int l,int r,int x){
	int ans=a[l];
	for(int i=l+1;i<=r;i++){
		ans=(ans xor a[i]);
	}
	if(ans==x) return 1;
	else return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ont","w",stdout);
	cin>>n>>k;
	
	for(int i=0;i<n;i++) cin>>a[i];
	int j=0;
	int ans=0;
	int p2;
	while(j!=n){
		bool pan=0;
		for(int p=j;p<n;p++){
			if(q(j,p,k)==1){
				pan=1;
				p2=p;
				ans++;
				break;
			}
		}
		if(pan==1) j=p2+1;
		else j++;
	}
	cout<<ans;
	return 0;
} 
