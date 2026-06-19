#include<bits/stdc++.h>
using namespace std;
int n,m,l,v;
int p[100010];
struct Car{
	int d,v,a;
};
int cnt;
Car c[100010];
int al[100010],ar[100010];
int x[100010],y[100010],t[100010];
int xb,yb;
void clear(){
	for(int i=1;i<=max(n,m);++i){
		c[i].d=c[i].v=c[i].a=x[i]=y[i]=al[i]=ar[i]=0;
	    p[i]=t[i]=0;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		bool A=false,B=false,C=false;
		cnt=0;
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
        }
		for(int i=1;i<=m;++i)
	        scanf("%d",&p[i]);
	    cnt=0;
	    for(int i=1;i<=n;++i){
	    	if(c[i].a>0){
	    		int vv=(v*v-c[i].v*c[i].v);
	    		if(l*2*c[i].a<=vv)    continue;
	    		else    ++cnt;
	    		int lb=1,rb=m;
	    		while(lb<=rb){
	    			int mid=(lb+rb)/2;
	    			if((p[mid]-c[i].d)*2*c[i].a<=vv)    lb=mid+1;
	    			else                       rb=mid-1;
				} 
				al[i]=lb;
				ar[i]=m;
                if(c[i].d>p[m]||c[i].d>p[lb])    cnt--;
			}
			else if(c[i].a==0){
				if(c[i].v<=v)    continue;
				else    ++cnt;
				int lb=1,rb=m;
				while(lb<=rb){
					int mid=(lb+rb)/2;
					if(p[mid]>c[i].d)    rb=mid-1;
					else                  lb=mid+1;
				}
				al[i]=lb;
				ar[i]=m;
				if(c[i].d>p[m]||c[i].d>p[lb])    cnt--;
			}
			else{
				int lb=1,rb=m;
				while(lb<=rb){
					int mid=(lb+rb)/2;
					if(p[mid]>=c[i].d)    rb=mid-1;
					else                  lb=mid+1;
				}
				int vv=c[i].v*c[i].v+2*c[i].a*(p[lb]-c[i].d);
				if(vv<=v*v)    continue;
				else    ++cnt;	
				int vvv=v*v-c[i].v*c[i].v;
	    		int lbb=1,rbb=m;
	    		while(lbb<=rbb){
	    			int mid=(lbb+rbb)/2;
	    			if((p[mid]-c[i].d)*2*c[i].a<=vvv)    rbb=mid-1;
	    			else                       lbb=mid+1;
				}
				al[i]=lb; ar[i]=rbb;				
			}
		}
		cout<<cnt<<" ";
		for(int i=1;i<=n;++i){
		    t[ar[i]]++;
		}
		int ans=0;
		for(int i=1;i<=m;++i)
		    if(t[i])
		        ans++;
		cout<<m-ans<<'\n';
	}
	return 0;
}
