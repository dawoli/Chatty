#include<bits/stdc++.h>
#define int long long
#include<fstream>
using namespace std;

ifstream fin("color.in");
ofstream fout("color.out");
#define cin fin
#define cout fout

int T,n;
int a[200005],color[200005],c[200005];
signed main(){
	cin>>T;
while(T--){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=-1;
	for(int opt=0;opt<(1<<n);opt++){
		int op=opt;
		for(int j=1;j<=n;j++){
			color[j]=op%2;
			op/=2;
		}
		for(int j=1;j<=n;j++){
			int flag=0;
			for(int k=j-1;k>=0&&flag==0;k--){
				if(color[k]==color[j]){
					if(a[k]==a[j]){
						c[j]=a[j];
					}
					else{
						c[j]=0;
					}
					flag=1;
				}
			}
			if(flag==0){
				c[j]=0;
			}
		}
		int sum=0;
		for(int j=1;j<=n;j++){
			sum+=c[j];
		}
		ans=max(ans,sum);
	}
	cout<<ans<<'\n';
}
	return 0;
}
