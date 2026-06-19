#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t;
int n;
int a[N],f[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n;i++){
			int j=i-1,gt=0;
			while(a[i]!=a[j] && j>=1)j--;
			int t=j;
			f[i]=f[i-1];
			if(t!=0) f[i]=max(f[i],f[t]+a[i]); 
			j++;
			while(a[i]!=a[j] && j<i){
				if(f[j]!=f[j-1] && t!=0){
					int u=j-1;
					while(a[u]!=a[j])u--;
					if(u>t)break;
					f[i]=max(f[i],f[j]+a[i]);
					break;
				}
				j++;
			}	
		}
		cout<<f[n]<<"\n";
	}
	return 0;
}
/*
2
15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13
15
1 12 11 11 7 11 15 6 4 6 3 15 7 5 2
*/

