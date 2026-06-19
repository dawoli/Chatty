#include <bits/stdc++.h>
using namespace std;
int T,n,m,L,V,p[100020],y[100020],ans,vis[100020],sz;
typedef struct rp{
	int d,v,a,l,r;
	bool ov,dtd;
}ca;
ca car[100020];
vector<ca> dcar;
vector<int> yp[100020];
void init(int i){
	if(car[i].a==0){
		if(car[i].v>V){
			car[i].l=car[i].d;
			car[i].r=L;
			car[i].ov=1;
		}
		else car[i].ov=0;
	}
	else if(car[i].a>0){
		if(car[i].v>V){
			car[i].l=car[i].d;
			car[i].r=L;
			car[i].ov=1;
		}
		else{
			int s=floor((V*V-car[i].v*car[i].v)/(2.0*car[i].a));
			double s1=(V*V-car[i].v*car[i].v)/(2.0*car[i].a);
			car[i].l=car[i].d+s;
			if(s==s1)car[i].l++;
			car[i].r=L;
			car[i].ov=(car[i].d+s<=L);
		}
	}
	else{
		if(car[i].v<V)car[i].ov=0;
		else{
			int s=floor((V*V-car[i].v*car[i].v)/(2.0*car[i].a));
			double s1=(V*V-car[i].v*car[i].v)/(2.0*car[i].a);
			car[i].l=car[i].d;
			car[i].r=min(car[i].d+s,L);
			if(s==s1)car[i].r--;
			car[i].ov=1;
		}
	}
}//初始化，计算超速区间，注意到测速仪必然在整数位置;已检测无误
bool cmo(ca x,ca y){
	return x.l<y.l;
}
int getsz(vector<int> x){
	int pmt=0;
	for(int i=0;i<x.size();i++){
		if(!vis[x[i]])pmt++;
	}
	return pmt;
}
bool cmp(vector<int> x,vector<int> y){
	return getsz(x)>getsz(y);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		ans=0,sz=0;
		memset(y,0,sizeof(y));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++)yp[i].resize(0);
		dcar.resize(0);
		for(int i=1;i<=n;i++){
			cin>>car[i].d>>car[i].v>>car[i].a;
			init(i);
			if(car[i].ov)dcar.push_back(car[i]);
		}
		sort(dcar.begin(),dcar.end(),cmo);
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		int tmp=1;
		for(int i=0;i<dcar.size();i++){
			for(int j=1;j<=m;j++){
				if(dcar[i].l<=p[j]&&dcar[i].r>=p[j]){
					y[i]++;
					yp[j].push_back(i);
				}
			}
			if(y[i])ans++,tmp++;
		}
		cout<<ans<<" ";
		//如果所有p都开，哪些区间里有p;同时做好再次预处理，为下一问做准备;O(mn)但保证无错 
		ans=0;
		sort(yp+1,yp+m+1,cmp);
		int eee=0;
		for(int j=1;j<=m;j++){
			int p=0;
			for(int k=0;k<yp[j].size();k++){
				if(vis[yp[j][k]])p++;
			}
			if(p==yp[j].size())continue;
			for(int k=0;k<yp[j].size();k++){
				if(!vis[yp[j][k]]){
					vis[yp[j][k]]=1;
					sz++;
				}
			}
			cout<<sz;
			eee++;
			if(sz==tmp-1){
				ans=eee;
			}
		}
		cout<<ans<<endl;
		//对给定的区间，哪些p删除不影响查询，好像能贪(更正：就是贪) 
	}
	return 0;
}
