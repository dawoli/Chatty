#include<bits/stdc++.h>
using namespace std;
long long T,n,m,L,V,d[30][100010],v[30][100010],a[30][100010],p[30][100010]={0},b[30][100010]={0},c[30][100010]={0};
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(long long i=0;i<T;i++){
		
		cin>>n>>m>>L>>V;
		long long w=V*V,cnt=0,ans=0;
		for(long long j=0;j<n;j++){
			cin>>d[i][j]>>v[i][j]>>a[i][j]; 
			if(a[i][j]<0){
				ans=1;
			}
		}
		for(long long j=0;j<m;j++){
			cin>>p[i][j];
		}
		for(long long j=0;j<n;j++){
			if(a[i][j]==0){
				if(v[i][j]<V){
					b[i][j]=1;
				}
			}
			
			for(long long k=0;k<m;k++){
				if(b[i][j]==0){
					if(d[i][j]<=p[i][k]){
						long long h=p[i][k]-d[i][j];//加速度的距离 
						long long e=2*a[i][j]*h,f=v[i][j]*v[i][j];
						long long g=e+f;
						if(g>w){
							c[i][k]++;
							b[i][j]=-1;
							cnt++;
						}
					}
		
				}
			}
			if(b[i][j]==0){
				b[i][j]=1;
			} 
		
		}
		
		
		cout<<cnt<<" ";
		if(ans==0){
			if(cnt>0){
				cout<<m-1<<endl;
			}
			else{
				cout<<m<<endl;
			}
		}
		else{
			long long z=0;
			for(int j=0;j<m;j++){
				if(c[i][j]==0){
					z++;
				}
			}
			cout<<z<<endl;
		}
	} 
	return 0;
} 
