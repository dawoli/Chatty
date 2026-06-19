#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
struct c{
	int d,v,a,e;
}car[100005];
bool cmp(c x,c y){
	return x.d<y.d;
}
int p[100005];
bool vis[10005][10005];
struct po{
	int num,id;
}vis2[100005];
bool cmp2(po x,po y){
	return x.num<y.num;
}
int f(int wc,int wp){
	int e=car[wc].d;
	for(int v=car[wc].v,i=0;e<=wp;v+=car[wc].a,i++){
		e+=v;
		if(e>=p[wp]) {
			return e;
		}
	}
} 
bool f2(int wc,int wp){
	for(int i=1;i<=m;i++){
		if(vis[wc][i]&&i!=wp){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				vis[i][j]=false;
			}
		}
		for(int i=1;i<=n;i++){
			int e;
			cin>>car[i].d>>car[i].v>>car[i].a;
			if(car[i].a>=0)	car[i].e=L;
			else {
				e=car[i].d;
				for(int v=car[i].v;v>=0;v+=car[i].a){
					e+=v;
				}
				car[i].e=e;
			}
		} 
		sort(car+1,car+1+n,cmp);
		for(int i=1;i<=m;i++){
			cin>>p[i];
		} 
		for(int i=1;i<=n;i++){
			bool a=false;
			for(int j=1;j<=m;j++){
				if(car[i].d<=p[j]&&p[j]<=car[i].e){
					vis[i][j]=true;
					a=true;
				}
				else if(a) break;
			}
		}
		
		int ans1=0; 
		for(int i=1;i<=n;i++){
			if(car[i].a==0){
				if(car[i].v>V){
					for(int j=1;j<=m;j++){
						if(vis[i][j]){
							ans1++;
							break;
						} 
					}
				}
			}
			else if(car[i].a>0){
				for(int j=m;j>=1;j--){
					if(vis[i][j]&&V<double(sqrt(car[i].v*car[i].v+car[i].a*f(i,j)*2))){
						ans1++;
						break;
					}
					else if(vis[i][j]) vis[i][j]=false;
				}
			}
			else{
				for(int j=1;j<=m;j++){ 
					if(vis[i][j]&&V<double(sqrt(car[i].v*car[i].v+car[i].a*f(i,j)*2))){
						ans1++;
						break;
					}
					else if(vis[i][j]) vis[i][j]=false;
				}
			}
		} 
		cout<<ans1<<" ";
		int ans2=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(vis[j][i]) vis2[i].num++;
			}
			vis2[i].id=i;
		}
		sort(vis2+1,vis2+1+m,cmp2);
		for(int i=1;i<=m;i++){ 
			bool a=false;
			for(int j=1;j<=n;j++){
				if(f2(j,vis2[i].id)&&vis[j][vis2[i].id]){
					a=true;
				}
				else if(vis[j][vis2[i].id]){
					a=false;
					break;
				}
			}
			if(a) {
				for(int j=1;j<=n;j++) vis[j][vis2[i].id]=false;
				ans2++;
			}
		}	
		cout<<ans2<<endl;
	}
	return 0;
} 
