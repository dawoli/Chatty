#include<bits/stdc++.h>
using namespace std;
int n,k,a[500009];
int f[1009][1009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=1000){
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				for(int q=i;q<=j;q++)
					f[i][j]^=a[q];
		int cnt=0;
		for(int i=1;i<=n;){
			bool flag=0;
			for(int j=i;j<=n;j++)
				if(f[i][j]==k){
					cnt++,i=j+1;
					flag=1;
					break;
				}
			if(!flag) i++;
		}
		cout<<cnt;
	}
	return 0;
}
