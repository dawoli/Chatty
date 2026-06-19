#include<bits/stdc++.h>
using namespace std;
struct node{
	int v;
	int a;
	int d;
};

struct whe{
	int start=-1;
	int end;
};

int T;
int n,m,L,V;
int kaians=0,ans=0;
int p[100005];
whe must[100005];   //2:他及到最后的测速仪选一个开   1:这个测速仪还是超速，下一个不一定 
node car[100005];

int target=0;//最近的测速仪是第几号 

int main(){
	freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout); 
	cin>>T;
	while(T--){
		target=0,kaians=0,ans=0;
		memset(must,0,sizeof(must));
		memset(car,0,sizeof(car));
		memset(p,0,sizeof(p));
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			cin>>car[i].d>>car[i].v>>car[i].a;
		}
		for(int i=0;i<m;i++){
			cin>>p[i];
		}
		
		for(int i=0;i<n;i++){
			target=0;
			if(car[i].v<=V){
				if(car[i].a<=0){
					continue;
				}
				else{
					target=114514;
					for(int j=0;j<m;j++){//寻找最近的测速仪 
						if(p[j]>=car[i].d){
							target=j;
							break;
						}
					}
					if(target==114514){
						continue;
					}
					
					float vthere=0;
					for(int z=target;z<m;z++){
						vthere=sqrt(car[i].v*car[i].v+2*car[i].a*(p[z]-car[i].d));
						if(vthere>(float)V){
							kaians++;
							must[z].start=z;
							must[z].end=-1;
							break; 
						}
						
					}
					
				}
			}
			else if(car[i].v>V){
				if(car[i].a<0){
					target=114514;
					for(int j=0;j<m;j++){//寻找最近的测速仪 
						if(p[j]>=car[i].d){
							target=j;
							break;
						}
					}
					if(target==114514){
						continue;
					}
					
					float vthere=0,tthere=0;
					for(int j=target;j<m;j++){
						vthere=sqrt(car[i].v*car[i].v-2*(-1)*car[i].a*(p[j]-car[i].d));
						if(vthere>(float)V){//到这个还是超速，下一个不一定 
							kaians++;
							must[j].start=j;
						}
						break; 
					}
					for(int j=target+1;j<m;j++){
						vthere=sqrt(car[i].v*car[i].v-2*(-1)*car[i].a*(p[j]-car[i].d));
						if(vthere>(float)V){//到这个还是超速，下一个不一定 
							continue;
						}
						else{
							must[target].end=j-1;
							break;
						}
					}
					
				}
				else{
					target=114514;
					for(int j=0;j<m;j++){//寻找最近的测速仪 
						if(p[j]>=car[i].d){
							target=j;
							break;
						}
					}
					if(target==114514){
						continue;
					}
					kaians++;
					must[target].start=target;
					must[target].end=-1;
					
					
				}
			}
		}
		cout<<kaians<<" ";
		
		
		if(car[0].a==0){
			cout<<m-ans-1<<endl;
		}
		
		if(car[0].a>0){
			cout<<m-ans-1<<endl;
		}
		
	}
	return 0;
}
