#include <cstdio>
using namespace std;

const int N = 1e3+10;
int n, m, k, d, pos[2], T;
char tmp, tstr[N];
int step[4][2];
int MAP[N][N]={0};
int anss[5];

bool isAct(int x, int y)
{
	if (x>n || y>m || x<1 || y<1) return false;
	if (MAP[x][y]==0) return false;
	return true;
}

int move()
{
	int res=1;
	MAP[pos[0]][pos[1]] = -1;
	while (k>0) {
		if (isAct(pos[0]+step[d][0], pos[1]+step[d][1])) {
			pos[0] += step[d][0];
			pos[1] += step[d][1];
			if (MAP[pos[0]][pos[1]]==1) {
				res++;
				MAP[pos[0]][pos[1]]=-1;
			}
		}
		else d = (d+1)%4;
		k--;
	}
	return res;
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	step[0][0]=0; step[0][1]=1; step[1][0]=1; step[1][1]=0; step[2][0]=0; step[2][1]=-1; step[3][0]=-1; step[3][1]=0;
	scanf("%d", &T);
	for (int i=0; i<T; i++)
	{
		scanf("%d %d %d", &n, &m, &k);
		scanf("%d %d %d", pos, pos+1, &d); 
		for (int x=1; x<=n; x++) {
			scanf("%s", tstr);
			for (int y=1; y<=m; y++) {
				tmp = tstr[y-1];
				MAP[x][y] = (tmp=='.') ? 1 : 0;
			}
		}
		anss[i] = move();
	}
	for (int i=0; i<T; i++)
		printf("%d\n", anss[i]);
	return 0;
}
