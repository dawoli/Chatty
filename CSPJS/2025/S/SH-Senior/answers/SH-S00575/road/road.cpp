#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,u,l,value;
	bool operator<(const node &x)const{
		return l>x.l;
	}	
}g[100005];
int n,m,k,fa[100005],num=0,fate;
bool flag[100005],fla;
int find(int a){
	if(fa[a]==a)return a;
	else return fa[a]=find(fa[a]);
}
void merge(int a,int b){
	fa[find(a)]=find(b);
}
bool cmp(node x,node y){
	return x.l<y.l;
}
void valu1()
{
	sort(g+1,g+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(g[i].u)!=find(g[i].v)){
			merge(g[i].u,g[i].v);
			num+=g[i].l;
		}
	}
}
void valu2()
{
	sort(g+1,g+n*k+m+1,cmp);
	for(int i=1;i<=m+n*k;i++)
	{
		fla=1;
		for(int j=1;j<=n;j++)
		{
			if(fate!=fa[j])fla=0;
		}
		if(fla==1)break;
		if(find(g[i].u)!=find(g[i].v)){
			merge(g[i].u,g[i].v);
			num+=g[i].l;
		}
	}
}
priority_queue<node> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>g[i].u>>g[i].v>>g[i].l;
		fa[i]=i;
		g[i].value=0;
		q.push(g[i]);
	}
	if(k==0)valu1();
	else {
		for(int i=1;i<=k;i++){
			fa[n+i]=n+i;
			flag[n+i]=true;
			cin>>a;
			int b;
			for(int j=1;j<=n;j++)
			{
				cin>>b;
				g[m+n*(i-1)+j].u=i+n;
				g[m+n*(i-1)+j].v=j;
				g[m+n*(i-1)+j].l=b+a;
				g[m+n*(i-1)+j].value=a;
				q.push(g[m+n*(i-1)+j]);
			}		
		}
		if(a==0)valu2();
		else {
			while(fla==0)
			{
				int a=q.top().u,b=q.top().v,c=q.top().l,d=q.top().value;
				q.pop();
				fla=1;
				fate=fa[1];
				for(int j=1;j<=n;j++)
				{
					if(find(j)!=fate)fla=0;
				}
				if(find(a)!=find(b)&&fla==0){
					merge(a,b);
					num+=c;
					if(a>n&&flag[a]==true)
					{
						flag[a]=false;
						for(int i=1;i<=n;i++)
						{
							g[m+n*(a-n-1)+i].l-=g[m+n*(a-n-1)+i].value;
							q.push(g[m+n*(a-n-1)+i]);
						}
					}
				}	
			}
		}
	}
	cout<<num<<endl;
}
