#include<bits/stdc++.h>
using namespace std;
int main (){
	/*freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);*/
	int n,m,s[n*m],ans1 = 1,x = 0,y = 0; //x是小R所在的列数 
	cin >> n >> m;
	int e = n*m;
	for(int a = 1;a <= e;a++)
	{
		cin >> s[e];//输入 
	}
	for(int c = 1;c <= e;c++)//比较成绩 
	{
		if(s[c]>s[0])
		{
			ans1++;
		}
		
	}
	if(ans1 == 1)
	{
		cout << "1" << " " << "1";
	}
	else
	{
		x = (ans1-1)/n+1;
		if(x % 2 == 0) 
		{
			y = x + 1 - (ans1 - n * (x-1));	
			cout << x <<" "<< y;
		}
		else
		{
			y = ans1 - n * (x-1);
			cout << x <<" "<< y;
		}
	}
	/*fclose(stdin)
	fclose(stdout)*/
	return 0;
}
