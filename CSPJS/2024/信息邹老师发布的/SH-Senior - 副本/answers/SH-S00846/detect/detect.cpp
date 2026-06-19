#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int l,r,a,v,x;
}a[N]; 
bool cmp(node x,node y){
	if(x.l!=y.l) return x.l<y.l;
	else return x.r<y.r; 
} 
int b[N],m,n,L,V,T;
double calc(double x,double a,double v0){
	double dis;
	if(a==0) return -1;
	dis=((V*V-v0*v0)/(2*a))+x;
	return dis;
}
int check2(double x){
	int l=1,r=m;
	while(l<r){
		int mid=(l+r)/2;
		if(b[mid]<=x) l=mid+1;
		else r=mid;
	}
	return l;
}
void check(int x){
	if(a[x].a<=0&&a[x].v<=V){a[x].l=a[x].r=-1; return;}
	if(a[x].x>b[m]){a[x].l=a[x].r=-1; return;}
	double dis1=calc(a[x].x,a[x].a,a[x].v);
	if(a[x].v<V&&a>0){
		if(dis1>=b[m]) a[x].l=a[x].r=-1;
		else a[x].l=check2(dis1),a[x].r=m;
	}
	else if(a[x].v==V&&a>0){
		if(a[x].x==b[m]) a[x].l=a[x].r=-1;
		else a[x].l=check2((double)a[x].x),a[x].r=m;
	}
	else if(a[x].v>V){
		int num1=check2((double)a[x].x),num2=check2(dis1);
//		cout<<"i="<<x<<" num1="<<num1<<" num2="<<num2<<endl;
		if(b[num1-1]==a[x].x&&num1>1) num1--;
		if(a[x].a>=0) {a[x].l=num1,a[x].r=m;}
		else{
			if((double)dis1>b[m]) num2=m;
			else if((double)dis1==b[m]) num2=m-1; 
			else if((double)b[num2-1]==dis1) num2-=2;
			else num2-=1;
			a[x].l=num1,a[x].r=num2;
		}
	}
//	cout<<"i="<<x<<" dis1="<<dis1<<endl;
	if(a[x].l>a[x].r) a[x].l=a[x].r=-1;
}
/*
q1:求区间内有指定点的区间数
q2：删除若干点，使区间数不变 
*/ 
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].v,&a[i].a);
		}
		for(int i=1;i<=m;i++) cin>>b[i];
		for(int i=1;i<=n;i++) check(i);
//		for(int i=1;i<=n;i++) cout<<"l="<<a[i].l<<" r="<<a[i].r<<endl;
		sort(a+1,a+n+1,cmp);
		int i=1,cnt,left,right,ans1,ans2=m;
		while(a[i].l==-1) i++;
		ans1=n-i+1; i--;
		while(i<n){
			++i;
			if(i==n) break;
			left=a[i].l,right=a[i].r;
			while(a[i].l==left&&i<n) i++;
			if(right<a[i].l) {ans2--;}
			else if(a[i].l<=right&&a[i].r>right) {a[i].r=right;}
			i--;
		}
		ans2--;
		if(ans1==0) ans2=m;
		cout<<ans1<<" "<<ans2<<endl;
//		cout<<"test="<<calc(0,-2,4)<<endl;
	}
	return 0;
}
