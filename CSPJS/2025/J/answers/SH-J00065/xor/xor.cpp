#include<bits/stdc++.h>
using namespace std;
long long a[5000005],b[5000005][2];
int d[5000005];
long long xor_sum(long long l,long long r){
	long long ans=0;
	for(long long i=l;i<=r;i++) ans=ans^a[i];
	return ans;
}
bool select(long long l,long long r){
	for(int i=l;i<=r;i++){
		if(d[i]==0){
			for(;i>=l;i--) d[i]--;
			return false;
		}
		d[i]++;
	}
}
int main(){
	long long n,k,c=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long l=1;l<=n;l++){
		for(long long r=l;r<=n;r++){
			if(xor_sum(l,r)==k){
				b[c][0]=l;
				b[c][1]=r;
				c++;
			} 
		}
	}
	memset(d,-1,sizeof(d));
	int ans;
	for(int i=0;i<c;i++){
		ans+=select(b[i][0],b[i][1]);
	}
	cout<<ans;
	return 0;
}
