#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD=998244353;
const int MN=100005;
const int MM=100005;
const int MT=3005; 
const int INF=0x3f3f3f3f;


int Read() {
	int t=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9') {
		t=t*10+c-'0';
		c=getchar();
	}
	return t*f;
}
void Print(int x) {
	if(x<0) {
		putchar('-');
		x=-x;
	} 
	if(x<10) {
		putchar((char)(x%10+'0')); 
	    return;
	}
	Print(x/10);
	putchar((char)(x%10+'0')); 
	return;
}

int t,n,m,l,v,p[MM],pdcs[MN],ans;
int cbcs[MT][MT];
//一定要记得改MT!!!!!!!!! 
struct cars{
	int d,v,a;
} r[MN];

void csh() {
    memset(p,0,sizeof p);
    memset(pdcs,0,sizeof pdcs);
    memset(cbcs,0,sizeof cbcs);
    n=m=l=v=ans=0;
}

bool check() {
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			if(cbcs[i][j]==1) return 1;
		}
	}
	return 0;
}
void erase(int x) {
	for(int i=1;i<=n;++i) {
		if(cbcs[i][x]==1) {
			for(int j=1;j<=m;++j) {
				cbcs[i][j]=0;
			}
		}
	}
}
int tttt[MM],vvis[MN],ans222=INF;
void dfs(int now) {
	if(now==(m+1)) {
		memset(vvis,0,sizeof vvis);
		int ttmp=0;
		for(int i=1;i<=m;++i) {
			if(tttt[i]==1) {
				ttmp++;
				for(int j=1;j<=n;++j) {
					if(cbcs[j][i]==1) {
						vvis[j]=1;
					}
				}
			} 
		}
		int nummm=0;
		for(int i=1;i<=n;++i) {
			if(vvis[i]==1) nummm++;
		}
		if(nummm==ans) {
			for(int i=1;i<=m;++i) {
//			cout<<tttt[i]<<" ";
		}
//		cout<<endl;
//		
//		for(int i=1;i<=n;++i) {
//			cout<<vvis[i]<<" ";
//		}
//		cout<<endl;
			ans222=min(ans222,ttmp);
		}
//		cout<<ttmp<<" "<<ans222<<endl;
	} else {
		tttt[now]=1;
		dfs(now+1);
		tttt[now]=0;
		dfs(now+1); 
	}
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--) {
    	csh();
    	scanf("%d%d%d%d",&n,&m,&l,&v);
    	for(int i=1;i<=n;++i) {
    		scanf("%d%d%d",&r[i].d,&r[i].v,&r[i].a);
		}
		for(int i=1;i<=m;++i) {
			scanf("%d",&p[i]);
		}
		sort(p+1,p+m+1);
//		for(int i=1;i<=m;++i) {
//			cout<<p[i]<<" ";
//		}
//		cout<<endl;
	    for(int i=1;i<=n;++i) {
	    	int vc=r[i].v,vzc=v,aa=r[i].a; 
	    	for(int j=1;j<=m;++j) {
	    		if(p[j]<r[i].d) continue;
	    		else {
	    			int s=p[j]-r[i].d;
	    			if(aa<0&&2*(-aa)*s>vc*vc) {
	    				cbcs[i][j]=0;
	    				continue;
					}
					//如果停了 
				    if(s*2*aa>(vzc*vzc-vc*vc)) {
				    	//超速
						cbcs[i][j]=1; 
						pdcs[i]=1;
					}
				    //如果没停 
				}
			} 
			//这里可以优化 如果这一点超速了后面就都超了！！！(a>0) 如果这一点不超后面就都不超（a<0) 
		}
		
	    for(int i=1;i<=n;++i) {	
//	    	for(int j=1;j<=m;++j) {
//	    		cout<<cbcs[i][j]<<" ";
//			} 
//			cout<<endl;
		    if(pdcs[i]) ans++;
		}
		printf("%d ",ans);
		ans222=INF;
//		if(m>10) {
			int ans2=0;
		while(check()) {
		int mmax=0,gl=0;
		for(int i=1;i<=m;++i) {
			int ttmp=0;
			for(int j=1;j<=n;++j) {
		        ttmp+=cbcs[j][i];	
			}
			if(ttmp>mmax){
				mmax=ttmp;
				gl=i;
			}
		}
		erase(gl);	
//		cout<<gl<<endl;
		
//	    for(int i=1;i<=n;++i) {	
//	    	for(int j=1;j<=m;++j) {
//	    		cout<<cbcs[i][j]<<" ";
//			} 
//			cout<<endl;
//		}
		ans2++;
		} 
		printf("%d\n",n-ans2);
//		} 
//		else {
//			dfs(1);
//			printf("%d",ans222);
//		}
	}

	return 0; 
} 

