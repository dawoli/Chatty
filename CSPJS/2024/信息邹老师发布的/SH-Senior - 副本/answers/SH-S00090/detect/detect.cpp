	//freopen不要注释 
	//freopen不要注释 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int q;
int d[3005];
int v[3005];
int a[3005];
int p[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>q;
	for(int z=1;z<=q;z++){
		int n,m,l,lim;
		cin>>n>>m>>l>>lim;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		
		for(int j=1;j<=m;j++){
			cin>>p[j];
		}
		int ans=0;
		for(int k=1;k<=n;k++){
			if(a[k]==0){
				if(v[k]>lim){
					ans++;
				}
			}
			if(a[k]>0){
				if(v[k]>lim){
					ans++;
				}
				if(v[k]<=lim){
					double ju=(((lim*lim)-(v[k]*v[k]))/2.0/a[k]);
					if(ju<p[m]-d[k])
						ans++;
				}
			}
		}
		int kkk=m-1;
		cout<<ans<<" "<<kkk<<'\n';
	}
	//输出用\n 
	//记得写freopen，并且不要注释掉！！！！！
	//freopen不要注释
	//写return 0 
	return 0;
} 

