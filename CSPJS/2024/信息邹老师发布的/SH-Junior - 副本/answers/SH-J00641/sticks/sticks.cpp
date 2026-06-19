#include<bits/stdc++.h>
using namespace std;
string mn;
string smin(string a,string b)
{
	if(a.size()>b.size())return b;
	else if(a.size()<b.size())return a;
	else if(a>b)return b;
	else return a;
}
void dfs(int n,string num)
{
	if(n==1)return;
	else if(n<0)return;
	else if(smin(num,mn)==mn)return;
	else if(n==0){
		mn=smin(mn,num);return;
	}
	if(num.size()!=0)dfs(n-6,num+"0");
	else dfs(n-6,num+"6");
	dfs(n-2,num+"1");
	dfs(n-5,num+"2");
	dfs(n-4,num+"4");
	
	dfs(n-3,num+"7");
	dfs(n-7,num+"8");
}




int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	int t;cin>>t;
	
	while(t--)
	{
		int n;cin>>n;
		
		if(n==1){printf("-1\n");continue;}
		else if(n%7==0){for(int i = 1;i<=n/7;i++)printf("8");printf("\n");continue;}
		else if(n%7==1){cout<<10;for(int i = 1;i<=(n-8)/7;i++)printf("8");printf("\n");continue;}
		else if(n<=50){mn="999999999999999999999999999999999999999";dfs(n,"");cout<<mn<<endl;continue;}
		else if(n%7==2){cout<<1;for(int i = 1;i<=(n-2)/7;i++)printf("8");printf("\n");continue;}
		else if(n%7==3){cout<<200;for(int i = 1;i<=(n-17)/7;i++)printf("8");printf("\n");continue;}
		else if(n%7==4){cout<<20;for(int i = 1;i<=(n-11)/7;i++)printf("8");printf("\n");continue;}
		else if(n%7==5){cout<<2;for(int i = 1;i<=(n-5)/7;i++)printf("8");printf("\n");continue;}
		else {cout<<6;for(int i = 1;i<=(n-6)/7;i++)printf("8");printf("\n");continue;}
		
		
			
		
		

		
	}
}
