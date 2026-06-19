#include<bits/stdc++.h>
using namespace std;
//奋力博 
int t;
int n,m,L,V;
//车辆数量、测速仪数量、主干道长度和道路限速 
const int N = 1e5+9,M = 1e5+9;
int p[M];
double stv(int v,int a){
	//返回时刻 
	return 1.00*((double)V-(double)v)/(double)a; 
}
int stl(int v,int a,int d){
	//制造node的L
	//注意规避精度问题 
	double ans = ((double)V*V-(double)v*v)/((double)2*(double)a);
	if(ans<0){
		if(a>0){
			return d;
		}
		return -1;
	}
	//cout<<ans<<endl;
	ans+=d;
	//cout<<ans<<endl;
	if(a>0){
		ans++;
		//cout<<a<<" "<<ans<<endl; 
		return (int)ans;
	} 
	else{
		//cout<<a<<"-"<<ans<<endl;
		if((ans-(int)ans)==0){
			ans--;
		}
		return (int)ans;
	}
	
} 
struct node{
	int d,v,a;
	int l; 
	//l记录车辆状态改变的节点,
	//当a>0时，l及往后的测速仪可以检测到超速
	//当a<0时,l及往前的测速仪可以检测到超速 
	//若不存在，赋值-1 
	
}q[N]; 
void work_node(int id){
	if(q[id].a!=0){
		//变速行驶的
		q[id].l = stl(q[id].v,q[id].a,q[id].d); 
	} 
	else{
		//对于匀速行驶的，直接判断初速 
		if(q[id].v>V){
			q[id].l = q[id].d;
		}
		else{
			q[id].l = -1;
		}
	}
	
}
struct dtd{
	//线段覆盖问题
	int l,r; 
	bool operator <(const dtd &t)const{
		return (r-l)>(t.r-t.l);
	}
};
priority_queue<dtd> qq,qr;
int ansa=0;//会被超度的车数 
int ansb=0; //开启的机器数
int half__x(int x){
	int l=1,r=m,ans = m+1;
	while(l<=r){
		int mid = (l+r)/2;
		//cout<<mid<<"-"<<p[mid]<<" "<<x<<endl;
		if(p[mid]>=x){
			r = mid-1;
			ans = mid;
		}
		else{
			l = mid+1;
		}
	}
	return ans;
}
int half__y(int x){
	int l=1,r=m,ans = 0;
	while(l<=r){
		int mid = (l+r)/2;
		if(p[mid]>x){
			r = mid-1;
		}
		else{
			l = mid+1;
			ans =mid;
		}
	}
	return ans;
}
int chf[M];//差分数组 
//后改为正常数组 
bool vis[M];
int flg;
int half_chf(int l,int r){
	if(l==r){
		return l; 
	}
	int xx = half_chf(l,(l+r)/2);
	int yy= half_chf((l+r)/2+1,r);
	if(vis[xx]){
			return xx;
		}
		if(vis[yy]){
			return yy;
		}
	if(chf[xx]<chf[yy]){
		return yy;
	}
	return xx;
}
int dc[N],dca[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	//多测记得清空数据！ 
	while(t--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>q[i].d>>q[i].v>>q[i].a;
			work_node(i);
			//cout<<q[i].l<<endl;
			if(q[i].l==-1){
				//不可能超速的车没有贡献 
				continue;
			} 
			//插入 
			dtd ini;
			if(q[i].a>0){
				ini.l = q[i].l;
				ini.r = L;
			}
			else if(q[i].a<0){
				ini.l = q[i].d;
				ini.r = q[i].l;
			}
			else{
				ini.l = q[i].d;
				ini.r = L;
				
			}
			//cout<<"push"<<ini.l<<" "<<ini.r<<endl; 
			qq.push(ini);
			qr.push(ini);
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			//cout<<p[i]<<" ";
		}
		//cout<<endl;
		p[0] = 0;
		p[m+1] = p[m]+1;
		//读入完毕，预处理完毕，开始干活
		//先处理每个点的贡献度 
		memset(chf,0,sizeof(chf));
		int txtt=0;
		while(!qq.empty()){
			int x = qq.top().l;
			int y = qq.top().r;
			//cout<<x<<"-"<<y<<endl;
			//cout<<half__x(x)<<" "<<half__y(y)<<endl;
			int xx,yy;
			xx = half__x(x);
			yy = half__y(y);
			//cout<<xx<<" "<<yy<<" "<<x<<" "<<y<<" "<<p[xx]<<" "<<p[yy]<<endl;
			if(p[xx]>y||p[yy]<x){
				//修理掉所有不可能 
				//因为这没有贡献 
				qq.pop();
				continue;
			}
			chf[xx]++;
			chf[yy+1]--; 
			qq.pop();
		}
		int a=0;
		for(int i=1;i<=m;i++){
			chf[i]+=chf[i-1];
			//cout<<p[i]<<" "<<chf[i]<<endl;
		}
		ansa =0;
		ansb = 0;
		memset(vis,0,sizeof(vis));
		while(!qr.empty()){
			int x = qr.top().l;
			int y = qr.top().r;
			//cout<<x<<"-"<<y<<endl;
			//cout<<half__x(x)<<" "<<half__y(y)<<endl;
			int xx=0,yy=0;
			xx = half__x(x);
			yy = half__y(y);
			if(p[xx]>y||p[yy]<x){
				//修理掉所有不可能 
				//因为这没有贡献 
				qr.pop();
				continue;
			}
			ansa++;
			//现在，我们可以得到贡献线段
			int id = half_chf(xx,yy);
			//cout<<xx<<" "<<yy<<" "<<id<<" "<<p[id]<<endl;
			if(!vis[id]){
				ansb++;
				vis[id] = 1;
			}
			qr.pop();
			
		}
		cout<<ansa<<" "<<m-ansb<<endl; 
	}
}
