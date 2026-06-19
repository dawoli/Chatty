#include<bits/stdc++.h>
using namespace std;

const int MAXN=100009;  // 定义最大节点数，适配题目数据范围

// 定义全局数组：
// l[u]：节点u的左儿子编号（0表示无左儿子）
// r[u]：节点u的右儿子编号（0表示无右儿子）
// chk[u]：标记节点u的子树是否是完全二叉树（1=是，0=否）
// mn[u]：节点u的子树中，从u到叶子节点的最短距离
// mx[u]：节点u的子树中，从u到叶子节点的最长距离
int l[MAXN],r[MAXN];
bool chk[MAXN];
int mn[MAXN],mx[MAXN];
int ans=0;  // 记录完全二叉树子树的总数

// 递归函数：后序遍历处理每个节点u的子树
void dfs(int u)
{
	// 边界条件：如果节点u是0（不存在），直接返回
	if(u==0)
	{
		mn[u]=mx[u]=0;  // 空节点的距离设为0
		chk[u]=true;      // 空节点默认是"合法"的
		return;
	}

	// 步骤1：先递归处理左儿子和右儿子（后序遍历核心）
	dfs(l[u]);
	dfs(r[u]);

	// 步骤2：初始化当前节点u的最短/最长距离
	// 叶子节点（左右儿子都是0）：距离自己为1
	if(l[u]==0&&r[u]==0)
	{
		mn[u]=mx[u]=1;
		chk[u]=true;  // 叶子节点的子树是完全二叉树
	}
	else
	{
		// 非叶子节点：最短距离 = 1 + 左右儿子最短距离的最小值
		mn[u]=1+min(mn[l[u]],mn[r[u]]);
		// 非叶子节点：最长距离 = 1 + 左右儿子最长距离的最大值
		mx[u]=1+max(mx[l[u]],mx[r[u]]);

		// 步骤3：判断节点u的子树是否是完全二叉树（四个条件）
		// 条件1：左右子树都是完全二叉树
		chk[u]=chk[l[u]]&&chk[r[u]];
		// 条件2：左子树的最短距离 ≥ 右子树的最长距离（保证整齐）
		if(chk[u]) chk[u]&=(mn[l[u]]>=mx[r[u]]);
		// 条件3：当前子树的最长-最短距离 ≤1（层数差不超过1）
		if(chk[u]) chk[u]&=(mx[u]-mn[u]<=1);
	}

	// 步骤4：如果当前子树是完全二叉树，答案数+1
	if(chk[u])
	{
		ans++;
	}
}

int main()
{
	// 加速输入输出
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;  // n表示总节点数
	cin>>n;

	// 输入每个节点的左儿子和右儿子（节点编号从1到n）
	for(int i=1; i<=n; i++)
	{
		cin>>l[i]>>r[i];
	}

	// 步骤1：从根节点（编号1）开始递归处理整棵树
	dfs(1);

	// 步骤2：输出完全二叉树子树的总数
	cout<<ans<<endl;

	return 0;
}