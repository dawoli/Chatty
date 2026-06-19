#include <bits/stdc++.h>
using namespace std;
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define foR(i,a,b) for(int i=a;i>=b;i--)
#define debug(s) //cout<<s<<'\n'

int n,m,k;
int bcj[11006];
int con[11006];
int vcon[16][10000];
int va[16];

int scb[10006];

int tbcj[10006];
int tcon[10006];

int bcm(int nd){
	while(bcj[nd]!=nd)nd=bcj[nd];
	return nd;
}
int bcc(int nm,int nn){
	int nmp=bcm(nm),nnp=bcm(nn);
	con[nmp]+=con[nnp];
	con[nnp]=0;
	bcj[nnp]=nmp;
	return con[nmp];
}

int tbcm(int nd){
	while(tbcj[nd]!=nd)nd=tbcj[nd];
	return nd;
}
int tbcc(int nm,int nn){
	int nmp=tbcm(nm),nnp=tbcm(nn);
	tcon[nmp]+=tcon[nnp];
	tcon[nnp]=0;
	tbcj[nnp]=nmp;
	return tcon[nmp];
}

struct node{
	int r;
	bool a;
	int u,v;
	int w;
}d[1200006];
int dp;
//所需的乡镇，是否计入乡镇维修，链接a,链接b，价值 

signed cmp(const void *a, const void *b){
	return (*(node *)a).w-(*(node *)b).w;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	For(i,1,m){
		int u,v,w;
		cin>>d[dp].u>>d[dp].v>>d[dp].w;
		dp++;
	}
	//For(i,)
	For(i,1,k){
		int c;
		cin>>c;
		For(j,1,n){
			d[dp].u=n+i;
			d[dp].r=n+i;
			d[dp].v=j;
			d[dp].a=false;
			cin>>d[dp].w;
			dp++;
			d[dp].u=n+i;
			d[dp].r=n+i;
			d[dp].v=j;
			d[dp].a=true;
			d[dp].w=d[dp-1].w+c;
			dp++;
		}
	}
	int tot=m+2*n*k;
	qsort((int*)d,tot,sizeof(node),cmp);
	For(i,1,n){
		bcj[i]=i;
		con[i]=1;
	}
	For(i,n+1,n+k){
		bcj[i]=i;
	}
	int cost=0;
	//最小生成树 
	For(i,0,tot-1){
		node cn=d[i];
		debug("Processing "<<i<<": "<<cn.r<<','<<cn.a<<','<<cn.u<<','<<cn.v<<','<<cn.w);
		if(cn.u>n){
			int u=cn.u;
			if((va[u-n]!=0)!=cn.a)continue;
		}
		if(bcm(cn.u)!=bcm(cn.v)){
			debug("Debug: connect "<<cn.u<<" with "<<cn.v<<". ");
			cost+=cn.w;
			if(cn.u>n){
				int u=cn.u;
				vcon[u-n][++vcon[u-n][0]]=cn.v;
				va[u-n]+=cn.w;
			}
			if(bcc(cn.v,cn.u)==n){
				break;
			}
		}		 
	}
	//检查能否删村庄
	For(i,1,k){
		debug("Check village"<<i);
		if(vcon[i][0]){
			For(j,1,vcon[i][0]){
				scb[vcon[i][j]]=1;
			}
			For(j,1,n){
				if(scb[j]==0)tbcj[j]=vcon[i][1];
				else{
					tbcj[j]=j;
				}
			}
			int cv=0;
			For(_i,0,tot-1){
				node cn=d[_i];
				if(cn.u>n){
					continue;
				}
				if(tbcm(cn.u)!=tbcm(cn.v)){
					cv+=cn.w;
					if(bcc(cn.v,cn.u)==vcon[i][0]){
						break;
					}
				}
			}
			For(j,1,vcon[i][0]){
				scb[vcon[i][j]]=0;
			}
			if(va[i]>cv){
				debug("Remove village "<<i);
				cost-=va[i];
				cost+=cv;
			}
		}
	}
	cout<<cost;
	return 0;
}

