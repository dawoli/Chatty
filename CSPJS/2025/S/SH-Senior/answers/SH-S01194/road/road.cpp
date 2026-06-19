//实验员精神
//一棵树似乎总是最优的
//所以我们似乎可以先去掉一些废物边 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct bian{
	int x;
	int y;//两个端点
	int tj;//条件，为0则是旧城边，为其他数字是新城边
	int v;//价格
};
int zhu[10020]={};
bian cs[1000010]={};
bian zhihou[2000010]={};
int nv[15]={};
int zz=0;
int ans=99999999999999999;
bool ejz[15]={};
bool cmp(bian a,bian b){
	return a.v<b.v;
}
int root(int a){//找老祖宗
	if(zhu[a]!=a){
		zhu[a]=root(zhu[a]);
	}
	return zhu[a];
}
void hb(int a,int b){
	zhu[zhu[a]]=zhu[b];
}
int ss(int now){
	if(now==k){
		int nans=0;
		for(int i=1;i<=n+k;i++){
		    zhu[i]=i;
	    }
		for(int i=0;i<zz;i++){
    		if(zhihou[i].tj==-1||ejz[zhihou[i].tj]==1){
    			if(root(zhihou[i].x)!=root(zhihou[i].y)){
    	        	//cout<<zhihou[i].x<<" "<<zhihou[i].y<<" "<<zhu[zhihou[i].x]<<" "<<zhu[zhihou[i].y]<<" "<<zhihou[i].v<<endl;
        	    	hb(zhihou[i].x,zhihou[i].y);
        			nans+=zhihou[i].v;
        		}
    	   	}
    	}
		for(int i=0;i<k;i++){
			if(ejz[i]==1)nans+=nv[i];
		}
		//for(int i=0;i<k;i++)cout<<ejz[i];
	//	cout<<endl;
	//	cout<<nans<<endl;
		ans=min(ans,nans);
		return 0;
	}
	ss(now+1); 
	ejz[now]=1;
	ss(now+1);
	ejz[now]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++)zhu[i]=i;
	for(int i=0;i<m;i++){
		cin>>cs[i].x>>cs[i].y>>cs[i].v;
		cs[i].tj=-1; 
	}
	sort(cs,cs+m,cmp);
	for(int i=0;i<m;i++){
		if(root(cs[i].x)!=root(cs[i].y)){
			hb(cs[i].x,cs[i].y);
			zhihou[zz++]=cs[i];
		}
	}
	for(int i=0;i<k;i++){
		cin>>nv[i];
		for(int j=1;j<=n;j++){
			cin>>zhihou[zz].v;
			zhihou[zz].x=n+i+1;
			zhihou[zz].y=j;
			zhihou[zz].tj=i;
			zz++;
		}
	}
	sort(zhihou,zhihou+zz,cmp);
	ss(0);
	cout<<ans;
	return 0;
}
