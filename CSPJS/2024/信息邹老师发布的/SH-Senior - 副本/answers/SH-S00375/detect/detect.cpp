#include<bits/stdc++.h>
using namespace std;
#define MAXN 100007
int n,m,l,vmax;
int d[MAXN],v[MAXN],a[MAXN];
int p[MAXN];
struct Car{
	int start,ende; //closed
	short status;//0:plain 1:endless 2:stageous
	int ps,pe;
	Car(int start,int ende,short status){
		this->start=start;
		this->ende=ende;
		this->status=status; 
		this->ps=this->pe=0;
	}
	bool operator<(Car b){
		return this->start<b.start; 
	}
}car[MAXN]=Car(0,0,0);

int T;
//int ceiling(double x){
//	if(x-(int)x) return int(x)+1;
//	return (int)x+1;
//}
bool simpleSolution1=true;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		scanf("%d%d%d%d",&n,&m,&l,&vmax);
		for(int i=1;i<=n;i++) scanf("%d%d%d",d+i,v+i,a+i);
		for(int i=1;i<=m;i++) scanf("%d",p+i);
		for(int i=1;i<=n;i++){ //
			int di,vi,ai;
			di=d[i];vi=v[i];ai=a[i];
			if(ai==0){ //constant velocity
				if(vi>vmax) car[i]=Car(di,l,1);//exceeding vmax
				else car[i]=Car(l+1,-1,0);//not exceeding vmax
			}
			else if(ai>0){ //accelerating
				if(vi>vmax) car[i]=Car(di,l,1);//exceeds when beginning
				else{ //good beginning
					if(vi*vi+2*ai*(l-di)<=vmax*vmax) car[i]=Car(l+1,-1,0);//never reaches vmax
					else{ //exceeds some time
						double x=(vmax*vmax-vi*vi)*1.00/(2*ai);
						car[i]=Car(di+int(x)+1,l,1);
					}
				}
			}
			else{ //decelerating
				if(vi<=vmax) car[i]=Car(l+1,-1,0);//good beginning
				else{ //evil beginning
					if(vi*vi+2*ai*(l-di)>vmax*vmax) car[i]=Car(di,l,1);//never justifies
					else{ //turns good some time
						double x=(vmax*vmax-vi*vi)*1.00/(2*ai);
						car[i]=Car(di,di+(x==(int)x?(int)x-1:(int)x),2);
						simpleSolution1=false;
					}
				}
			}
		}
		if(simpleSolution1){
			int ans=0;
			int chosenP=p[m];
			for(int i=1;i<=n;i++){
				if(car[i].status==0) continue;
				else{
					if(chosenP>=car[i].start) ans++;
				}
			}
			printf("%d %d\n",ans,m-1);
		}
		else{
			sort(car+1,car+n);
			int curj=1;
			int ans1=0,ans2=0;
			for(int i=1;i<=n;i++){
				if(car[i].status==0) continue;
				bool detected=false,isStart=true;
				for(int j=1;j<=m;j++){
					if(p[j]>=car[i].start&&p[j]<=car[i].ende){
						detected=true;
						if(isStart) {
							car[i].ps=j;
							isStart=false;
						}
					}
					if(p[j]>car[i].ende){
						car[i].pe=j-1;
						break;
					}
				}
				if(car[i].pe==0) car[i].pe=n;
				ans1+=detected;
			}
			printf("%d %d\n",ans1,ans2);
		}
	}
	return 0;
}
