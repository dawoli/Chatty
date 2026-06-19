#include <bits/stdc++.h>
using namespace std; 
int qwq[100002];
bool s[100002];
int n,couou;


void fff()
{
	int i,j;
	for(int e=0;e<n;e++)
	{
		j=qwq[e];
		if (j>0 and s[e]==false)
		{
			for(int w=0;w<n;w++)
			{
				i=qwq[w];
				if(i>0)
				{
					if(i<j and s[e]==false) //j*i
					{
						qwq[w]=0;//i=0
						s[e]=true;//j=t
						break;
					}
	 
				}	
			}
			
		}
	}
	
	
	for(int a=0;a<n;a++)
	{
		if (qwq[a]>0){
			couou++;
		}
	}

	cout<<couou<<endl;
	
}

int main() 
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	couou=0;
	
	 
	for(int w=0;w<n;w++)
	{
		cin>>qwq[w];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(qwq[i]>qwq[j])
			{
				swap(qwq[i],qwq[j]);
			}
		}
		
	}

	fff();
	

	return 0;
}
