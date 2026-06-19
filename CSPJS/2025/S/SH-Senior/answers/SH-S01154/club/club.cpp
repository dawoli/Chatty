#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
普及+提高 
*/

//struct chose{
//	int val=0, chosed[4]={0};
//};


const int MaxN = 1e5;
int a[6];//满意度 
//int chosed[MaxN][6][6];//表示dp[i][j]时，一二三选择项的数量 
//int dp[MaxN][4];
//dp[i][j]表示第i个学生选择第j项时，最大值 

//void solve(int n)
//{
//	int ans;
//	scanf("%d",&[1]);
//	scanf("%d",&[2]);
//	scanf("%d",&[3]);
//	for(int i = 1; i <= 3; i++)
//	{
//		dp[1][i] = a[i];
//		chosed[1][i][i]++;
//	} 
//	for(int i = 2; i <= n; i++)
//	{
//		for(int j = 1; j <= 3; j++)
//		{
////			dp[j] = max(dp[j], dp[j-v[i]] + c[i])
//			//上一个学生选择第一二三项的满意度并加上这一个的之后的值 
//			//如果上一个学生被选走了，是最后一个名额，那么就不能选，为0 
//			
//			for(int k = 1; k <= 3; k++)
//			{
//				
//			}
////			if(dp[i-1][1].chosed[1]<= n/2) 
////			chose1 = dp[i-1][j].val += a[1];
////			if(dp[i-1][2].chosed[2]<= n/2) 
////			chose2 = dp[i-1][j].val += a[2];
////			if(dp[i-1][2].chosed[2]<= n/2) 
////			chose3 = dp[i-1][j].val += a[3];
////			
////			maxv = max(chose1,max(chose2,chose3));
////			if(maxv==chose1)
////			{
////				chose1
////			}
//		}
//	}
//}
int chosed[4]={0};
int chos[MaxN];

int dfs(int depth, int chose, int maxdepth, int v)
{
	//第depth个学生，选择chose，其他选项的选择情况为chosed[4],值为v 
//	if(depth==1 and chose == 1)
//	cout << depth << " "<<chose<<" "<<maxdepth<<" "<<v<<endl;
//	if(depth==2 and chose == 3)
//	cout << depth << " "<<chose<<" "<<maxdepth<<" "<<v<<endl;
//	if(depth==3 and chose == 1)
//	cout << depth << " "<<chose<<" "<<maxdepth<<" "<<v<<endl;
	if(depth==4 and chose ==2)
	cout << depth << " "<<chose<<" "<<maxdepth<<" "<<v<<endl;
	if(chosed[chose]>maxdepth/2)
	{
		cout << "不合法\n";
		return -1;
	}
	v+=a[chose];
	if(depth>=maxdepth)
	{
		cout << v << endl;
		for(int i = 0; i <= depth; i++)
		{
			cout << "选择=" << chos[i] << " ";
			
		}cout<<"\n";
		for(int i = 0; i <= depth; i++)
		{
			cout << a[chos[i]] << "+";
		}cout<<"\n";
		return v;
	}
	int maxv = 0;
	for(int i = 1; i <= 3; i++)
	{
		chosed[chose]++;
		chos[depth]=chose;
		v = max(dfs(depth+1,i,maxdepth, v),v);
		chosed[chose]--;
	}
	return maxv;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	for(int i = 1; i <= T ;i++)
	{
		int n;
		scanf("%d",&n);
//		solve(n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d%d",&a[1],&a[2],&a[3]);
		}
//		int ans=0;
//		for(i = 1; i <= 3; i++)
//		{
//			chosed[i]++;
//			chos[0]=i;
//			ans = max(  dfs(1,i,n,0)  ,ans);
//			chosed[i]--;
//		}
//		cout << ans << endl;
		for(int i = 1; i <= 3; i++)
		{
			sort()
		}
	} 
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
