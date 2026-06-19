#include<bits/stdc++.h>
using namespace std; 
int t,n,m,c,x,d[100005],v[100005],a[100005],p[100005],ans,q[10005][10005]; 
double s; 
int main(){
	freopen("detect.in","r",stdin); 
	freopen("detect.out","w",stdout); 
	cin>>t; 
	for(int i=1; i<=t; i++){
		cin>>n>>m>>c>>x;  
		for(int j=1; j<=n; j++) cin>>d[j]>>v[j]>>a[j]; 
		for(int j=1; j<=m; j++) cin>>p[j]; 
		for(int j=1; j<=n; j++){
			s=((v[j]+a[j])*(v[j]+a[j])-v[j]*v[j])*1.0/(2*a[j]); 
			if(a[j]==0 && v[j]>3)
			{
				for(int k=1; k<=m; k++){
					if(d[j]<p[k])
					{
						ans+=1; 
						for(int z=k; z<=m; z++){
							q[j][z-k+1]=p[z]; 
						}
						break; 
					}
				}
			}
			if(a[j]>0)
			{
				if(v[j]<=x) for(int k=1; k<=m; k++){
					if(d[j]*1.0+s<p[k]*1.0)
					{
						ans+=1; 
						for(int z=k; z<=m; z++){
							q[j][z-k+1]=p[z]; 
						}
						break; 
					}
				}
				else{
					ans+=1; 
					for(int k=1; k<=m; k++){
						if(d[j]<p[k]){
							for(int z=k; z<=m; z++){
								q[j][z-k+1]=p[z]; 
							}
						}
						break; 
					}
				}
			}
			if(a[j]<0){
				for(int k=1; k<=m; k++){
					if(d[j]*1.0+s>p[k]*1.0 && d[j]<p[k])
					{
						ans+=1; 
						for(int z=k; z<=m; z++){
							if(d[j]*1.0+s>p[z]*1.0 && d[j]<p[z]) q[j][z-k+1]=p[z]; 
						}
						break; 
					}
				}
			}
		}
		cout<<ans<<" "<<m-2; 
	}
	fclose(stdin); 
	fclose(stdout); 
	return 0; 
}
