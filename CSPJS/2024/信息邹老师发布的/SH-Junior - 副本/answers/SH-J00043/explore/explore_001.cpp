#include <bits/stdc++.h>
using namespace std;
int explore[1003][1003];
int res[7];
int T,n,m,x,y,d;
int move(){
	int xi=x,yi=y;
	if(d==0){
		yi++;
	}
	if(d==1){
		xi++;
	}
	if(d==2){
		yi--;
	}
	if(d==3){
		xi--;
	}
	if(explore[xi][yi]==0)
	{
		x=xi;
		y=yi;
		explore[x][y]=23;
		return 0 ;
	}
	else{
		d=(d+1)%4;
	}
	return 0;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout) ;
	long long k;
	cin>>T;
	for(int i=0;i<1003;i++){
		for(int j=0;j<1003;j++){
			explore[i][j]=1;
		}
	}
	for(int i=0;i<=T;i++)
	{
		res[i]=0;
	}
	for(int i=0;i<T;i++)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			string s; 
			cin>>s;
			for(int ij=0;ij<m;ij++)
			{
				if(s[ij]=='.') {
					explore[j][ij+1]=0;
				}
				else{
					explore[j][ij+1]=1;
				}
			}
		}
		explore[x][y]=23;
		for(int j=1;j<=k;j++)
		{
			move();
		}
		for(int j=1;j<=n;j++)
		{
			for(int ij=1;ij<=m;ij++)
			{
				if(explore[ij][j]==23)
			
				{
					cnt++;
				}
			}
			cout<<endl;
		}
		res[i]=cnt;
		
	}
	for(int i=0;i<T;i++)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}
