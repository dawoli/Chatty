#include<bits/stdc++.h>
using namespace std;
const int MAXX=100000007;
int num=0;
struct tcar{
	int d,v,a,dis;
}v[100005];
struct team{
	int l,r;
}x[100005],tp[100005];
int p[100005];
tcar temp[100005];
int tmp[100005];
int n,m,l,v2;
bool check[100005];
int ff[100005];
bool speedown(int i){
	if(v[i].v<=v2){
		return false; 
	}
	int s=v[i].dis-v[i].d;
	int v_=2*v[i].a*s+v[i].v*v[i].v;
	if(v_<=0){
		return false;
	}
	double v1=sqrt(v_);
	double v3=v2*1.00;
	//cout<<v1<<' ';
	if(v1>v3){
		x[++num].l=v[i].d;
		if((v2*v2-v[i].v*v[i].v)%(2*v[i].a)) x[num].r=v[i].d+floor((v2*v2-v[i].v*v[i].v)/(2*v[i].a));
		else x[num].r=v[i].d+(v2*v2-v[i].v*v[i].v)/(2*v[i].a)-1;
		return true;
	}
	else return false;
}
bool speedup(int i){
	if(v[i].v>v2){
		x[++num].l=v[i].d;
		x[num].r=l;
		return true;
	}
	int s=v[m].dis-v[i].d;
	int v_=2*v[i].a*s+v[i].v*v[i].v;
	double v1=sqrt(v_);
	double v3=v2*1.00;
	//cout<<v1<<' ';
	if(v[i].a==0){
		if(v[i].v>v2){
			x[++num].l=v[i].d;
			x[num].r=l;
			return true;
		}
		else{
			return false;
		}
	}
	if(v1>v3){
		if((v2*v2-v[i].v*v[i].v)%(2*v[i].a)) x[++num].l=v[i].d+ceil((v2*v2-v[i].v*v[i].v)/(2*v[i].a));
		else x[++num].l=v[i].d+(v2*v2-v[i].v*v[i].v)/(2*v[i].a)+1;
		x[num].r=l;
		return true;
	}
	else return false;
}
void mergesort(tcar v[],int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	mergesort(v,l,mid);
	mergesort(v,mid+1,r);
	int j=l,k=mid+1,u=l;
	for(;j<=mid&&k<=r;){
		if(v[j].d>v[k].d) temp[u++]=v[k++];
		else temp[u++]=v[j++];
	}
	for(;j<=mid;j++) temp[u++]=v[j++];
	for(;k<=r;k++) temp[u++]=v[k++];
	for(int i=l;i<=r;i++) v[i]=temp[i];
}
void mergesort2(int p[],int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	mergesort2(p,l,mid);
	mergesort2(p,mid+1,r);
	int j=l,k=mid+1,u=l;
	for(;j<=mid&&k<=r;){
		if(p[j]>p[k]) tmp[u++]=p[k++];
		else tmp[u++]=p[j++];
	}
	for(;j<=mid;j++) tmp[u++]=p[j++];
	for(;k<=r;k++) tmp[u++]=p[k++];
	for(int i=l;i<=r;i++) p[i]=tmp[i];
}
void mergesort3(team x[],int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	mergesort3(x,l,mid);
	mergesort3(x,mid+1,r);
	int j=l,k=mid+1,u=l;
	for(;j<=mid&&k<=r;){
		if(x[j].l>x[k].l) tp[u++]=x[k++];
		else tp[u++]=x[j++];
	}
	for(;j<=mid;j++) tp[u++]=x[j++];
	for(;k<=r;k++) tp[u++]=x[k++];
	for(int i=l;i<=r;i++) x[i]=tp[i];
}
void mergesort4(team x[],int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	mergesort4(x,l,mid);
	mergesort4(x,mid+1,r);
	int j=l,k=mid+1,u=l;
	for(;j<=mid&&k<=r;){
		if(x[j].r>x[k].r) tp[u++]=x[k++];
		else tp[u++]=x[j++];
	}
	for(;j<=mid;j++) tp[u++]=x[j++];
	for(;k<=r;k++) tp[u++]=x[k++];
	for(int i=l;i<=r;i++) x[i]=tp[i];
}
int dp(){
	int ans=0;
	memset(ff,false,sizeof(ff));
	for(int i=1;i<=num;i++){
		if(i==1){
			ans++;
			ff[ans]=1;
			continue;
		}
		else{
			if(x[ff[ans]].r>=x[i].l) continue;
			else{
				ans++;
				ff[ans]=i;
			}
		}
	}
	return m-ans;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		num=0;
		memset(check,false,sizeof(check));
		int ans=0;
		scanf("%d%d%d%d",&n,&m,&l,&v2);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&v[i].d,&v[i].v,&v[i].a);
		}
		for(int i=1;i<=m;i++) scanf("%d",&p[i]);
		mergesort(v,1,n);
		//cout<<"1.¼ìÑé¹é²¢ÅÅÐòÊä³ö"<<endl;
		//for(int i=1;i<=n;i++) cout<<v[i].d<<' '<<v[i].v<<' '<<v[i].a<<endl;
		mergesort2(p,1,m);
		//for(int i=1;i<=m;i++) cout<<p[i]<<' ';
		//cout<<endl;
		int i,j;
		for(i=0,j=1;i<=n&&j<=m;){
			i++;
			while(v[i].d>p[j]&&j<=m){
				j++;
			}
			v[i].dis=p[j];
		}
		//cout<<endl;
		if(i+1<=n){
			for(;i<=n;i++) v[i].dis=MAXX;
		}
		//for(int i=1;i<=n;i++) cout<<v[i].dis<<' ';
		int count=0;
		for(i=1;i<=n;i++){
			bool flag;
			if(v[i].a<0) flag=speedown(i);
			else flag=speedup(i);
			if(flag==true) count++;
		}
		cout<<count<<' ';
		mergesort3(x,1,num);
		//for(i=1;i<=num;i++) cout<<x[i].l<<' '<<x[i].r<<endl;
		for(i=1,j=1;i<=num&&j<=m;i++){
			while(x[i].l>p[j]){
				j++;
				if(j>m) break;
			}
			if(x[i].l==p[j]) x[i].l=j;
			else x[i].l=j;
		}
		mergesort4(x,1,num);
		for(i=1,j=1;i<=num&&j<=m;i++){
			while(x[i].r>p[j]){
				j++;
				if(j>m) break;
			}
			if(x[i].r==p[j]) x[i].r=j;
			else x[i].r=j-1;
		}
		cout<<dp()<<endl;
	}
	return 0;
}
