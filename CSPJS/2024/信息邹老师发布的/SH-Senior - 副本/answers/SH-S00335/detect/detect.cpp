#include<bits/stdc++.h>
using namespace std;
int n,m,L,V,p[100009],t,ans,ans2,sub[100009],sum[100009];
struct car{
	int d,v,a,flag,f,l,r,mark,done;	//flag=1 safe flag=-1 dangerous
	double s,x;
}h[100009],emp;
bool A(){
	for(int i=1;i<=n;i++)
		if (h[i].a!=0)
			return 0;
	return 1;
}
bool B(){
	for(int i=1;i<=n;i++)
		if (h[i].a<=0)
			return 0;
}
bool C(){
	for(int i=1;i<=n;i++)
		if (h[i].a>=0)
			return 0;
}
void solveA(){
	if (ans==0){
		ans2=m;
		return ;
	}
	else ans2=m-1;
	return ;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		ans=ans2=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) h[i]=emp;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&h[i].d,&h[i].v,&h[i].a);
		for(int i=1;i<=m;i++) scanf("%d",&p[i]);
		for(int i=1;i<=n;i++){
//			cout<<ans<<' ';
			if (h[i].a==0&&h[i].v>V) h[i].flag=-1;
			else if (h[i].a==0&&h[i].v<=V) h[i].flag=1;
			else if (h[i].a<0&&h[i].v<=V) h[i].flag=1;
			else if (h[i].a>0&&h[i].v>V) h[i].flag=-1;
			else{
				h[i].x=h[i].d+1.0*(V*V-h[i].v*h[i].v)/(2*h[i].a);
				if (h[i].a>0) h[i].f=ceil(h[i].x+0.0001);
				if (h[i].a<0) h[i].f=floor(h[i].x-0.0001);
			}
//			cout<<h[i].x<<' '<<h[i].flag<<endl;
			//查询a~b有无摄像头
			if (h[i].flag==1) continue;
			int beg=lower_bound(p+1,p+m+1,h[i].d)-p;
			int enl=lower_bound(p+1,p+m+1,h[i].f)-p;
			h[i].l=beg;
			h[i].r=enl;
			if (beg==m+1) continue;
			if (h[i].flag==-1){
				ans++;
				h[i].mark=1;
				continue;
			}
			if (h[i].a>0&&enl!=m+1){
				ans++;
				h[i].mark=1;
				continue;
			}
			if (h[i].a<0&&beg!=enl){
				ans++;
				h[i].mark=1;
				continue;
			}
		}
		cout<<ans<<' ';
		for(int i=1;i<=n;i++){
			if (p[h[i].r]>h[i].f) h[i].r--;
			if (h[i].mark==0) continue;
			if (h[i].flag==-1) h[i].r=m;
			if (h[i].a>0&&h[i].flag!=-1){
				h[i].l=h[i].r;
				h[i].r=m;
			}
			if (h[i].r>m) h[i].r=m;
//			cout<<h[i].x<<' '<<h[i].flag<<' '<<h[i].mark<<' '<<h[i].l<<' '<<h[i].r<<endl; 
		}
		if (A()) solveA();
		else{
			memset(sub,sizeof(sub),0);
			memset(sum,sizeof(sum),0);
			int num=0;
			for(int i=1;i<=n;i++)
				if (h[i].mark==1)
					num++;
			int k=num;
			for(int i=1;i<=n;i++){
				if (h[i].mark==1){
					sub[h[i].l]++;
					sub[h[i].r+1]--;
//					cout<<h[i].l<<' '<<h[i].r<<endl;
				}
			}
			for(int i=1;i<=m;i++) sum[i]=sum[i-1]+sub[i];
			while(k>0){
//			for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
//			cout<<endl;
				int maxx=max_element(sum+1,sum+m+1)-sum;
				for(int i=1;i<=n;i++){
					if (h[i].mark==1&&h[i].done==0){
						if (h[i].l<=maxx&&h[i].r>=maxx){
							h[i].done=1;
							sub[h[i].l]--;
							sub[h[i].r+1]++;
							k--;
						}
					}
				}
				for(int i=1;i<=m;i++) sum[i]=sum[i-1]+sub[i];
				ans2++;	
			}
			ans2=m-ans2;
		}
		cout<<ans2<<endl;
	}
	return 0;
}
