#include <iostream>

using namespace std;

bool map_status[1005][1005], discovery_status[1005][1005]={0};
int mapx,mapy,num,direction,posx,posy,ans[10];

bool ablemove(int mapx,int mapy,int posx,int posy,int direction,bool right,bool bottom,bool left,bool top){
	if(direction==0 && (posy==mapy||(right&&posy!=mapy)))return 0;
	if(direction==1 && (posx==mapx||(bottom&&posx!=mapx)))return 0;
	if(direction==2 && (posy==1||(left&&posy!=1)))return 0;
	if(direction==3 && (posx==1||(top&&posx!=1)))return 0;
	return 1;
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	for(int k=1;k<=T;k++){
		cin >> mapx >> mapy >> num;
		cin >> posx >> posy >> direction;
		for(int i=1;i<=mapx;i++){
			char a[1005];
			cin >> a;
			for(int j=1;j<=mapy;j++){
				if(a[j-1]=='x'){
					map_status[i][j]=1;
				}else{
					map_status[i][j]=0;
				}
			}
		}//fill map cin done
		for(int i=1;i<=1005;i++){
			for(int j=1;j<+1005;j++){
				discovery_status[i][j]=0;
			}
		}//reset discovery
		discovery_status[posx][posy]=1;//orig pos
		for(int i=1;i<=num;i++){
			if(ablemove(mapx,mapy,posx,posy,direction,map_status[posx][posy+1],map_status[posx+1][posy],map_status[posx][posy-1],map_status[posx-1][posy])){
				if(direction==0)posy++;
				if(direction==1)posx++;
				if(direction==2)posy--;
				if(direction==3)posx--; 
			}else{
				direction++;
				if(direction==4)direction=0;
			}
			discovery_status[posx][posy]=1;
		}
		for(int i=1;i<=mapx;i++){
			for(int j=1;j<=mapy;j++){
				if(discovery_status[i][j]==1)ans[k]++;
			}
		}//record ans	
	}
	for(int i=1;i<=T;i++){
		cout << ans[i] << endl;
	}
	return 0;
} 
