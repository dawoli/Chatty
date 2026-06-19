#include<iostream>
using namespace std;
int T;
int n,m,L,V;
const int N=1e5+10;
struct car{
	int d,v,a;
};
bool sudu(car c,int x){//判断是否超速 
	if(c.d>x)return 0;//在测速仪之后进入 
	int v2=c.v*c.v+2*c.a*(x-c.d);
	if(v2>V*V)return 1;//超速 
	return 0;
}
int guan(car cars[],int sum,int yi[]){
	struct cesuyi{
		int c[N],len;
	}yis[N];
	for(int j=0;j<m;j++){
		for(int i=0;i<=n;i++){
			if(sudu(cars[i],yi[j])){
				yis[j].c[yis[j].len]=i;
				yis[j].len++;
			}
		}
	}
	return sum;
}
int main(){
	cin>>T;
	while(T--){
		car cars[N];
		int cesu[N];
		int chaosu=0;
		car csuc[N];
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			cin>>cars[i].d>>cars[i].v>>cars[i].a;
		}
		for(int i=0;i<m;i++){
			cin>>cesu[i];
		}
		for(int i=0;i<n;i++){
			bool cs=0;
			for(int j=0;j<m;j++){
				if(sudu(cars[i],cesu[j])){
					cs=1;
				}
			}
			if(cs)chaosu++;
		}
		int guanbi=guan(cars,chaosu,cesu);
		cout<<chaosu<<" "<<guanbi<<endl;
		
	}
	return 0;
}
