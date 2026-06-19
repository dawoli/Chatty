#include <bits/stdc++.h>
using namespace std;
int ex[1000100]={0};
struct Node{
	int d,v,a; //位置,初速度,加速度 
}car[1000100];
int n,m,L,V; //车辆数量,测速仪数量,主干道长度,道路限速
int flag=0;// 0=到get_inV后超速,1=到get_inV前超速,2=一直超速,3=一直不超速
int get_inV(int pos){
	if(car[pos].a<=0&&car[pos].v<=V){
		flag=3;
		return 0;
	}
	else if(car[pos].a>=0&&car[pos].v>V){
		flag=2;
		return car[pos].d;
	}
	int mole=V*V-car[pos].v*car[pos].v;
	int deno=2*car[pos].a;
	if(car[pos].v>V)flag=1;
	else if(car[pos].v<V)flag=0;
	if(mole%deno==0)return car[pos].d+mole/deno;
	else return car[pos].d+mole/deno+1;
}
int get_end(int pos){
	if(car[pos].a>=0)return L;
	else{
		int mole=0*0-car[pos].v*car[pos].v;
		int deno=2*car[pos].a;
		return car[pos].d+mole/deno;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>car[i].d>>car[i].v>>car[i].a;
		}
		for(int i=1;i<=m;i++)
			cin>>ex[i];
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++){
			int hefa=min(L,get_inV(i));
			int Leave=min(L,get_end(i));
			if(flag==3)continue;
			if(flag==1){
				for(int j=1;j<=m;j++){
					if(ex[j]>=car[i].d&&ex[j]<hefa){
						ans1++;
						break;
					}
				}
			}else{
				for(int j=1;j<=m;j++){
					if(ex[j]>hefa&&ex[j]<=Leave){
						ans1++;
						break;
					}
				}
			}
		}
		cout<<ans1<<" "<<m<<endl;
	}
	return 0;
}
