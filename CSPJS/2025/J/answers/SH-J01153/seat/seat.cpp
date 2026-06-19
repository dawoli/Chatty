#include <iostream>
#include <stdio.h>
#include <fstream>
#include <bits/stdc++.h>

/*
普及-
n × m - i + 1  ?
*/

using namespace std;

const int MaxN = 10*10*4+100;
int n,m;
int a[MaxN];

bool comp(int x, int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++)
	{
		cin >> a[i];
	}
	int x=a[1];//little R's score;
	sort(a+1,a+n*m+1,comp);
	for(int i = 1; i <= n*m; i++)
	{
//		cout << a[i] << "\n";
		if(a[i]!=x)continue;
		//推断小明在第几列
//		cout << "\n\n小明第" << i <<"个\n";
		int r = i/n , c;
		r+=i%n?1:0;
		//小明在第几个
		if(r%2==0)//偶数列，2,4,6……，从后往前排
		{
//			cout << "偶数列" << endl;	
			c = n-i%n+1;
//			cout << c<<"="<<i<<"%"<<n<<"\n";
			if(i%n==0)//正好在这一列最后一个 
			{
				c = 1;
			}
		} 
		else//奇数列 
		{
			c = 0 + i%n;
//			cout << c<<"="<<i<<"%"<<n<<"\n";
			if(i%n==0)//正好在这一列最后一个 
			{
				c = n;
			}
		}
		
		printf("%d %d",r,c);
		break; 
	}
	
	
	fclose(stdout);
	fclose(stdin);
	return 0;
}
/*
3 4
100 99 98 97 96 95 94 93 92 91 90 89

3 4
99 100 98 97 96 95 94 93 92 91 90 89

3 4
98 100 99 97 96 95 94 93 92 91 90 89

3 4
97 100 99 98 96 95 94 93 92 91 90 89

3 4
96 100 99 98 97 95 94 93 92 91 90 89

3 4
95 100 99 98 97 96 94 93 92 91 90 89

3 4
94 100 99 98 97 96 95 93 92 91 90 89
*/
