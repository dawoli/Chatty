#include <bits/stdc++.h>

using namespace std;
struct nodeCar{
	int d;
	int v;
	int a;
	int overNum;
	double overL;
	double overR;
}Car[100001];
struct nodeyi{
	int overCar;
	int l;
}yi[100001];
int T;
int n,m,L,V;
bool carRest[100001];

bool cmp(nodeyi a,nodeyi b){
	return a.overCar>b.overCar;
}

bool cmp_1(nodeyi a,nodeyi b){
	return a.l<b.l;
}

/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(register int p=1;p<=T;p++){
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(register int i=1;i<=n;i++){
			scanf("%d%d%d",&Car[i].d,&Car[i].v,&Car[i].a);
		}
		for(register int i=1;i<=m;i++){
			scanf("%d",&yi[i].l);
			yi[i].overCar=0;
		}
		sort(yi+1,yi+1+m,cmp_1);
		
		//calculate
		int ansOver=0;
		for(register int i=1;i<=n;i++){
			if(Car[i].a==0){
				if(Car[i].v<=V){
					Car[i].overL=-1;
					Car[i].overR=-1;
					Car[i].overNum=0;
				} else{
					ansOver++;
					Car[i].overL=Car[i].d;
					Car[i].overR=L;
					Car[i].overNum=0;
					
					for(int j=1;j<=m;j++){
						if(yi[j].l>=Car[i].overL && yi[j].l<=Car[i].overR){
							Car[i].overNum++;
							yi[j].overCar++;
							//cout<<"3/"<<j;
						}
					}
				}
			} else if(Car[i].a>0){//a>0
				double Os=(abs(V*V-Car[i].v*Car[i].v))*1.0/(2*abs(Car[i].a));
				//cout<<"/"<<V*V<<"/"<<Car[i].d<<"/"<<Os<<endl;
				//cout<<i<<"/"<<Car[i].d<<"/"<<Car[i].v<<"/"<<Car[i].a<<endl;
				//cout<<"/"<<Os<<endl;
				Car[i].overL=Os+Car[i].d;
				Car[i].overNum=0;
				Car[i].overR=L;
				for(int j=1;j<=m;j++){
					if(yi[j].l>Car[i].overL){
						for(int k=j;k<=m;k++){
							Car[i].overNum++;
							yi[k].overCar++;
							//cout<<"2/"<<k;
						}
						break;
					}
				}
			} else{//a<0
				if(Car[i].v<=V){
					Car[i].overL=-1;
					Car[i].overR=-1;
					Car[i].overNum=0;
				} else{
					ansOver++;
					double Os=(abs(V*V-Car[i].v*Car[i].v))*1.0/(2.0*abs(Car[i].a));
					//cout<<"/"<<"/"<<"/"<<Os<<endl;
					
					//double Os=Car[i].v*(V-Car[i].v)*1.0/Car[i].a+(V-Car[i].v)*(V-Car[i].v)*1.0/2.0/Car[i].a;
					Car[i].overNum=0;
					Car[i].overL=Car[i].d;
					Car[i].overR=Car[i].d+Os;
					for(int j=1;j<=m;j++){
						if(yi[j].l>=Car[i].overL && yi[j].l<=Car[i].overR){
							for(int k=j;k<=m;k++){
								if(yi[k].l>=Car[i].overL && yi[k].l<Car[i].overR){
									yi[k].overCar++;
									Car[i].overNum++;
									//cout<<"1/"<<k;
								}
							}
							break;
						}
					}
				}
			}
		}
		
		cout<<ansOver<<" ";
		//delete
		
		int ansDelete=0;
		/*for(int i=1;i<=n;i++){
			if(Car[i].overNum == 1){
				for(int j=1;j<=m;j++){
					if(Car[i].overL<=yi[j].l && yi[j].l<=Car[i].overR){
						ansDelete++;
						//清空测速仪及相关测速仪超速点 
						for(int k=1;k<=n;k++){
							if(Car[k].overL<=yi[j].l && yi[j].l<=Car[k].overR){//Car[k] over
								for(int h=1;h<=m;h++){
									if(Car[k].overL<=yi[h].l && yi[h].l<=Car[k].overR){
										yi[h].overCar--;
									}
								}
							}
						}
						//
						yi[j].overCar=0;
					}
				}
			}
		}//唯一 */
		
		/*for(int i=1;i<=m;i++){
			cout<<i<<" "<<yi[i].overCar<<endl;
		}*/
		
		int maxYi=1;
		for(int i=2;i<=m;i++){
			if(yi[i].overCar>yi[maxYi].overCar){
				maxYi=i;
			}
		}
		while(yi[maxYi].overCar>0){
			ansDelete++;
			//清空测速仪及相关测速仪超速点 
			for(int k=1;k<=n;k++){
				if(Car[k].overL<=yi[maxYi].l && yi[maxYi].l<=Car[k].overR){//Car[k] in maxYi over
					for(int h=1;h<=m;h++){
						if(Car[k].a<0){
							if(Car[k].overL<=yi[h].l && yi[h].l<Car[k].overR){
								yi[h].overCar--;
							}
						} else if(Car[k].overL<=yi[h].l && yi[h].l<Car[k].overR){
							yi[h].overCar--;
						}
					}
				}
			}
			yi[maxYi].overCar=0;
			//
			maxYi=1;
			for(int i=2;i<=m;i++){
				if(yi[i].overCar>yi[maxYi].overCar){
					maxYi=i;
				}
			}
		}
		
		cout<<ansDelete<<endl;
		/*for(int i=1;i<=n;i++){
			cout<<Car[i].overL<<" "<<Car[i].overR<<" "<<Car[i].overNum<<endl;
		}*/
	}
	return 0;
}
