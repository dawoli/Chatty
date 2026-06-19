#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0;
	bool f=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f^=1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	if(f) return -x;
	return x;
}
void write(long long x){
	static int stk[23];
	int tp=0;
	if(x<0) putchar('-'),x=-x;
	while(x) stk[++tp]=x%10,x/=10;
	while(tp) putchar(stk[tp]+'0'),--tp;
}
void we(long long x){
	write(x);
	putchar('\n');
}
int n,m,t,aa[200010],c[200010],x[10],a[200010],ans[200010],kkk,winn[21][200010];
char ss[200010];
bool win[21][200010],p1=1,p2=1,qd[21][200010];
void dfs(int dep,int st){
	if(dep==0){
		winn[dep][st]=st;
		return;
	}
	dfs(dep-1,st);
	if(st+(1<<(dep-1))<=n) dfs(dep-1,st+(1<<(dep-1)));
	if(st-1+(1<<dep)<=n){
		int temp=(st>>dep)+1;
		if(win[dep][temp]) winn[dep][temp]=(a[winn[dep-1][temp*2]]>=dep?winn[dep-1][temp*2]:winn[dep-1][temp*2-1]);
		else winn[dep][temp]=(a[winn[dep-1][temp*2-1]]>=dep?winn[dep-1][temp*2-1]:winn[dep-1][temp*2]);
	}
	if(st==1){
		ans[(1<<dep)]=winn[dep][st];
	}
}
long long dfs2(int dep,int st,int nn){
	if(dep==0){
		winn[dep][st]=st;
		qd[dep][st]=(st<=nn);
		return st;
	}
	long long ans1,ans2;
	ans1=dfs2(dep-1,st,nn);
	ans2=dfs2(dep-1,st+(1<<(dep-1)),nn);
	int temp=(st>>dep)+1;
	if(!win[dep][temp]){
		if(!qd[dep-1][temp*2-1]){
			qd[dep][temp]=0;
			if(winn[dep-1][temp*2-1]<=nn){
				if(a[winn[dep-1][temp*2-1]]>=dep) winn[dep][temp]=winn[dep-1][temp*2-1];
				else winn[dep][temp]=winn[dep-1][temp*2],ans1-=winn[dep-1][temp*2-1];
			}
			else winn[dep][temp]=winn[dep-1][temp*2-1];
			return ans1+ans2;
		}
		if(a[winn[dep-1][temp*2-1]]>=dep){
			winn[dep][temp]=winn[dep-1][temp*2-1],qd[dep][temp]=1;
			return ans1;
		}
		else{
			winn[dep][temp]=winn[dep-1][temp*2],qd[dep][temp]=qd[dep-1][temp*2];
			return ans2;
		}
	}
	else{
		if(qd[dep-1][temp*2]){
			if(a[winn[dep-1][temp*2]]>=dep) winn[dep][temp]=winn[dep-1][temp*2],qd[dep][temp]=1;
			else winn[dep][temp]=winn[dep-1][temp*2-1],qd[dep][temp]=1;
			return winn[dep][temp];
		}
		else{
			if(winn[dep-1][temp*2]<=nn){
				if(a[winn[dep-1][temp*2]]>=dep) winn[dep][temp]=winn[dep-1][temp*2],qd[dep][temp]=0;
				else winn[dep][temp]=winn[dep-1][temp*2-1],ans2-=winn[dep-1][temp*2],qd[dep][temp]=0;
			}
			else winn[dep][temp]=winn[dep-1][temp*2-1],qd[dep][temp]=0;
		}
		return ans1+ans2;
	}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) aa[i]=read();
	for(int i=1;i<=m;i++){
		c[i]=read();
		if((c[i]&(-c[i]))!=c[i]) p1=0;
	}
	while((1<<kkk)<n) ++kkk;
	for(int i=1;i<=kkk;i++){
		scanf("%s",ss+1);
		for(int j=1;j<=(1<<(kkk-i));j++){
			win[i][j]=ss[j]-'0';
		}
	}
	t=read();
	while(t--){
		x[0]=read();
		x[1]=read();
		x[2]=read();
		x[3]=read();
		ans[1]=1;
		for(int i=1;i<=n;i++){
			a[i]=aa[i]^x[i&3];
			//cout<<a[i]<<endl;
		}
		for(int i=0;i<=kkk;i++){
			for(int j=1;j<=(1<<(kkk-i));j++) winn[i][j]=0;
		}
		if(p1) dfs(kkk,1);
		else{
			for(int i=1;i<=n;i++){
				int cccc=0;
				while((1<<cccc)<i) ++cccc;
				ans[i]=dfs2(cccc,1,i);
			}
		}
		long long as=0;
		//for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
		for(int i=1;i<=m;i++) as^=1ll*i*ans[c[i]];
		we(as);
	}
	return 0;
} 
