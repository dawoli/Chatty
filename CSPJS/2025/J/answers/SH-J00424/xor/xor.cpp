#include<iostream>
using namespace std;
int a[500005],b[500005],c[500005];
int near(int x,int n){
	for(int i=x;i<=n;i++){
		if(c[i])return i-1;
	}
	return n;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	b[0]=0;
	for(int i=1;i<=n;i++)c[i]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
			c[i]=1;
		}
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=near(i,n);j++){
			if(b[j]^b[i]==k){
				bool flag=0;
				for(int l=i+1;l<=j;l++)if(c[l])flag=1;
				if(flag)continue;
				cnt++;
				for(int l=i+1;l<=j;l++)c[l]=1;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
