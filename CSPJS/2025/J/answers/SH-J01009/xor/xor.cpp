#include<bits/stdc++.h>
using namespace std;
const int N=50009;

int n,k,a[N];
int f[N],d[N];
bool vst[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	f[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])	f[i]=f[i-1];
		else f[i]=f[i-1]+1;
	}
	int ans=0,cnt=0,x=0;
	for(int i=1;i<=n;i++){
		vst[i]=1;
		if(a[i]>k&&i==1){
			vst[i]=0;
			d[i]=d[i-1];
			continue;
		}
		if(a[i]==k){
			vst[i]=0;
			d[i]=d[i-1]+1;
			continue;
		}
		else{
			cnt=0;
			for(int j=i;j>=1;j--){
				if(!vst[j])	cnt=j;
			}
			x=f[i]-f[cnt]-1;
			if(x==k)	d[i]=d[i-1]+1;
			else d[i]=d[i-1];
		}
	}
	cout<<d[n]<<endl;
	return 0;
} 

