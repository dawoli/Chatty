#include<bits/stdc++.h>
using namespace std;
const int da=200010;
int t,n,m,ap[da],c[da],d[30][da],K,x[4];
int a[da],id[da],gj[da],aa[da];
string s;
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
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		ap[i]=read();
	}
	int bb=1,cc; 
	for(int i=1;i<=m;i++){
		c[i]=read();
		cc=log2(c[i]);
		if(c[i]!=1<<cc) bb=0;
	}
	K=log2(n-1)+1;
	for(int i=1;i<=K;i++){
		int w=1<<(K-i);
		cin>>s;
		for(int j=1;j<=w;j++){
			d[i][j]=s[j-1]-'0';
		}
	}
	t=read();
	if(bb==0){
		while(t--){
			x[0]=read(),x[1]=read(),x[2]=read(),x[3]=read();
			long long ans=0,cnt;
			for(int i=1;i<=m;i++){
				int k=log2(c[i]-1)+1;
				K=1<<k;
				for(int j=1;j<=c[i];j++){
					a[j]=x[j%4]^ap[j];
					id[j]=j;
					gj[j]=0;
				}
				for(int j=c[i]+1;j<=K;j++){
					a[j]=0;
					id[j]=j;
					gj[j]=0;
				}
				for(int u=c[i]+1;u<=K+1;u++){
					for(int j=1;j<=K;j++){
						aa[j]=a[j];
					}
					a[u]=100;
					for(int w=1;w<=k;w++){
						int ww=1<<(k-w);
						for(int j=1;j<=ww;j++){
							int bb=2*j-1;
							if(d[w][j]==0){
								if(a[2*j-1]<w) bb++;
							}
							if(d[w][j]==1){
								if(a[2*j]>=w) bb++;
							}
							a[j]=a[bb];
							id[j]=id[bb];
						}
					}
					gj[id[1]]=1;
					for(int j=1;j<=K;j++){
						a[j]=aa[j];
						id[j]=j;
					}
				}
				cnt=0;
				for(long long j=1;j<=K;j++){
					if(gj[j]) cnt+=j;
				}
				ans=ans^(cnt*i);
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	while(t--){
		x[0]=read(),x[1]=read(),x[2]=read(),x[3]=read();
		long long ans=0,cnt;
		for(int i=1;i<=m;i++){
			int k=log2(c[i]);
			for(int j=1;j<=c[i];j++){
				a[j]=x[j%4]^ap[j];
				id[j]=j;
			}
			for(int w=1;w<=k;w++){
				int ww=1<<(k-w);
				for(int j=1;j<=ww;j++){
					int bb=2*j-1;
					if(d[w][j]==0){
						if(a[2*j-1]<w) bb++;
					}
					if(d[w][j]==1){
						if(a[2*j]>=w) bb++;
					}
					a[j]=a[bb];
					id[j]=id[bb];
				}
			}
			cnt=id[1];
			ans=ans^(cnt*i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
