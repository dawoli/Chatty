#include<bits/stdc++.h>
using namespace std;
int n,r[100005],a[100005],b[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++){
		a[r[i]]++,b[r[i]]++;
	}
	for(int i=1;i<=r[n];i++){
		if(b[i]==0)continue;
		int sum=b[i];
		while(sum){
			for(int j=i+1;j<=n;j++){
				if(a[j]==0) continue;
				if(sum>a[j]) {
					ans-=a[j];
					sum-=a[j];
				}
				else {
					ans-=sum;
					a[j]-=sum; 
					sum=0;
					break;
				}
			}
			if(sum!=0){
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
} 
