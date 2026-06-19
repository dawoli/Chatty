#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int N=100100;
struct node{
	int b,v,a;
};
int dt[N][2];
node c[N];
int p[N];
int T,n,m,L,V,cnt,ans,pos;
double move;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cnt=ans=0;
		memset(dt,0,sizeof(dt));
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++)cin>>c[i].b>>c[i].v>>c[i].a;
		for(int i=0;i<m;i++)cin>>p[i];
		for(int i=0;i<n;i++){
			if(!c[i].a){
				if(c[i].v>V){
					for(int j=m-1;j>=0;j--){
						if(p[j]>=c[i].b){
							cnt++;
							dt[i][0]=c[i].b,dt[i][1]=L;
						}
						else dt[i][0]=dt[i][1]=-1;
						break;
					}
				}
				else{
					dt[i][0]=dt[i][1]=-1;
				}
			}
			else if(c[i].a>0){
				move=(V*V-c[i].v*c[i].v)/(2.0*c[i].a);
				pos=ceil(move+c[i].b+0.001);
				if(pos>L){
					dt[i][0]=dt[i][1]=-1;
				}
				else{
					for(int j=m-1;j>=0;j--){
						if(p[j]>=pos){
							cnt++;
							dt[i][0]=pos,dt[i][1]=L;
						}
						else dt[i][0]=dt[i][1]=-1;
						break;
					}
				}
			}
			else{
				if(c[i].b<=V){
					dt[i][0]=dt[i][1]=-1;
				}
				else{
					move=(c[i].v*c[i].v-V*V)/(-2.0*c[i].a);
					pos=floor(c[i].b+move-0.001);
					bool f=1;
					for(int j=m-1;j>=0;j--){
						if(pos>=p[j]&&p[j]>=c[i].b){
							cnt++,f=0;
							dt[i][0]=c[i].b,dt[i][1]=pos;
							break;
						}
						else if(p[j]<c[i].b){
							break;
						}
					}
					if(f)dt[i][0]=dt[i][1]=-1;
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
