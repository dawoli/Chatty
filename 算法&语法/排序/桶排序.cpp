#include <bits/stdc++.h>
using namespace std;
int n;            //要给n个数排序
int bucket[10005]; //满足所有数不超过 bucket[x]的x

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		bucket[a]++; //进入相应的区域（桶）
					 //如果题目要求把重复的数删掉（去重）
		             //可以写 bucket[a]=1;
	}

	for(int i=0;i<=10000;i++) //要把所有区域里的数“拽”出来
//		while(bucket[i]>0)
//		{
//			cout<<i<<' '; //i指的是数
//			bucket[i]--;  //bucket[i]指的是区域 i里剩余数的数量
//		}
        for(int j=1;j<=bucket[i];j++)
        {
            cout<<i<<" ";
        }
	return 0;
}
