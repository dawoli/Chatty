#include<bits/stdc++.h>
using namespace std;
int dp[15];
//0:6,1:2,2:5,3:5,4:4,5:5,6:6,7:3,8:7,9:6
int main()
{
//	freopen("sticks.in","r",stdin);
//	freopen("sticks.out","w",stdout);
    dp[0]=6;
    dp[1]=2;
    dp[2]=5;
    dp[3]=5;
    dp[4]=4;
    dp[5]=5;
    dp[6]=6;
    dp[7]=3;
    dp[8]=7;
    dp[9]=6;
    int t;
    cin>>t;
    for(int i=1;i<=t;t++)
    {
    	int n, a, b, c;
    	cin>>n;
    	bool flag=true;
    	while(flag)
    	{
    		int d=0, sum=0;
			b=d%10/10;
			c=d/100;//a:个位，b:十位，c：百位
			for(int j=0;j<=9;j++)
			{
				//if(b==dp[j]&&b!=0) sum+=dp[j];
				if(c==dp[j]) sum+=dp[j];
			}
			if(sum==n)
			{
				cout<<d<<endl;
				flag=false;
				break;
			}
			if(n==1)
			{
				cout<<-1<<endl;
				flag=false;
				break;
			}
			if(n==3)
			{
				cout<<7<<endl;
				flag=false;
				break;
			}
			d++;
		}

	}
	return 0;
}

