#include<bits/stdc++.h>
#define INF 100005
using namespace std;
int T,n,m,l,V,ans=0;
int d[INF],v[INF],a[INF],mnt[INF],con[INF];
bool s[INF];
void doit(){
	ans=0;
	cin>>n>>m>>l>>V;
	for(int i=1;i<=n;++i){
		cin>>d[i]>>v[i]>>a[i];
	}
	for(int i=1;i<=m;++i){
		cin>>mnt[i];
	}
	for(int i=1;i<=m;++i){
		s[i]=false;
	}
	for(int i=1;i<=n;++i){
		if(a[i]==0){
			if(v[i]>V){
				int tmp=-1; 
				bool flag=false;
				
				for(int j=1;j<=m;++j){
					if(mnt[j]>=d[i]){
						
						
						flag=true;
					
					    tmp=j;
					}
				}
				
				if(flag==true){
					s[tmp]=true;
					ans++;
				}
			}
		}else if(a[i]>0){
			double dis=(V*V-v[i]*v[i])/2/a[i];
			if(dis<0){
				int tmp=-1; 
				bool flag=false;
				for(int j=1;j<=m;++j){
					if(mnt[j]>=d[i]){
						
						flag=true;
						
					    tmp=j;
					}
			    
				}
				if(flag==true){
					s[tmp]=true;
					ans++;
				}
			}else if(dis==0){
				int tmp=-1; 
				bool flag=false;
				for(int j=1;j<=m;++j){
					if(mnt[j]>d[i]){
						flag=true;
						tmp=j;
					}
				}
				if(flag==true){
					s[tmp]=true;
					ans++;
				}
				
			}else{
				int tmp=-1; 
				bool flag=false;
				for(int j=1;j<=m;++j){
					if(mnt[j]>d[i]+dis){
						flag=true;
						tmp=j;
					}
				}
				if(flag==true){
					s[tmp]=true;
					ans++;
				}
			}
		}else{
			if(v[i]<=V){
				break;
			}else{
			    double dis=(V*V-v[i]*v[i])/2/a[i];
			    int tmp=-1; 
				bool flag=false;
			    for(int j=1;j<=m;++j){
					if(mnt[j]>=d[i]&&mnt[j]<d[i]+dis){
						flag=true;
						tmp=j;
					}
				}
				if(flag==true){
					s[tmp]=true;
					ans++;
				}
			}
			
			
		}
			
		
	}
	cout<<ans<<" ";
	int cl=0;
	for(int i=1;i<=m;++i){
		if(s[i]==false){
			cl++;
		}
	}
	cout<<cl<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int w=1;w<=T;++w){
		doit();
	} 
	return 0;
}
