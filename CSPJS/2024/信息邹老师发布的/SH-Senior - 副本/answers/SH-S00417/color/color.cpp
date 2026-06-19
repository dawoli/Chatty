#include<bits/stdc++.h>
using namespace std;
int t,n,a[20010],b[20010],tot,jl;
bool bo;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;++i){
		cin>>n;
		for (int j=1;j<=n;++j) cin>>a[i];
		for (int j=1;j<=n;++j){
			bo=0;
			for (int k=1;k<=j;++k){
				if (a[j]==a[k]){
					bo=1;
					jl=k;
					break;
				}
			}
			if (j==1) b[j]=0;
			if (bo==0&&j>1){
				b[j]=(int)(!(bool)b[j-i]);
			}else{
				b[j]=b[jl];tot+=a[jl];
			}
		}
	}
	cout<<tot;
	return 0;
}
