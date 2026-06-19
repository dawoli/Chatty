






#include <bits/stdc++.h>
using namespace std;
long long n,k,nn,ll=1,rr=1;
long long a[500005],b[300],v[5005][5005],f[500005];
void d(int l,int r,int cnt,int cnt2){
	if(cnt2==nn){
		cout<<cnt;
		exit(0);
	}
	int ii;
	for(int i=l;i<=r;i++){
		long long t=a[i];
		ii=1;
		while(t){
			if(t%2==b[ii]){
				b[ii]=0;
			}else{
				b[ii]=1;
			}
			t/=2;
			ii++;
		}
	}
	long long sum=0;	
	for(int j=ii,l=0;j>=1,l<ii;j--,l++){
		long long su=pow(2,l);
		sum+=su*b[j];
		b[j]=0;
	}
	
	if(sum==k&&v[l][r]==0&&!f[l]&&!f[r]){
		for(int i=l;i<=r;i++){
			f[i]=1;
		}
		v[l][r]=1;
		if(r<n){
			d(l,r+1,cnt+1,cnt2+1);
		}else if(l<n){
			d(l+1,r,cnt+1,cnt2+1);
		}else{
			ll++;
			rr++;
			d(ll,rr,cnt+1,cnt2+1);
		}
	}else{
		if(r<n){
			d(l,r+1,cnt,cnt2+1);
		}else if(l<n){
			d(l+1,r,cnt,cnt2+1);
		}else{
			ll++;
			rr++;
			d(ll,rr,cnt,cnt2+1);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int fff=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			fff=0;
		}
		
	}
	if(fff==1&&k==0){
		cout<<n/2;
		return 0;
	}
	if(fff==1&&k==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		nn+=i;
	}

	d(1,1,0,0);
	
	return 0;
}
