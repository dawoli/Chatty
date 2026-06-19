#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int T;
struct color{
	int num;
	bool color; // 1 or 0, 1 means blue
}A[1000001];
int n;
int r = -1;
int C[1000001];
void func(color a[1000001],int floor = 1)
{
	//cout << "µ±Ç°Â¥²ã" << floor << ' ';
	//for(int i = 0; i <= floor; i++)cout << a[i].color << ' ';
	//cout << endl;
	if(floor>=n-1)
	{
//		for(int i = 0; i < n; i++)
//		{
//			cout << ' ' <<a[i].color << ' '; 
//		}
//		cout << endl;
		for(int i = 0; i < n; i++)
		{
			for(int j = i-1; j >= 0; j--)
			{
				bool f = false;
				if(A[j].color==A[i].color)
				{
					f = true;
					if(A[i].num==A[j].num)
					{
						C[i] = A[i].num;
					}
					break;
				}
				if(!f)
				{
					C[i]=0;
				}
			}
		}
		int count = 0;
		for(int i = 0; i < n; i++)
		{
			//cout << C[i] << ' ';
			count+=C[i];
		}
		//cout << endl;
		if(count>r)
		{
			r = count;
//			for(int i = 0; i < n; i++)
//			{
//				cout << ' ' <<a[i].color << ' '; 
//			}
		//cout << endl;
		}
		//cout << endl << endl;
		return;
	}
//	bool flag = false;
//	for(int i = floor; i >= 0; i--)
//	{
//		if(A[i].color==A[floor].color)
//		flag = 1;
//	}
	if(1)
	{
		a[floor+1].color = 1;
		func(a,floor+1);
	}
	if(1)
	{
		//cout << 1 <<endl;
		a[floor+1].color = 0;
		func(a,floor+1);
	}
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	for(int i = 0; i < T; i++)
	{
		scanf("%d",&n);
		for(int j = 0; j < n; j++)
		{
			scanf("%d",&A[j]);
		}
//		for(int j = 0; j < n; j++)
//		{
//			cout << A[j] << ' ';
//		}
//		cout << '\n';
		A[0].color = 1;
		func(A,0);
		cout << r << endl;
		r=0;
		for(int i = 0; i < n; i ++)
		{
			C[i]=0;
		}
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
