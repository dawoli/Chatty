#include<bits/stdc++.h>
using namespace std;
int num,mun,Long,Verb,sum=0,cum=0,car,up,ki;
int dis[100002],ver[100002],av[100002],st[100002];
int summ[21],suum[21];
short int diis[10001][10001];
void Over(int d,int v,int a){
	double s,e;
	if(v>Verb){
		if(a>=0){
			s=d;e=Long;
		}else{
			s=d;e=d+abs(((Verb*Verb)-(v*v))/(a*2))-0.01;
		}
	}else{
		if(a<=0){
			return;
		}else{
			s=d+abs(((Verb*Verb)-(v*v))/(a*2))+0.01;e=Long;
		}
	}
	int su=0;
	for(int i=1;i<=mun;i++){
		if((st[i]>=s)&&(st[i]<=e)){
			diis[i][car]=1;su=1;
		}
	}
	sum+=su;
}
void deuxki(int i,int ii){
	for(int k=1;k<=num;k++){
		if(diis[i][1]==2)	return;
		if((diis[i][k]==diis[ii][k])||((diis[i][k]==1)&&(diis[ii][k]==0))){
			up++;
		}
		else{
			return;
		}
	}
	if(up==num){
		diis[ii][1]=2;
		deuxki(i,ii+1);
		ki++;
	}
}
void death(){
	ki=0;
	for(int i=1;i<=mun;i++){
		up=0;
		for(int j=1;j<=num;j++){
			if(diis[i][j]==0){
				up++;
			}
			else{break;}
		}
		if(up==num){
			ki++;continue;
		}
		up=0;
		deuxki(i,i+1);
	}
	mun=ki;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d%d%d%d",&num,&mun,&Long,&Verb);
		for(int a=1;a<=num;a++){scanf("%d%d%d",&dis[a],&ver[a],&av[a]);
		}
		for(int a=1;a<=mun;a++){scanf("%d",&st[a]);
		}
		for(int a=1;a<=num;a++){
			car=a;
			Over(dis[a],ver[a],av[a]);
		}
		death();
		summ[i]=sum;
		suum[i]=mun;
	}
	for(int i=1;i<=T;i++){
		printf("%d %d\n",summ[i],suum[i]);
	}
	return 0;
}
