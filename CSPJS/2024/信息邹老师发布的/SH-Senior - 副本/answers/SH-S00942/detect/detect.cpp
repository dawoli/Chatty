#include<bits/stdc++.h>
using namespace std;
int t,n,m,c,ans1,ans2;
int vis[100005];
double l,v,di,vi,ai;
double s[100005],e[100005];
struct node{
	int ind,cnt;
}p[100005];
bool cmp(node p1,node p2){
	return p1.cnt>p2.cnt;
}
void check(int i){
	if(ai<0){
		if(vi<=v){
			s[i]=-1;
			e[i]=-1;
		}
		else{
			s[i]=di;
			double dd=(double)(v*v-vi*vi)/(2*ai);
			if(di+dd>l) e[i]=l;
			else e[i]=di+dd-0.1;
		}
	}
	else if(ai==0){
		if(vi<=v){
			s[i]=-1;
			e[i]=-1;
		}
		else{
			s[i]=di;
			e[i]=l;
		}
	}
	else{
		if(vi>v){
			s[i]=di;
			e[i]=l;
		}
		else{
			double dd=(double)(v*v-vi*vi)/(2*ai);
			if(di+dd>=l){
				s[i]=-1;
				e[i]=-1;
			}
			else{
				s[i]=di+dd+0.1;
				e[i]=l;
			}
		}
	}
}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	t=read();
	while(t--){
		ans1=0;
		n=read(),m=read(),l=read(),v=read();
		for(int i=1;i<=n;i++){
			s[i]=0;
			e[i]=0;
			vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			di=read(),vi=read(),ai=read();
			check(i);
		}
		for(int i=1;i<=m;i++){
			p[i].ind=read();
			p[i].cnt=0;
			for(int j=1;j<=n;j++){
				if(s[j]<=p[i].ind&&p[i].ind<=e[j]){
					if(vis[j]==0){
						p[i].cnt++;
						vis[j]=1;
						ans1++;
					}
				}
			}
		}
		/*sort(p+1,p+m+1,cmp);
		int c=ans1;
		int i=1;
		while(c>0){
			c-=p[i].cnt;
			i++;
		}
		ans2=i;*/
		if(ans1==0) ans2=m;
		else ans2=m-1;
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
