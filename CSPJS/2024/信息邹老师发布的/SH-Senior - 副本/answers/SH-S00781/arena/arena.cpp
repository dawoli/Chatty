#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

template<typename T>
void read(T& x)
{
	T n = 0;
	int f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		n = n * 10 + ch - '0';
		ch = getchar();
	}
	x = n * f;
}

int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	
	
	
	
}
