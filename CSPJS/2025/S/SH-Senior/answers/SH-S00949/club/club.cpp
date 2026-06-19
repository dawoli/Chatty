#include<bits/stdc++.h>
using namespace std;

struct u{
	int p,q,r,mn;
};
u a[100010];
int T,n,ans,cnt[3];
vector<u> v[3];
bool cmp(u c,u d){
	return c.mn<d.mn;
}

int rd(){
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0'&& c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=rd();
	while(T--){
		ans=0,cnt[0]=0,cnt[1]=0,cnt[2]=0;
		n=rd();
		for(int i=0;i<3;i++) v[i].clear();
		for(int i=1;i<=n;i++){
			a[i].p=rd(),a[i].q=rd(),a[i].r=rd();
			int tmp=max(a[i].p,max(a[i].q,a[i].r));
			ans+=tmp;
			if(tmp==a[i].p){
				cnt[0]++;
				a[i].mn=tmp-max(a[i].q,a[i].r);
				v[0].push_back(a[i]);
				continue;
			}
			if(tmp==a[i].q){
				cnt[1]++;
				a[i].mn=tmp-max(a[i].p,a[i].r);
				v[1].push_back(a[i]);
				continue;
			}
			if(tmp==a[i].r){
				cnt[2]++;
				a[i].mn=tmp-max(a[i].p,a[i].q);
				v[2].push_back(a[i]);
				continue;
			}
		}
		for(int x=0;x<3;x++){
			if(cnt[x]>n/2){
				sort(v[x].begin(),v[x].end(),cmp);
				for(int i=0;i<cnt[x]-n/2;i++) ans-=v[x][i].mn;
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}
