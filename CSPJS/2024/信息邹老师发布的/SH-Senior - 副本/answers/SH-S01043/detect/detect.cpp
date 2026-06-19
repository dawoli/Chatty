#include<bits/stdc++.h>
using namespace std;



int t,n,m,l,v;
struct cars{
	int pos;
	int speed;
	int addspeed;
	double chaosux;
	double chaosuy;
	bool ischaosu;
};

cars a[100020];
int b[100020];


int main(){
	
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>l>>v;
		int chaosucarnum=0;
		for(int j=0;j<n;j++){
			cin>>a[j].pos>>a[j].speed>>a[j].addspeed;
			if(a[j].addspeed>=0){
				if(a[j].speed>v){
				}
				else{
					if(a[j].speed<=v and a[j].addspeed==0){
					}else{				
						double t=(v-a[j].speed)*1.0/a[j].speed;
						a[j].chaosux=a[j].pos*a[j].speed+0.5*a[j].addspeed*t*t;	
						if(a[j].chaosux>l){
							a[j].ischaosu=0;
						}else{
							a[j].ischaosu=1;
							a[j].chaosuy=l;
						}
					}
				}
			}
			else{
				if(a[j].speed>v){
					a[j].ischaosu=1;
					a[j].chaosux=a[j].pos;
					double temp=(a[j].speed-v)/abs(a[j].addspeed);
					a[j].chaosuy=a[j].speed*temp+0.5*abs(a[j].addspeed)*t*t;
				}else{
					a[j].ischaosu=0;
				}
			}
			
		}
		for(int j=0;j<m;j++){
			cin>>b[j];
		}
		int re=0;
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(   )
			}
		}
		cout<<chaosucarnum<<endl;
	}
	
	
	
	return 0;
}







//1
//5 5 15 3
//0 3 0
//12 4 0
//1 1 4
//5 5 -2
//6 4 -4
//2 5 8 9 15


 
