#include<bits/stdc++.h>
using namespace std;
//char a[4][5];
int main(){
	int T; //多少组数据
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	int ansList[T];
	for (int operation=0;operation<T;operation++){
		long long int n, m;
		long long int k; //n&m地图行数列数，k是机器人操作次数
		int x0, y0, d0; //机器人位置，d是方向
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		int map[n][m];
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				char input;
				cin>>input;
				if(input=='x'){
					map[i][j]=2; //有障碍物 
				}
				else{
					map[i][j]=0;
				} 
			}
		}
		x0-=1;
		y0-=1;
		map[x0][y0]=1;
		const long long movement =k;
		for (long long int move=0;;move++){
			if (move==k) break;
			if (d0==0){
				if (y0+1<m){
					if (map[x0][y0+1]!=2){
						y0+=1;
						map[x0][y0]=1; //走过了 
					}
					else{d0=(d0+1)%4;}
				}
				else{d0=(d0+1)%4;}
			}
			else if(d0==1){
				if (x0+1<n){
					if (map[x0+1][y0]!=2){
						x0+=1;
						map[x0][y0]=1; 
					}
					else{d0=(d0+1)%4;}
				}
				else{d0=(d0+1)%4;}
			}
			else if(d0==2){
				if (y0-1>=0){
					if (map[x0][y0-1]!=2){
						y0-=1;
						map[x0][y0]=1; 
					}
					else{d0=(d0+1)%4;}
				}
				else{d0=(d0+1)%4;}
			}
			else{
				if (x0-1>=0){
					if (map[x0-1][y0]!=2){
						x0-=1;
						map[x0][y0]=1;
					}
					else{d0=(d0+1)%4;}
				}
				else{d0=(d0+1)%4;}
			}
		}
		int cnt=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if(map[i][j]==1){ cnt+=1;}
			}
		}
		ansList[operation]=cnt;
		}
	for (int finall=0;finall<T;finall++){
		cout<<ansList[finall];
		if (finall!=T-1) cout<<"\n";
	}
	return 0;
}
