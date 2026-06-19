#include<bits/stdc++.h>

using namespace std;
struct Task{
	int r = 0;
	int c = 0; 
}t[1500]; 
int T,n,k,q;
int words[1500][1500];
int last[1500];
int currentn[1500];
bool checklast()
{
	for(int i = 0;i < 1500;i++)
	{
		if(last[i] != currentn[i])
		{
			return true; 
		}
	}
	return false; 
}
void copylast()
{
	for(int i = 0;i < 1500;i++)
	{
		last[i] = currentn[i];
	}
}
bool check(int index,int end,int round)
{
	for(int i = 1;i <= n;i++)
	{
		int l = words[i][0];
		for(int w = 1;w <= l;w++)
		{
			if(words[i][w] == end)
			{
				//cout << end;
				if(index == round)
				{
					if(w > 1 && words[i][w-1] == 1)
					{
						currentn[i] == 1;
						return true;
					}
					if(w > 2 && words[i][w-2] == 1)
					{
						currentn[i] == 1;
						return true;
					}
					return false;
				} 
				bool flag = false;
				bool flag2 = false;
				if(w > 1)
				{
					flag = check(index+1,words[i][w-1],round);
				}
				if(w > 2 && !flag)
				{
					flag2 = check(index+1,words[i][w-2],round);
				}
				if(flag || flag2)
				{
					if(round == 3){
						return false; 
					} 
					return true;
				}
			}
		}
	}
	return false;
}
void Function()
{
	memset(words,0,sizeof(words)); 
	cin >> n >> k >> q;
	//int last[1500];
	for(int i = 1;i <= n;i++)
	{
		int l;
		cin >> l;
		words[i][0] = l;//³¤¶È 
		for(int w = 1;w <= l;w++)
		{
			cin >> words[i][w];
		} 
	} 
	for(int i = 0;i < q;i++)
	{
		cin >> t[i].r;
		cin >> t[i].c;
	} 
	memset(last,0,sizeof(last)); 
	for(int i = 0;i < q;i++)
	{
	    //memset(last,0,sizeof(last)); 
	    memset(currentn,0,sizeof(currentn)); 
		Task ct = t[i];
		if(check(1,ct.c,ct.r))
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}	
	} 
} 

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> T;
	for(int i = 0;i < T; i++)
	{
		Function();		
    }
	return 0; 
} 
