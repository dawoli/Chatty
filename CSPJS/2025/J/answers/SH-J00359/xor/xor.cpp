#include<bits/stdc++.h>
using namespace std;
const int N=500009;
int a[N];bool v[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;bool check;
	cin>>n>>k;
	for(int i=1;i<=n;i++){cin>>a[i];if(!a[i])check=false;}
	if(check&&(!k)){cout<<floor(n/2.0);return 0;}
	for(int i=1;i<=n;i++){if(a[i]==k){ans++;v[i]=1;}}
	for(int i=1;i<n;i++){
		for(int x=1;x<=n-i;x++){
			if(v[x])continue;
			int sum=a[x];bool flag=0;
			for(int j=x+1;j<=x+i&&j<=n;j++){
				if(v[j]){flag=1;break;}
				sum=sum^a[j];
			}
			if(!flag&&sum==k){
				ans++;
				for(int j=x;j<=x+i;j++)v[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
