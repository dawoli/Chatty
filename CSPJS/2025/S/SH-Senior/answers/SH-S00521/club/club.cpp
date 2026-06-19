#include<bits/stdc++.h>
using namespace std;
int N; //人数
int s[4][100009];
int l[4][50009];
int n[4];
int THMin[4]; //tihuanzuixiaodaijia
void Ins(int x,int tag)
{
//	cout<<"调用Ins --------"<<endl; 
	if(n[tag]<N/2) //没满人 
	{
		n[tag]+=1;
		l[tag][n[tag]]=x; //代替了s 
//		cout<<"直接将"<<x<<"插入了"<<tag<<"位"<<endl;
	}
	else //人满了！！ 
	{
//		cout<<tag<<"人满了，开始检查"<<endl;
		int CostMin=INT_MAX,CMpos=0,mcst=0; //最小调整代价、位置、来人最小值 
		if(tag ==1) mcst=s[tag][x] - max(s[2][x],s[3][x]); //最小代价 
		if(tag ==2) mcst=s[tag][x] - max(s[1][x],s[3][x]); //最小代价
		if(tag ==3) mcst=s[tag][x] - max(s[2][x],s[1][x]); //最小代价
//		cout<<"本人调整最小代价为"<<mcst<<endl;
        if(mcst> THMin[tag]){
        	for(int i=1;i<=N/2;i++)
			{
				int cst;//调整最低代价
				int sc=l[tag][i];//审查此人 
	//			cout<<tag<<"组第"<<i<<"个编号"<<sc<<"开始检查"<<endl; 
				
				if(tag ==1) cst=s[tag][sc] - max(s[2][sc],s[3][sc]); //最小代价 
				if(tag ==2) cst=s[tag][sc] - max(s[1][sc],s[3][sc]); //最小代价
				if(tag ==3) cst=s[tag][sc] - max(s[2][sc],s[1][sc]); //最小代价
				
	//			cout<<"最小代价："<<cst<<endl;
				
				if(CostMin > cst)
				{
					CostMin=cst;
					CMpos=i;
	//				cout<<"已更新最小代价为"<<CostMin<<endl; 
				}
				
			}
		}
		else CostMin=1;
//		cout<<"最终最小更换代价"<<CostMin<<endl; 
		if(CostMin < mcst) //换
		{
//			cout<<"决定更换"<<endl; 
			int nxt=l[tag][CMpos];//换出来的人
			l[tag][CMpos] = x; //人换进去
		    if(tag ==1)
		    {
				if(s[2][nxt] >= s[3][nxt])
		    	{
		    		n[2]+=1;
	            	l[2][n[2]]=nxt; //代替了s 
				}
				else
		    	{
		    		n[3]+=1;
	            	l[3][n[3]]=nxt; //代替了s 
				}
			}
			else if(tag ==2)
		    {
				if(s[1][nxt] >= s[3][nxt])
		    	{
		    		n[1]+=1;
	            	l[1][n[1]]=nxt; //代替了s 
				}
				else
		    	{
		    		n[3]+=1;
	            	l[3][n[3]]=nxt; //代替了s 
				}
			}
			else
		    {
				if(s[1][nxt] >= s[2][nxt])
		    	{
		    		n[1]+=1;
	            	l[1][n[1]]=nxt; //代替了s 
				}
				else
		    	{
		    		n[2]+=1;
	            	l[2][n[2]]=nxt; //代替了s 
				}
			}
		}
		else 
		{
//			cout<<"决定不更换"<<endl; 
            THMin[tag]=max(THMin[tag],mcst); //gengxinzuixiaobutihuanzhi
			int nxt=x;
		    if(tag ==1)
		    {
		    	if(s[2][nxt] >= s[3][nxt])
		    	{
		    		n[2]+=1;
	            	l[2][n[2]]=nxt; //代替了s 
				}
				else
		    	{
		    		n[3]+=1;
	            	l[3][n[3]]=nxt; //代替了s 
				}
			}
			else if(tag ==2)
		    {
		    	if(s[1][nxt] >= s[3][nxt])
		    	{
		    		n[1]+=1;
	            	l[1][n[1]]=nxt; //代替了s 
				}
				else
		    	{
		    		n[3]+=1;
	            	l[3][n[3]]=nxt; //代替了s 
				}
			}
			else
		    {
		    	if(s[1][nxt] >= s[2][nxt])
		    	{
		    		n[1]+=1;
	            	l[1][n[1]]=nxt; //代替了s 
				}
				else
		    	{
		    		n[2]+=1;
	            	l[2][n[2]]=nxt; //代替了s 
				}
			}
		}
	}
//	cout<<"执行完成 ---------"<<endl; 
	return ;
}
int main()
{
	int q;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	while(q--){
		n[1]=0,n[2]=0,n[3]=0;
		THMin[1]=1,THMin[2]=1,THMin[3]=1;
		cin>>N;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>s[j][i];
			}
		}
		for(int i=1;i<=N;i++)
		{
			int tag;
			if(s[1][i]>=s[2][i] && s[1][i]>=s[3][i]) tag=1;
			else if(s[2][i]>=s[1][i] && s[2][i]>=s[3][i]) tag=2;
			else tag=3;
			Ins(i,tag);
		}
		int ans=0;
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=n[i];j++)
			{
				int r=l[i][j];
				ans+=s[i][r];
			}
		}
		cout<<ans<<endl;
	}
}
