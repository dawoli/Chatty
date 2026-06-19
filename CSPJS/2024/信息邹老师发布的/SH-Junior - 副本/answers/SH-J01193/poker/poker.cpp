#include<iostream>
#include<cstring>
#include<cstdio>
#include<fstream>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	char c[53][10]={0};
	cin>>n;
	int top=0;
	int k[53]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(i==1)
		{
			k[++top]=1;
		}
		else
		{
			bool b=true;
			for(int j=top;j>=1;j--)
			{
				if(strcmp(c[i],c[k[j]])==0)
				{
					b=false;
					break;
				}
			}
			if(b==true)
			{
				k[++top]=i;	
			} 
		}
	}
	cout<<52-top<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
