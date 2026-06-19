#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int yihuo(int x,int y){
	int a[25]={},b[25]={};
	long long er=1;
	for(int i=1;i<=24;i++){
		er*=2;
	}
	for(int i=25;i>=1;i--){
		if(x>=er){
			x-=er;
			a[i]=1;
		}
		if(y>=er){
			y-=er;
			b[i]=1;
		}
		er/=2;
	}
	int ans=0;
	er=1;
	for(int i=1;i<=25;i++){
		if(a[i]!=b[i]){
			ans+=er;
		}
		er*=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int num=a[i];
			for(int p=i;p<j;p++){
				num=yihuo(num,a[i+p-i+1]);
			}
			if(num==k){
				ans++;
				i=j+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
