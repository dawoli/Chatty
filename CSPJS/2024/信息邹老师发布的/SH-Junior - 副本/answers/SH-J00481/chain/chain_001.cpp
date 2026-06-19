#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m,q,l[200001],cnt_l[100001],r[10001],c[100001],maxr;//cnt_l qianzhuihe of l
vector<int>v[200001];
vector<int>cnt_num[200001];//the value of cnt_num[x] is x 
//                           in the words,l[cnt_num] is all euqal to x;
bool flag[200001][101];
int get_id(int x,int y)
{
	return cnt_l[x]+y;
}
void dfs(int x,int step)
{
	if(flag[x][step])return;
	flag[l[x]][step]=true;
	//cout<<x<<" "<<step<<endl;
	if(step>=maxr+1)
	{
		return;
	}
	for(int id:v[x])
	{
		int i,j;
		i=lower_bound(cnt_l+1,cnt_l+n+1,id)-(cnt_l+1);
		j=id-cnt_l[i];
		//cout<<" "<<i<<" "<<j<<endl;
		for(int z=id+1;z<=min(id+m-1,cnt_l[i+1]);z++)
		{
			dfs(z,step+1);
		}
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=200000;i++)
		{
			v[i].clear();
			cnt_num[i].clear();
		}
		int pre_tmp=0;
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)
		{
			int tmp;
			cin>>tmp;
			cnt_l[i]=cnt_l[i-1]+pre_tmp;
			for(int j=1;j<=tmp;j++)
			{
				cin>>l[get_id(i,j)];
				for(auto k:cnt_num[l[get_id(i,j)]])
				{
					if(cnt_l[i]<k&&k<(cnt_l[i]+tmp))continue;
					v[get_id(i,j)].push_back(k);
					v[k].push_back(get_id(i,j));
				}
				cnt_num[l[get_id(i,j)]].push_back(get_id(i,j));
			}
			pre_tmp=tmp;
		}
		cnt_l[1+n]=cnt_l[n]+pre_tmp;
		/*for(int i=1;i<=cnt_l[1+n];i++)
		{
			for(auto j:v[i])cout<<j<<" ";
			cout<<endl;
		}*/
		//for(int i=1;i<=n;i++)cout<<cnt_l[i]<<" ";
		//cout<<endl;
	//	for(int i=1;i<=cnt_l[n+1];i++)cout<<l[i];
	//	cout<<endl;
		memset(flag,0,sizeof(flag));
		
		/*for(int i=1;i<=7;i++)
		{
			for(int j=1;j<=6;j++)
			{
				cout<<flag[j][i]<<" ";
			}
			cout<<endl;
		}*/
		maxr=-1;
		for(int i=1;i<=q;i++)
		{
			cin>>r[i]>>c[i];
			maxr=max(maxr,r[i]);
		}
		for(auto id:cnt_num[1])
		{
			int i,j;
			i=lower_bound(cnt_l+1,cnt_l+n+1,id)-(cnt_l+1);
			j=id-cnt_l[i];
			//cout<<id<<" "<<i<<" "<<j<<endl;
			for(int z=id+1;z<=min(id+m-1,cnt_l[i+1]);z++)
			{
				dfs(z,1);
			}
			//cout<<endl;
		}
		for(int i=1;i<=q;i++)
		{
			cout<<flag[c[i]][r[i]]<<endl;
		}
	}
}
