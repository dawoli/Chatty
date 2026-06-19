#include<bits/stdc++.h>
using namespace std;
const int N=500009;
const int M=-1;
int a[N];
long long ihuo(int l,int r){
	int ans=a[l];
	for(int i=l+1;i<=r;i++){
		if(a[i]==M) return M;
		ans=ans^a[i];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt=max(cnt,a[i]);
	}
	if(cnt<=1){
		if(k<=1){
			int po=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) po++;
			}
			cout<<po<<endl;
			return 0;
		}
		else{
			cout<<0<<endl;
			return 0;
		}
	}
	if(k>pow(2,cnt/2)){
		cout<<0<<endl;
		return 0;
	}
	long long ans1=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(a[j]==M) continue;
			if(ihuo(j,j+i-1)==k){
				ans1++;
				for(int t=j;t<=j+i-1;t++){
					a[t]=M;
				}
			}
		}
	}
	cout<<ans1<<endl;
	return 0;
}
