#include <fstream>
using namespace std;
ifstream fin("explore.in");
ofstream fout("explore.out");
const int maxn=1005;
const int moveX[4]={0,1,0,-1},moveY[4]={1,0,-1,0};
bool map[maxn][maxn],reached[maxn][maxn];
int main(){
	int T;
	fin >> T;
	while (T--){
		int n,m,k;
		int x,y,d;
		fin >> n >> m >> k;
		fin >> x >> y >> d;
		reached[x][y]=1;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				char c;
				fin >> c;
				if (c=='x')
					map[i][j]=1;
			}
		}
		int ans=1;
		while (k--){
			int newX=x+moveX[d],newY=y+moveY[d];
			if (1<=newX and newX<=n and 1<=newY and newY<=m and map[newX][newY]==0){
				x=newX;
				y=newY;
				if (!reached[x][y]){
					reached[x][y]=1;
					ans++; 
				}
			}
			else
				d=(d+1)%4;
		}
		fout << ans << endl;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				map[i][j]=reached[i][j]=0;
	}
	return 0;
}
