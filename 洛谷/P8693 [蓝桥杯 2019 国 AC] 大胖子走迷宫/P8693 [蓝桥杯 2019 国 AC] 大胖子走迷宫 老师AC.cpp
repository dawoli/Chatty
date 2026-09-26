#include <bits/stdc++.h>
using namespace std;

const int N = 310;

int n,k;
char a[N][N];
int d[N][N];
// 四个方向：右、左、下、上
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

/**
 * 检查以(x,y)为中心，半径size的正方形区域是否全部空地、不出界，且该点未访问
 *  x 中心点行坐标
 *  y 中心点列坐标
 *  size 半径：2代表5*5，1代表3*3，0代表1*1
 * return true 合法；false 有障碍/出界/已经访问过
 */
bool check(int x,int y,int size){
	// d[x][y]!=-1 代表这个坐标已经来过，不再重复入队
	if(d[x][y]!=-1) return false;
	// 遍历正方形所有格子
	for(int i=x-size;i<=x+size;i++){
		for(int j=y-size;j<=y+size;j++){
			// 碰到墙*，或者越界，直接不合法
			if(a[i][j]=='*'||i < 1 || i > n || j < 1 || j > n ){
				return false;
			}
		}
	}
	return true;
}

/*
 * 根据当前时间Time，返回对应的胖子半径size
 * Time <k     → 半径2，体型5×5
 * k ≤ Time <2k → 半径1，体型3×3
 * Time ≥2k    → 半径0，体型1×1
 */
int work(int Time)
{
	if(Time < k)	return 2;
	else if(Time < 2 * k)	return 1;
	else	return 0;
}

int bfs(){
	// 4个队列并行，分别存 x坐标，y坐标，时间，半径size
	queue<int> q[4];
	// 起点：(3,3)，时间0，半径2（5*5大胖子）
	q[0].push(3);
	q[1].push(3);
	q[2].push(0);
	q[3].push(2);
	// d数组标记该坐标是否被访问，初始-1代表未访问
	memset(d,-1,sizeof d);
	d[3][3]=0;

	while(!q[0].empty()){
		// 取出队首状态
		int tx=q[0].front();
		int ty=q[1].front();
		int tt=q[2].front();// 当前已经花费的时间
		int t=q[3].front();// 当前状态的半径（体型大小）
		q[0].pop(); q[1].pop(); q[2].pop(); q[3].pop();

		// 到达终点(n-2,n-2)，直接返回所用时间tt
		if(tx==n-2&&ty==n-2){
			return tt;
		}

		// 如果当前体型不是最小（t!=0，不是1*1），可以原地等待一步
		// 等待后时间+1，体型由新时间tt+1重新计算
		if(t!=0){
			q[0].push(tx); q[1].push(ty); q[2].push(tt+1); q[3].push(work(tt+1));
		}

		// 遍历4个移动方向
		for(int i=0;i<4;i++){
			int xx=tx+dx[i];
			int yy=ty+dy[i];
			// check：新坐标在当前体型t下合法，并且没访问过
			if(check(xx,yy,t)){
				d[xx][yy]=0;        // 标记这个点已经访问，防止重复入队
				q[0].push(xx);
				q[1].push(yy);
				q[2].push(tt+1);
				q[3].push(work(tt+1));// 移动一步后时间+1，用新时间计算新体型
			}
		}	
	}
}

int main()
{
	cin >> n >> k;
	// 读入地图
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	cout << bfs() <<endl;
	return 0;
}