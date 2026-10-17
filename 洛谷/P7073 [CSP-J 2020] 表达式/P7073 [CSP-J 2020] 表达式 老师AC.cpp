#include <iostream>
#include <stack>
#include <string>
using namespace std;
string s;				// 存储后缀表达式
int	   a[1000005];		// 用栈来建立表达式树
int	   son[1000005][2]; // 记录左右节点的编号
int	   flag[1000005];	// 标记该节点是否取反
int	   c[1000005];		// 标记该节点的改变是否会影响最后结果
int	   n, q, ck;
int	   dfs(int u, int g)
{			   // 节点编号  该节点是否取反
	a[u] ^= g; // 处理取反
	if (u <= n)
	{ // 叶子节点直接返回对应的数值 0或者1
		return a[u];
	}
	// 递归计算左右节点的结果
	int x = dfs(son[u][0], g ^ flag[son[u][0]]);
	int y = dfs(son[u][1], g ^ flag[son[u][1]]);
	// 标记当前节点是否影响最后结果
	if (a[u] == 2)
	{ //'&'运算
		// 左右节点其1为0，另一节点不影响最后结果
		if (x == 0)
			c[son[u][1]] = 1;
		if (y == 0)
			c[son[u][0]] = 1;
		return x & y;
	}
	else
	{ //'|'运算
		// 左右节点其1为1，另一节点不影响最后结果
		if (x == 1)
			c[son[u][1]] = 1;
		if (y == 1)
			c[son[u][0]] = 1;
		return x | y;
	}
}
// 同步父节点的影响情况
void dfs2(int u)
{
	if (u <= n)
		return;
	c[son[u][0]] |= c[u];
	c[son[u][1]] |= c[u];
	dfs2(son[u][0]);
	dfs2(son[u][1]);
}
int main()
{
	getline(cin, s); // 输入后缀表达式
	scanf("%d", &n); // 输入运算数的个数
	ck = n;
	for (int i = 1; i <= n; i++)
	{ // 输入每个运算数
		scanf("%d", &a[i]);
	}
	stack<int> b; // 创建栈b
	// 遍历后缀表达式
	for (int i = 0; s[i]; i += 2)
	{
		// 找字符'x'
		if (s[i] == 'x')
		{
			// 计算后面的运算数的编号  x125
			int num = 0;
			i++;
			while (s[i] != ' ')
			{
				num = num * 10 + (s[i] - '0');
				i++;
			}
			i--;
			b.push(num); // 将预算数的编号入栈
		}
		else if (s[i] == '&')
		{					 //'&'运算
			int x = b.top(); // 获取栈顶的两个元素
			b.pop();
			int y = b.top();
			b.pop();
			b.push(++ck);	// 运算符入栈
			a[ck]	   = 2; // 运算符的标识 2代表'&'
			son[ck][0] = x; // ck运算符的左节点
			son[ck][1] = y; // ck运算符的右节点
		}
		else if (s[i] == '|')
		{					 //'|'运算
			int x = b.top(); // 获取栈顶的两个元素
			b.pop();
			int y = b.top();
			b.pop();
			b.push(++ck);	// 运算符入栈
			a[ck]	   = 3; // 运算符的标识 3代表'|'
			son[ck][0] = x; // ck运算符的左节点
			son[ck][1] = y; // ck运算符的右节点
		}
		else if (s[i] == '!')
		{						//'!'运算
			flag[b.top()] ^= 1; // 直接修改栈顶元素的值
		}
	}
	// 深搜计算整个表达式的值，并标记对应的a[i]改变是否会影响结果
	int ans = dfs(ck, flag[ck]);
	// 第二次搜索，将父节点的属性同步给子节点
	dfs2(ck);
	// q次访问并输出
	scanf("%d", &q);
	while (q--)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", c[x] ? ans : !ans);
	}
	return 0;
}