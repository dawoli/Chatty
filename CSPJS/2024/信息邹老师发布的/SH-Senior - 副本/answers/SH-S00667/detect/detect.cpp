# include<bits/stdc++.h>
using namespace std;
int T; //有多少辆车子

int main(){
	cin >> T;
	for (int i=0;i<T;i++){
		int n, m, L, V;
		cin>>n>>m>>L>>V;  //n车数，m测速仪数，L主干长度，V道路限速
		int carL[n][4];
		for (int j=0;j<n;j++){
			int di, vi, ai;
			cin>>di>>vi>>ai;
			carL[j][0]=di;
			carL[j][1]=vi;
			carL[j][2]=ai;
			carL[j][3]=0;
		}
		//for (int a=0;a<n;a++){
		//	for (int b=0;b<3;b++){
		//		cout<<carL[a][b];
		//	}
		//	cout<<endl;
		//}
		int cesuL[m];
		for (int k=0;k<m;k++){
			cin>>cesuL[k];
			cout<<cesuL[k];
		} 
		int flags[n][15];
		//for (int a=0;a<m;a++){
		//	cout<<cesuL[a];}
		// 计算每个车超速的区间
		for (int j=0;j<n;j++) {
			int overSpdStart;
			int overSpdEnd;
			if (carL[j][2]>0){
				if (carL[j][1]>3){
					overSpdStart=carL[j][0];
					overSpdEnd=L;
				}
				else{
					double ticketD;
					ticketD = double ((9-pow(carL[j][1],2))/(2*carL[j][2])+carL[j][0]);
					overSpdStart = ceil(ticketD)+1;
					overSpdEnd = L;
					
				}
			}
			else if(carL[j][2]==0){
				if (carL[j][1]>3){
					overSpdStart=carL[j][0];
					overSpdEnd=L;
				}
				else{
					overSpdStart=carL[j][0];
					overSpdEnd=carL[j][0];
				}
			}
			else{
				if (carL[j][1]>3){
					double ticketD;
					ticketD = double ((9-pow(carL[j][1],2))/(2*carL[j][2]));
					overSpdStart = carL[j][0];
					overSpdEnd = floor(carL[j][0]+ticketD);
				}
				else{
					overSpdStart=0;
					overSpdEnd=0;
				}
			}
			for (int start=overSpdStart;start<=overSpdEnd;start++){
				flags[j][start]=1;
				cout<<start<<' ';
			}
		}
		for(int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				if (flags[j][cesuL[i]]==1){
					cout<<"超速了！！！"<<j<<"检测by"<<cesuL[i]; 
				}
			}
			
		}
        
		}
	return 0;
} 
