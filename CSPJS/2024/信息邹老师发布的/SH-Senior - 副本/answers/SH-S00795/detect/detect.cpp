#include <bits/stdc++.h>
using namespace std;
struct node{
	double l,r;
	int f,fl;
}rec[100005];
int p[100005],tp[100005],m,n,an;
vector<int> v1[3005];
int r[100005];
void dfs(int x){
//	cout<<x<<" "<<tp[x]<<endl;
	if(x==m+1){
		int flag=0,tmp=0;
		for(int i=0;i<=n;i++) r[i]=0;
		for(int i=1;i<=m;i++){
			if(tp[i]==1){
				for(int j=0;j<v1[i].size();j++){
					r[v1[i][j]]++;
				}
				tmp++;
			}
		}
		for(int i=1;i<=n;i++){
			if(rec[i].fl==1&&r[i]==0){
			//	for(int j=1;j<=n;j++) cout<<r[j]<<" ";
			//	cout<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0) an=max(an,tmp);
		return ;
	}
	tp[x]=0;
	dfs(x+1);
	tp[x]=1;
	dfs(x+1);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	scanf("%d",&t);
    while(t--){
    	int L,V,flag=0,f2=0,ans=0;
    	scanf("%d%d%d%d",&n,&m,&L,&V);
    	int d,v,a;
    	ans=0;
    	for(int i=1;i<=n;i++){
    		rec[i].f=0;
    		scanf("%d%d%d",&d,&v,&a);
    		if(a==0){
    			if(v<=V){
    				rec[i].l=double(L+1);
    				rec[i].r=double(L+1);
				}
				else{
					rec[i].l=double(d);
					rec[i].r=double(L);
					rec[i].f=2;
				}
			}
			
    		else{
    			flag=1;
    			double x=double((V*V-v*v)/(2*a));
    			if(x+d>L&&a>0){
    				rec[i].l=double(L+1);
    				rec[i].r=double(L+1);
				}
				else if(x<0&&a<0){
					rec[i].l=double(L+1);
					rec[i].r=double(L+1);
				}
				else{
					if(a>0){
						rec[i].l=d+x;
						rec[i].r=L;
					}
					else{
						rec[i].l=d;
						rec[i].r=d+x;
						rec[i].f=1;
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
		}
		for(int i=1;i<=n;i++){
			rec[i].fl=0;
			for(int j=1;j<=m;j++){
				if(rec[i].f==0){
					if(rec[i].l<p[j]&&rec[i].r>=p[j]&&rec[i].fl==0){
						f2=1;
						ans++;
						rec[i].fl=1; 
					}
					else if(rec[i].l<p[j]&&rec[i].r>=p[j]){
					
						v1[j].push_back(i);
					}
				}
				if(rec[i].f==1){
					if(rec[i].l<=p[j]&&rec[i].r>p[j]&&rec[i].fl==0){
						f2=1;
						ans++;
						rec[i].fl=1; 
					}
					if(rec[i].l<=p[j]&&rec[i].r>p[j]){
						v1[j].push_back(i);
					}
				}
				if(rec[i].f==2){
					if(rec[i].l<=p[j]&&rec[i].r>=p[j]&&rec[i].fl==0){
						f2=1;
						ans++;
						rec[i].fl=1; 
					}
					if(rec[i].l<=p[j]&&rec[i].r>=p[j]){
						v1[j].push_back(i);
					}
				}
			}
		}
//		cout<<rec[3].l<<" "<<rec[3].r<<" "<<rec[3].f<<endl;
/*		for(int i=1;i<=m;i++){
			cout<<i<<" ";
			for(int j=0;j<v1[i].size();j++){
				cout<<" "<<v1[i][j]<<" ";
			}
			cout<<endl;
		}*/
		cout<<ans<<" ";
		if(flag==0&&f2==1) cout<<m-1<<endl;
		else if(flag==0) cout<<m<<endl;
		else{
			dfs(1);
			cout<<m-an<<endl;
		}
	}
	return 0;
}
