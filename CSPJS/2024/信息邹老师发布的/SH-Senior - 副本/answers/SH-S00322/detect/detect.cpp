#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int T,n,m,L,V,d[N],v[N],a[N],p[N];
int b[N];
bool chao[N];
bool check(int cnt){
	for(int i=1;i<=n;i++){
		if(chao[i]){
			bool flag=0;
			for(int j=1;j<=cnt;j++){
				if(a[i]==0){
					if(v[i]>V)
						if(b[j]>=d[i])flag=1;
				}
				else if(a[i]<0){
					if(v[i]>V&&b[j]>=d[i]&&b[j]
						<=d[i]+(V*V-v[i]*v[i])/(2*a[i])-((V*V-v[i]*v[i])%(2*a[i])==0))
						flag=1;
				}
				else{
					if(v[i]>V)
						if(b[j]>=d[i])flag=1;
					if(v[i]<=V)
						if(b[j]>=d[i]&&b[j]>=d[i]+(V*V-v[i]*v[i])/(2*a[i])+1)
							flag=1;
				}
			}
			if(flag==0)return 0;
		}
	}
	return 1;
}
int bao(int i,int cnt){
	if(i==m+1){
		if(check(cnt)){
			return cnt;
		}
		else return m;
	}
	int j=bao(i+1,cnt);
	b[++cnt]=p[i];
	return min(j,bao(i+1,cnt));
}
void solve1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		chao[i]=0;
		for(int j=1;j<=m;j++){
			if(a[i]==0){
				if(v[i]>V)
					if(p[j]>=d[i])chao[i]=1;
			}
			else if(a[i]<0){
				if(v[i]>V&&p[j]>=d[i]&&p[j]
					<=d[i]+(V*V-v[i]*v[i])/(2*a[i])-((V*V-v[i]*v[i])%(2*a[i])==0))
					chao[i]=1;
			}
			else{
				if(v[i]>V)
					if(p[j]>=d[i])chao[i]=1;
				if(v[i]<=V)
					if(p[j]>=d[i]&&p[j]>=d[i]+(V*V-v[i]*v[i])/(2*a[i])+1)
						chao[i]=1;
			}
		}
		ans+=chao[i];
	}
	cout<<ans<<" "<<m-bao(1,0)<<endl;
}
void solveA(){
	int j=p[m],ans=0;
	for(int i=1;i<=n;i++){
		if(v[i]>V){
			if(j>=d[i])ans++;
		}
	}
	if(ans!=0)
		cout<<ans<<" "<<m-1<<endl;
	else
		cout<<ans<<" "<<m<<endl;
}
void solveB(){
	int j=p[m],ans=0;
	for(int i=1;i<=n;i++){
		if(v[i]>V){
			if(j>=d[i])ans++;
		}
		else
			if(j>=d[i]&&j>=d[i]+(V*V-v[i]*v[i])/(2*a[i])+1)ans++;
	}
	if(ans!=0)
		cout<<ans<<" "<<m-1<<endl;
	else
		cout<<ans<<" "<<m<<endl;
}
int af[N],be[N];
int find1(int t){//找大的 
	int l=1,r=m+1;
	while(l!=r){
		int mid=(r+l)/2;
		if(t<=p[mid])r=mid;
		else l=mid+1;
	}
	return l;
}
int find2(int t){//找小的 
	int l=0,r=m;
	while(l!=r){
		int mid=(r+l+1)/2;
		if(t<p[mid])r=mid-1;
		else l=mid;
	}
	return l;
}
struct kk{
	int l,r;
}jj[N];
bool cmp(const kk&a,const kk&b){
	return a.r<=b.r;
}
void solve(){
	int ans=0;
	p[m+1]=L;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			if(v[i]>V)af[i]=d[i],be[i]=L;
			else af[i]=L+1,be[i]=-1;
		}
		else if(a[i]<0){
			if(v[i]>V)
				af[i]=d[i],be[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i])-((V*V-v[i]*v[i])%(2*a[i])==0);
			else af[i]=L+1,be[i]=-1;
		}
		else{
			if(v[i]>V)af[i]=d[i],be[i]=L;
			if(v[i]<=V)
				af[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i])+1,be[i]=L;
		}
	}
	for(int i=1;i<=n;i++){
		if(af[i]>be[i])continue;
		int l=find1(af[i]),r=find2(be[i]);
		if(l>r)continue;
		ans++;
		jj[ans].l=l,jj[ans].r=r;
	}
	sort(jj+1,jj+ans+1,cmp);
	int cnt=0,num[N]={0}; 
	for(int i=1;i<=ans;i++){
		if(num[cnt]<jj[i].l)num[++cnt]=jj[i].r;
	}
	cout<<ans<<" "<<m-cnt<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=0;
		bool flagA=1,flagB=1;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0)flagA=0;
			if(a[i]<=0)flagB=0;
		}
		for(int i=1;i<=m;i++)
			cin>>p[i];
		if(flagA)
			solveA();
		else if(flagB)
			solveB();
		else if(n<=20&&m<=20)
			solve1();
		else
			solve();
	}
	return 0;
}
