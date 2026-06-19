#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],cnt,ans,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=max(sum,a[i]);
	}
	if(k==0&&sum<2){
		int flag=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)
				ans++;
			else if(a[i]==1){
				flag++;
				if(flag==2)ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	else if(k==1&&sum<2){
		for(int i=1;i<=n;i++)
			if(a[i]==1)ans++;
		cout<<ans;
		return 0;
	}
	long long l=1,r=1;
	while(l<=n){
		cnt=0;
		for(long long i=l;i<=r;i++)cnt^=a[i];
		if(cnt==k){
			ans++;
			l=r+1;
			r=l; 
		}
		else if(r<n)r++;
		else if(r==n){
			r=l+1;
			l=r;
		}
	}
	cout<<ans;
	return 0;
}
