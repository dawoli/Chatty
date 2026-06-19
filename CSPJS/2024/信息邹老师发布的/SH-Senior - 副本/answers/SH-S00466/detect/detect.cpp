#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL m,n,L,V,T;
LL d[1000005],v[1005],a[1005],p[1000005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(LL i=1;i<=T;i++){
		cin>>n>>m>>L>>V;
		LL sum=0,cclose=m; 
		LL chaosu[n+1];
		LL open[m+1];
		for(LL j=1;j<=n;j++){cin>>d[j]>>v[j]>>a[j];
		//驶入位置，初速度，加速度 
		chaosu[j]=0;} 
		for(LL j=1;j<=m;j++){cin>>p[j];open[j]=0;
		}
		for(LL j=1;j<=n;j++){
			if(v[j]>V){
			sum++;chaosu[j]=1;
			}
		} 
		cout<<sum<<" ";
		for(LL j=1;j<=n;j++){
			if(chaosu[j]==1){
				for(LL k=1;k<=m;k++){
					if(p[k]>=d[j]){open[k]=1;break;
					}
				}	
			}
		}
		for(LL j=1;j<=m;j++){
			if(open[j]==1)cclose--;
		}
		cout<<cclose<<endl;
	}  
	return 0;
}
