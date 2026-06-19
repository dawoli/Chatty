#include<bits/stdc++.h>
using namespace std;
int T,ans1,ans2;
struct node{
	int d,v0,a;
}che[100007];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		ans1=0,ans2=0;
		for(int i=1;i<=100007;i++){
			che[i].d =0;
			che[i].v0=0;
			che[i].a =0;
		}
		int n,m,l,v;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>che[i].d>>che[i].v0>>che[i].a ;
		}
		int tong[1000007]={0};//哪里有检测仪 
		int temp;
		for(int j=1;j<=m;j++){
			cin>>temp;
			tong[temp]++;
		}
		int s[1000007]={0};//0到i有多少个检测仪 
		s[0]=tong[0]; 
		for(int i=1;i<=l;i++){
			s[i]=s[i-1]+tong[i];
		}
		bool p[1000007]={0};//哪个检测仪必须开着 
		for(int i=1;i<=n;i++){
			if(che[i].a>0){
				float x=0;//超速位置
				x=che[i].d+(v*v-che[i].v0 *che[i].v0 )/(che[i].a *2);
				int y=ceil(x);
				if(y<=l && s[l]-s[y]>0){
					ans1++;
					bool flag=1;//要不要加上一座 
					for(int k=y;k<=l;k++){
						if(p[k]==1){
							flag=0;
							break;
						}
					}
					if(flag){
						for(int k=y;k<=l;k++){
							p[k]=1;
						}
						ans2--;
					}
				}		
			}else if(che[i].a==0){
				if(che[i].v0<=v){
					continue;
				}else{
					if(s[l]-s[che[i].d]>0){
						ans1++;
						bool flag=1;//要不要加上一座 
						for(int k=che[i].d ;k<=l;k++){
							if(p[k]){
								flag=0;
								break;
							}
						}
						if(flag){
							for(int k=che[i].d ;k<=l;k++){
								p[k]=true;
							}
							ans2--;
						}	
					}
				}
			}else if(che[i].a<0){
				if(che[i].v0 <v){
					continue;
				}else{
					float x=0;//不超速位置
					x=che[i].d + (che[i].v0 *che[i].v0-v*v ) / abs(che[i].a *2);
					int y=floor(x);
					if(s[y]-s[che[i].d]>0){
						ans1++;
						bool flag=1;//要不要加上一座 
						for(int k=che[i].d ;k<=y;k++){
							if(p[k]==1){
								flag=0;
								break;
							}
						}
						if(flag){
							for(int k=che[i].d ;k<=y;k++){
								p[k]=1;
							}
							ans2--;
						}	
					}
					
				}
			}	
		}
		ans2+=m;
		cout<<ans1<<" "<<ans2<<"\n";
	}
	return 0;
}
