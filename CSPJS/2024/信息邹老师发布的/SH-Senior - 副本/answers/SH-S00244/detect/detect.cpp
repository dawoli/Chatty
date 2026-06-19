#include<bits/stdc++.h>
using namespace std;
void file(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>10)write(x/10);
	putchar(x%10+'0');
}
typedef long double ld;
const int N=100005;
struct Segment{
	int l,r;
	bool operator<(const Segment&s){
		if(l<s.l)return 1;
		if(l>s.l)return 0;
		return r<s.r;
	}
}s[N],q[N];
int p[N],T,n,m,L,V;
int main(){
	file();
	T=read();
	while(T--){
		n=read(),m=read(),L=read(),V=read();
		for(int i=1,d,v,a;i<=n;i++){
			d=read(),v=read(),a=read();
			ld x;int l,r;//l,r记录超速区间的端点 
			if(a==0){
				l=d;
				r=v<=V?-1:L;//v<=V全程不超速, 否则全程超速 
			}
			else{
				x=1.0*(V*V-v*v)/(2*a);
				if(a>0){
					l=max(d,int(1.0*d+x)+1);//(d+x,L], l为第一个区间内的整数 
					r=L;
				}
				else{
					l=d;
					r=ceil(1.0*d+x)-1;//[d,d+x), r为最后一个区间内的整数 
				} 
			}
			s[i]=(Segment){l,r};
		//	printf("%.3Lf %d %d\n",x,s[i].l,s[i].r);
		}
	//	puts("");
		int c=0;//判定为超速车辆的个数 
		for(int i=1;i<=m;i++)p[i]=read();//单调递增
		for(int i=1;i<=n;i++){
			int l=s[i].l,r=s[i].r;
		//	p数组中查询>=l, <=r的位置 
			if(r<l)continue;
			int up=upper_bound(p+1,p+1+m,r)-p-1;
			int low=lower_bound(p+1,p+1+m,l)-p;
			if(up==0||low==m+1)continue;
		//	p[i]判定为超速(i∈[low,up])
			if(up<low)continue;
			q[++c]=(Segment){low,up};
		//	printf("%d %d %d\n",i,p[low],p[up]);
		}
	//	puts("");
		sort(q+1,q+1+c);
	//	for(int i=1;i<=c;i++)printf("%d %d\n",q[i].l,q[i].r);
	//	puts("");
		write(c),putchar(' ');
		int need=0;//需要保留的个数 
		int l=-1,r=-2,j=-1;//j表示当前处理的批次中所有区间共有的最大元素
		for(int i=1;i<=c;i++){
			if(q[i].l<=j)j=min(j,q[i].r);//只要新区间左端点小于等于j, 那么该区间仍能归于当前批次 
			else l=q[i].l,j=q[i].r,need++;//否则, 没有共有元素, 新开一个批次(需要保留的测速点+1) 
		}
		write(m-need),puts("");//输出可以撤去的数量 
	}
	return 0;
} 
