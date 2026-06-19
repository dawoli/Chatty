#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int da=100010;
struct qujian{
	int l,r;
}qj[da];
ll t,n,m,L,V,tnt,cnt;
ll d[da],v[da],a[da],p[da],yx[da];
int read(){
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
bool cmp(qujian X,qujian Y){
	if(X.l==Y.l) return X.r>Y.r;
	return X.l<Y.l;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	t=read();
	while(t--){
		tnt=cnt=0;
		n=read(),m=read(),L=read(),V=read();
		for(int i=1;i<=n;i++){
			d[i]=read(),v[i]=read(),a[i]=read();
		}
		for(int i=1;i<=m;i++){
			p[i]=read();
		}
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++){
			if(p[m]<d[i]) continue;
			if(a[i]==0){
				if(v[i]>V&&p[m]>=d[i]){
					cnt++;
					int l=1,r=m,mid;
					while(l<r){
						mid=(l+r)/2;
						if(p[mid]<d[i]) l=mid+1;
						else r=mid;
					}
					qj[cnt].l=l,qj[cnt].r=m;
				}
			}
			if(a[i]<0){
				if(v[i]<=V||p[m]<d[i]) continue;
				int l=1,r=m,mid;
				while(l<r){
					mid=(l+r)/2;
					if(p[mid]<d[i]) l=mid+1;
					else r=mid;
				}
				if((-2)*a[i]*(p[l]-d[i])<v[i]*v[i]-V*V){
					cnt++;
					qj[cnt].l=l,r=m;
					while(l<r){
						mid=(l+r+1)/2;
						if((-2)*a[i]*(p[mid]-d[i])<v[i]*v[i]-V*V) l=mid;//³¬ËÙ 
						else r=mid-1;
					}
					qj[cnt].r=l;
				}
			}
			if(a[i]>0){
				if(2*a[i]*(p[m]-d[i])<=V*V-v[i]*v[i]) continue;
				int l=1,r=m,mid;
				while(l<r){
					mid=(l+r)/2;
					if(p[mid]<d[i]) l=mid+1;
					else r=mid;
				}
				//cout<<i<<' '<<l<<endl;
				r=m;
				while(l<r){
					mid=(l+r)/2;
					if(2*a[i]*(p[mid]-d[i])>V*V-v[i]*v[i]) r=mid;//³¬ËÙ 
					else l=mid+1;
				}
				qj[++cnt].l=l,qj[cnt].r=m; 
			}
			//cout<<i<<' '<<cnt<<' '<<qj[cnt].l<<' '<<qj[cnt].r<<endl;
		}
		sort(qj+1,qj+cnt+1,cmp);
		int bb=1;
		while(bb<=cnt){
			tnt++;
			int l=qj[bb].l,r=qj[bb].r;
			while(bb<cnt){
				if(qj[bb+1].l>r) break;
				r=min(r,qj[++bb].r);
			}
			bb++;
		}
		cout<<cnt<<' '<<m-tnt<<endl;
	}
	return 0;
} 
