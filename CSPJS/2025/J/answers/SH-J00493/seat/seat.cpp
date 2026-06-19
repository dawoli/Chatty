#include<bits/stdc++.h>
using namespace std;
int n, m; // 行列
int R; // 小R成绩 
int idx; // 小R为第几名 
int arr[105] = {0}; // 考生第一轮成绩，其中arr[1]为小R成绩
int c, r; // 答案，c为列，r为行 

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n * m; i++) cin>>arr[i];
	R = arr[1];
	sort(arr + 1, arr + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++)
	{
		if(arr[i] == R)
		{
			idx = i;
			break;
		}
	}
	c = (idx - 1) / n + 1;
	if(c % 2 == 1) // 奇数列，从上往下
	{
		r = idx % m; // 此时r范围为0到m-1 
		if(r == 0) r = m; // 此时r范围为1到m 
	} 
	else // 偶数列，从下往上 
	{
		r = idx % m; // 此时r范围为0到m-1
		if(r == 0) r = m; // 此时r范围为1到m 
		r = m - r + 1;
	}
	cout<<c<<" "<<r; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
