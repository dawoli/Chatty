#include<bits/stdc++.h>
using namespace std;
int t,n,m,len,lim,mid;
bool fl[3005];
struct node{
	int d,v,a,l,r;
}data[100005];
struct no{
	int p,cnt,l,r,f;
	bool num[3005];
}da[3005];
bool cmp(node x,node y){
	return (x.d<y.d)||((x.d==y.d)&&(x.v<y.v))||((x.d==y.d)&&(x.v==y.v)&&(x.a<y.a));
}
bool cmp2(node x,node y){
	return (x.l<y.l)||((x.l==y.l)&&(x.r<y.r));
}
bool cmp3(no x,no y){
	return x.p<y.p;
}
bool cmp4(no x,no y){
	return (x.cnt>y.cnt);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		memset(da,0,sizeof(da));
		memset(fl,false,sizeof(fl));
		scanf("%d%d%d%d",&n,&m,&len,&lim);
		mid=len/2;
		int maxx=0;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&data[i].d,&data[i].v,&data[i].a);
		for(int i=1;i<=m;i++){
			scanf("%d",&da[i].p);
		}
		sort(data+1,data+n+1,cmp);
		sort(da+1,da+m+1,cmp3);
		for(int i=1;i<=n;i++){
			if(data[i].a<=0&&data[i].v<=lim){
				data[i].l=len+1,data[i].r=len+1;
				continue;
			}
			if(data[i].v>lim&&data[i].a>=0){
				data[i].l=data[i].d,data[i].r=len;
				continue;
			}
			if(data[i].v==lim&&data[i].a>0){
				data[i].l=data[i].d+1,data[i].r=len;
				continue;
			}
			if(data[i].v>lim&&data[i].a<0){
				int s=floor((lim*lim-data[i].v*data[i].v)/2.0/data[i].a);
				data[i].l=data[i].d,data[i].r=min(data[i].d+s,len);
				continue;
			}
			if(data[i].v<lim&&data[i].a>0){
				int s=floor((lim*lim-data[i].v*data[i].v)/2.0/data[i].a);
				data[i].l=data[i].d+s,data[i].r=len;
			}
//			cout<<data[i].l<<' '<<data[i].r<<endl;
		}
		int c=0,ans=0,ans2=0;
		sort(data+1,data+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(data[i].l>len) continue;
			bool f=false;
			for(int j=1;j<=m;j++){
				if(da[j].p>=data[i].l&&da[j].p<=data[i].r){
					f=true;
					da[j].num[i]=true;
					da[j].cnt++;
					da[j].l=min(da[j].l,data[i].l);
					da[j].r=max(da[j].r,data[i].r);
				}
			}
			if(f) ans++;
		}
		
		for(int i=1;i<=m;i++){
			if(da[i].f==true) continue;
			sort(da+i,da+m+1,cmp4);
			bool f=false;
			for(int j=1;j<=n;j++){
				if(c==n) break;
				if(da[i].num[j]&&fl[j]==false){
					fl[j]=true;
					c++;
					f=true;
				}
			}
			if(f){
				for(int k=i;k<=m;k++){
					if(da[k].p>=da[i].l&&da[k].p<=da[i].r){
						bool flag=true;
						for(int l=1;l<=n;l++){
							if(da[k].num[l]&&!da[i].num[l]) flag=false;
						}
						if(flag) da[k].f=true;
					}
						
				}
				ans2++;
			}
		}
		printf("%d %d\n",ans,m-ans2);
	}
	return 0;
}
