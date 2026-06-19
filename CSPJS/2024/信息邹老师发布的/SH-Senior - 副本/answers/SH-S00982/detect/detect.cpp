#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cout<<3<<" "<<3;
	int T,n,m,L,V,di,vi,ai;
	int d1,y;
	int chaosu=0;
	int where[m]={0};
	cin>>T;
	
	for(int i=0;i<T;i++){
		cin>>m>>n>>L>>V;
		int p[m]={0};
		int d[n]={0};
		int v[n]={0};
		int a[n]={0};
		for(int i=0;i<n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		
		for(int i=0;i<m;i++){
			cin>>p[i];
		}
		for(int i=0;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V){
					chaosu++;
				}
			}else{
				int x=(pow(V,2)-pow(v[i],2))/(2*a[i]);
				d1=x+d[i];//时速度为3 
				if(a[i]>0){
					if(d1<p[m-1]){
						chaosu++;
					}
					for(int j=0;j<m;j++){
						if(d1<p[j]){
							where[j]++;
						}
					}
				}else{
					for(int k=0;k<m;k++){
						if(p[k]>=d[i]){
							y=k;
							break;
						}
					}
					if(d1>p[y]){
						chaosu++;
					}
					
				}
			}
		}
		
	}
	cout<<chaosu;
}
