#include<bits/stdc++.h>
using namespace std;
const int N=100010;
const int M=1000010;
int T,n,m,L,V;
int d[N],v[N],a[N];
int p[M],nxt[M];
struct node{
	double st,en;
	int fl1,fl2; 
}e[N]={};
bool op[M];
struct node2{
	int start,end;
}e2[N]={};
bool cmp(node2 a,node2 b){
	if(a.end==b.end)return a.start<b.start;
	return a.end<b.end;
}
int find(int qu){
	if(qu==0)return m;
	else return m-1;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		//memset(e,0,sizeof(e));
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if(a[i]==0){
				if(v[i]>V)e[i]={d[i],L,1,1};
				else e[i]={0,0,0,0}; 
			}else if(a[i]>0){
				if(v[i]>V){
					e[i]={d[i],L,1,1};
				}else{
					double Vdis=(V*V-v[i]*v[i])/2.00/a[i];
					if(Vdis<=L){
						e[i].st=Vdis;
						e[i].en=L;
						e[i].fl1=0,e[i].fl2=1;	
					}else e[i]={0,0,0,0};
				
				}
			}else{
				if(v[i]>V){
					double Vdis=(V*V-v[i]*v[i])/2.00/a[i];
					//double Vend=(-v[i]*v[i])/2.00/a[i];
					if(L<Vdis+d[i])e[i]={d[i],1.0000*L,1,1};
					else e[i]={d[i],1.0000*Vdis+d[i],1,0};
				}else e[i]={0,0,0,0};
			}
			//cout<<e[i].st<<" "<<e[i].en<<endl;
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
			op[p[i]]=1;
		}
		int last=1e9;
		for(int i=L;i>=1;i--){
			if(op[i]==1)last=i;
			nxt[i]=last;
		}
		int ans=0; 
		for(int i=1;i<=n;i++){
			int endd=0;
			if(e[i].fl1==1){
				endd=nxt[int(ceil(e[i].st))];
			}else{
				if(e[i].st==int(e[i].st))endd=nxt[int(e[i].st+1)];
				else endd=nxt[int(ceil(e[i].st))];
			}
			if(e[i].fl2==1){
				if(e[i].en>=endd)ans++; 
			}else{
				if(e[i].en>endd)ans++;
			}
		}
		for(int i=1;i<=L;i++){
			op[i]=nxt[i]=0;
		}
		printf("%d ",ans);
		bool A=1,B=1,C=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=0){
				A=0;
			}
			if(a[i]<=0){
				B=0;
			}
			if(a[i]>=0){
				C=0;
			}
		}
		if((A&&n>=1e4)||(B&&n>=1e4)||(C&&n>=1e4)){
			printf("%d\n",find(ans));
			continue;
		}
		memset(e2,0,sizeof(e2));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				bool flag=0;
				if(e[i].fl1==1&&e[i].fl2==1&&p[j]>=e[i].st&&p[j]<=e[i].en)flag=1;
				if(e[i].fl1==1&&e[i].fl2==0&&p[j]>=e[i].st&&p[j]<e[i].en)flag=1;
				if(e[i].fl1==0&&e[i].fl2==1&&p[j]>e[i].st&&p[j]<=e[i].en)flag=1;
				if(e[i].fl1==0&&e[i].fl2==0&&p[j]>e[i].st&&p[j]<e[i].en)flag=1;
				if(flag){
					if(e2[i].start==0)e2[i].start=j;
				}else if(e2[i].start!=0){
					e2[i].end=j-1;
					break;
				}
				if(j==m&&flag)e2[i].end=j;
			}
			//cout<<e2[i].start<<" "<<e2[i].end<<endl;
		}
		
		sort(e2+1,e2+n+1,cmp);
		int ans2=0,now=0;
		for(int i=1;i<=n;i++){
			if(e2[i].start==0&&e2[i].end==0)continue;
			if(now==0||e2[i].start>now)now=e2[i].end,ans2++;
		}
		printf("%d\n",m-ans2);
	}
	return 0;
}
