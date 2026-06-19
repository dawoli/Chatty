#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int T;
int n,m,L,V;
struct carset{
	int d;
	int v;
	int a;
}car[N];
int csy[N];
int flag[N];
int cs_num,no_use_csy;


//测速：超过最大速度 or not 超速车辆+=1; 
void cesu(int m2,int car_num ,int Lmax ,int Vmax){
	if(car[car_num].a==0){
		if(car[car_num].v >=Vmax){
			cs_num+=1;
		}
	}
	else if(car[car_num].a>0){
		double Vlst=sqrt(car[car_num].v*car[car_num].v+2*car[car_num].a*(Lmax-car[car_num].d));
		if(Vlst>=Vmax){
			double s=(Vmax*Vmax-car[car_num].v*car[car_num].v)/(car[car_num].a*2.0);
			for(int i=m2;i>=1;i--){
				if(csy[i]>(s+car[car_num].d)){
					cs_num+=1;
//					flag[i]=1;
					break;
				}
			}
		}
	}
	else if(car[car_num].a<0){
		if(car[car_num].v>=Vmax){
			double s=(Vmax*Vmax-car[car_num].v*car[car_num].v)/(car[car_num].a*2.0);
			for(int i=m2;i>=1;i--){
				if((csy[i]<(s+car[car_num].d))&&(csy[i]>car[car_num].d)){
//					flag[i]=1;
					cs_num+=1;
					break;
				}
			}
		}
	}
	
}
	
	
//超速：最大速度之后被测到的测速仪flag=1; 

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	//输入区 
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>L>>V;
		for(int r1=1;r1<=n;r1++){
			cin>>car[r1].d>>car[r1].v>>car[r1].a;
		}
		for(int r2=1;r2<=m;r2++){
			cin>>csy[r2];
		}
		cs_num=0;
		no_use_csy=0;
		for(int r1=1;r1<=n;r1++){
			cesu(m,r1,L,V);	
		}
		//chaosu();
	
		if((car[1].a==0)&&cs_num!=0) no_use_csy=m-1;
		if((car[1].a>0)&&cs_num!=0) no_use_csy=m-1;
		if(cs_num==0) no_use_csy=m;
		cout<<cs_num<<' '<<no_use_csy<<endl;
	}

	return 0;
}
