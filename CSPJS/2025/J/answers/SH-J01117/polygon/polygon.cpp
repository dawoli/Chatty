#include <iostream>
using std::cin;
using std::cout;
using std::max;

int jzha[5010],jzhn;
bool vis[5010];
unsigned long long ans;

void dfs(int maxnow,int sumnow,int posnow,int numnow)
{
	if(sumnow>maxnow*2&&numnow>=3) 
	{
		///*dbg*/for(int i=0;i<numnow;i++) cout<<' ';
		///*dbg*/cout<<' ';
		///*dbg*/cout<<"YES"<<std::endl;
		ans++;
		ans%=998244353;	
	}
	for(int i=posnow+1;i<=jzhn;i++)
	{
		if(!vis[i])
		{
			///*dbg*/for(int j=0;j<numnow;j++) cout<<' ';
			///*dbg*/cout<<i<<'('<<jzha[i]<<')'<<std::endl;
			vis[i]=true;
			dfs(max(maxnow,jzha[i]),sumnow+jzha[i],i,numnow+1);
			vis[i]=false;
		}
	}
}



int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>jzhn;
	for(int i=1;i<=jzhn;i++) cin>>jzha[i];
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}

