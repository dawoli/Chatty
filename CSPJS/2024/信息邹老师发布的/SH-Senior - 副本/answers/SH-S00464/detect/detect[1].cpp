#include<bits/stdc++.h>
using namespace std;
int n,m,L,V,T,d[100002],v[100002],a[100002],p[100002],pre[100002],sum;
bool cmp(int a,int b){return a<b;}
int serch(int x){//x   jin_tou
	for(int i=1;i<=m;i++){
		if(p[i]>=x) return i;
	}
	return m;
}
int serch2(int x,int j){//yuan  pai
	int y=serch(x);
	for(int i=y;i<=m;i++){
		if(sqrt(v[i]*v[i]+2*a[i]*(p[i]-x))>V) return i-1;
	}
	return m;
}
int serch3(int x,int j){
	int y=serch(x);
	for(int i=y;i<=m;i++){
		if(sqrt(v[i]*v[i]+2*a[i]*(p[i]-x))>V) return i;
	}
	return m;
}
struct stu{
	int x,y;
}b[100002];
bool cmp2(const stu& a,const stu& b){
	return a.y<b.y;
}
int check(){//在1到m个摄像头
	int last,ans=0,ff=1;
	for(int i=2;i<=n;i++){
		if(b[i].y==0){
			continue;
		}
		if(ff){
			last=b[i].y; ans++;
			ff=0;
		}
		if(b[i].x<=last&&b[i].y>=last) continue;
		last=b[i].y;
		ans++;
	}
	return ans;
}
void fff(){
	for(int i=1;i<=n;i++){
		if(d[i]>p[m]){
			continue;
		}
		if(v[i]>V){
			sum++;
		}
	}
	for(int i=1;i<=n;i++){
		if(v[i]<=V) continue;
		else{
			int xx=serch(d[i]);
			b[i].x=xx; b[i].y=m;
		}
	}
	cout<<sum<<endl;
	cout<<m-check()<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		int f=1;
		cin>>n>>m>>L>>V;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0) f=0;
		}
		for(int i=1;i<=m;i++) cin>>p[i];
		sort(p+1,p+m+1,cmp);
		if(f){
			fff();
			continue;
		}
		for(int i=1;i<=n;i++){
			int xx=serch(d[i]);
			if(d[i]>p[m]){
				continue;
			}
			else if(d[i]==p[m]){
				if(v[i]>V){
					sum++;
					b[i].x=m; b[i].y=m;
				}
				continue;
			}
			if(a[i]==0){
				if(v[i]>V){
					sum++;
					b[i].x=xx; b[i].y=m;
				}
			}
			if(a[i]>0){
				if(v[i]>V){
					sum++;
					b[i].x=xx; b[i].y=m;
				}
				else{
					if(sqrt(v[i]*v[i]+2*a[i]*(p[m]-d[i]))>V){
						int e=serch3(d[i],i);
						sum++;
						b[i].x=e; b[i].y=m;
					}
				}
			}
			else{
				if(v[i]<=V) continue;
				else{
					if(sqrt(v[i]*v[i]+2*a[i]*(p[xx]-d[i]))>V){
						sum++;
						int e=serch2(d[i],i);
						b[i].x=xx; b[i].y=e;
					}
				}
			}
		}
		cout<<sum-1<<endl;
		sort(b+1,b+n+1,cmp2);
		cout<<m-check()+1<<endl;
	}
	return 0;
}
