#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
int n,m,L,V;
int d[maxn];//起点 
int v[maxn];//起始速度 
int a[maxn];//加速度 
int p[maxn];//测速仪位置 
int l[maxn],r[maxn];//记录每一辆车的超速区间 
struct qujian{
	int l,r;
}q[maxn];
struct node{
	int l,r,siz;
}car[maxn];
bool overspeed[maxn];//记录有没有超速 
bool cmp(node x,node y){
	return x.siz<y.siz;
}
void init(){
	for(int i=1;i<=n;i++){
		l[i]=r[i]=0;
		overspeed[i]=false;
		q[i].l=q[i].r=0;
	}
	return ;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	t=read();
	while(t--){
		init();
		n=read(),m=read(),L=read(),V=read();
		for(int i=1;i<=n;i++){
			d[i]=read(),v[i]=read(),a[i]=read();
		}
		for(int i=1;i<=m;i++){
			p[i]=read();
		}
		if(n>3000||m>3000){
			int ltag=0;
			for(int i=1;i<=n;i++){
				bool flag1=false;
				if(v[i]>V&&d[i]<=p[m]){
					overspeed[i]=true;
				}
			}
			int cnt1=0;
			for(int i=1;i<=n;i++){
				if(overspeed[i]) cnt1++;
			}//Q1
			
			write(cnt1);putchar(' ');
			if(cnt1==0){
				write(m);
			}else{
				write(m-1);
			}
			putchar('\n');
			continue;
		}
		int ltag=0;
		for(int i=1;i<=n;i++){
			int vt;//最终速度 
			bool flag1=false;
			for(int j=1;j<=m;j++){
				if(p[j]>=d[i]){
					flag1=true;
					ltag=j;
					break;
				}
			}
			if(!flag1){
				ltag=m+1;
			}//求从哪个开始能测到速 
			if(a[i]>0){
				for(int j=ltag;j<=m;j++){
					vt=2*a[i]*(p[j]-d[i])+v[i]*v[i];
					if(vt>V*V){
						overspeed[i]=true;
						l[i]=j;r[i]=m;
						break;
					}
				}
			}else if(a[i]==0){
				if(v[i]>V&&d[i]<=p[m]){
					overspeed[i]=true;
					l[i]=ltag,r[i]=m; 
				}
			}else{
				for(int j=ltag;j<=m;j++){
					vt=2*a[i]*(p[j]-d[i])+v[i]*v[i];
					if(vt>V*V){
						overspeed[i]=true;
					}else{
						if(overspeed[i]){
							l[i]=ltag;r[i]=j-1;
						}
						break;
					}
				}
				if(overspeed[i]&&(l[i]==0||r[i]==0)){
					l[i]=ltag,r[i]=m;
				}//减速到最后还是超速 
			}
		}
		int cnt1=0;
		for(int i=1;i<=n;i++){
			if(overspeed[i]) cnt1++;
		}//Q1
		
		int ccnt=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(l[i]!=0&&r[i]!=0){
				ccnt++;
				car[ccnt].l=l[i];
				car[ccnt].r=r[i];
				car[ccnt].siz=r[i]-l[i];
			}
		}
		sort(car+1,car+ccnt+1,cmp);
		/*
		for(int i=1;i<=ccnt;i++){
			cout<<"i:"<<i<<" "<<car[i].l<<" "<<car[i].r<<"\n";
		}
		cout<<"\n";
		*/
		for(int i=1;i<=ccnt;i++){
			//cout<<"overspeed:"<<overspeed[i]<<"\n";
			if(cnt2==0){
				cnt2++;
				q[cnt2].l=car[i].l;
				q[cnt2].r=car[i].r;
			}
			/*
			for(int j=1;j<=cnt2;j++){
				cout<<q[j].l<<" "<<q[j].r<<"\n";
			}
			cout<<"\n";
			*/
			bool flag=false;//是否已合并 
			for(int j=1;j<=cnt2;j++){
				if(q[j].l>=car[i].l&&q[j].r<=car[i].r){
					flag=true;
					break;
				}else if(q[j].l<=car[i].r&&q[j].r>=car[i].r){
					flag=true;
					q[j].r=car[i].r;
					break;
				}else if(q[j].r>=car[i].l&&q[j].l<=car[i].l){
					flag=true;
					q[j].l=car[i].l;
					break;
				}
			}
			if(!flag){
				cnt2++;
				q[cnt2].l=car[i].l;
				q[cnt2].r=car[i].r;
			}
		}
		//cout<<"ans:";
		write(cnt1);putchar(' ');
		write(m-cnt2);putchar('\n');
	}
	return 0;
}
