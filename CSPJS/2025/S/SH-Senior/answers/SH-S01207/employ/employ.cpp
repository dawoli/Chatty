#include<bits/stdc++.h>
using namespace std;
long long n,m,c[509],fai,f[509],cnt,qzj[509],ans;
bool fs,vst[509];
string s;
void dfs(long long sum,int cur,int fq){
	if(sum==m){
		//cout<<cur<<endl;
		ans+=qzj[n-cur+1];
		ans%=998244353;
		return;
	}
	if(cur==cnt+1)return;
	for(int i=1;i<=n;++i){
		if(!vst[i]){
			vst[i]=1;
			if(c[i]>f[cur]+fq)dfs(sum+1,cur+1,fq);
			else dfs(sum,cur+1,fq+1);
			vst[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	qzj[0]=1;
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i){
		qzj[i]=qzj[i-1]*i;
		qzj[i]%=998244353;
		if(s[i-1]=='1'){
			//cout<<i<<" "<<fai<<"\n";
			f[++cnt]=fai;
		}
		else fai++;
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	dfs(0,1,0);
	cout<<ans;
	return 0;
}
