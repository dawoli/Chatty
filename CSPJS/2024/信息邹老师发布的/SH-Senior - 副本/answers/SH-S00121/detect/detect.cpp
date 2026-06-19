#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,ans;
int ru[101000],v[101000],a[101000],w[101000],pan[101000],ji[101000];
vector<int> ce[101000];
bool cmp(int q1,int q2){
	return q1>q2;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&ru[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++) scanf("%d",&w[i]);
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(w[i]<ru[j]) continue;
				int s=w[i]-ru[j];
				if(pow(v[i],2)+2*a[i]*s<0) continue;
				bool lns=0;
				if(a[j]==0 && v[j]>V) lns=1;
				double v1=sqrt(pow(v[i],2)+2*a[i]*s);
				if(v1>V) lns=1;
				if(lns){
					ce[i].push_back(j);
					ji[i]++;
					if(!pan[i]){
						ans++;
						pan[i]=1;
					}
				}
			}
		}
		cout<<ans<<" ";
		sort(ji+1,ji+1+m,cmp);
		set<int> lll; 
		for(int i=1;;i++){
			for(int kkk=0;kkk<ce[i].size();kkk++){
				lll.insert(ce[i][kkk]);
			}
			if(lll.size()==ans){
				cout<<m-i<<"\n";
				break;
			}
		}
	}
	return 0;
}
