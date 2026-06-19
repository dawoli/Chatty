#include <bits/stdc++.h>
using namespace std;
int A[100002];//Êý¾Ý 
bool B[100002];//ÑÕÉ« f=red t=blue 
int n;

int test(){
	int c,aj;
	for(int i=1;i<n;i++)
	{
		if (A[i]>0)
		{
			if (B[i-1]!=B[i])
			{
				for(int j=0;j<i;j++)
				{
					if (B[j]==B[i])
					{
						aj=A[j];
						break;
					}
						
				}	
				c+=aj;

			}
		}
	}

	return c;
}


int main() 
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	
	for(int w=0;w<T;w++)
	{
		
		int maxx,atta=0;
		cin>>n;
		for(int s=0;s<n;s++)
		{
			cin>>A[s];
		}
		
		for(int i=0;i<n;i++)
		{
			B[i]=true;
			for(int j=i;j<n;j++){
				B[j]=true;
				atta=test();
				if (atta>maxx){
					swap(atta,maxx);
				}
				B[j]=false;
			}
			B[i]=false;
			 
		}
		
		cout<<0<<endl;
		
	}
	return 0;
}
