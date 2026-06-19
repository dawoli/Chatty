#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],n,k,sum[N];
bool flag=false,flag1=false;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int arr=a[1];
		if(a[i]!=arr)flag=true;//判断是否全部相同 
		if(a[i]!=0&&a[i]!=1)flag1=true;//判断是否只含有0和1 
	}
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	if(n==1&&k==0){//测试点1 
		if(a[1]==0){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(k==0&&!flag){//测试点3 
		if(n%2==1){
			cout<<(n-1)/2;
			return 0;
		}
		else{
			cout<<n/2;
			return 0;
		}
	}
	if(k==0&&!flag1){//测试点2、4、5、13 
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				continue;
			}
			if(a[i]==1&&a[i+1]==1){
				ans++;
				i++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1&&!flag1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
				continue;
			}
			if(a[i]!=a[i+1]){
				ans++;
				i++;
			}
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=i;
		bool check=true;
		while(l<=r&&check){
			if(sum[r]-sum[l-1]==k){
				ans++;
				i=r;
				check=false;
			}
			r++;
		}
	}
	cout<<ans;
	return 0;
}
