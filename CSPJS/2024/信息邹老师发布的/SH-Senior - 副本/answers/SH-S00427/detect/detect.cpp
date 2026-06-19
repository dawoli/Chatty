#include<bits/stdc++.h>
#define N 100009
#define ninf 0.00000000001
#define double long double
using namespace std;
double a[N][2],b[N];
bool scar[N],scam[N],inlaw[N];
int cnt[N];
int dxx[N],vxx[N],axx[N];
vector<int> cam[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
//	double test1=10000000+0.000000001,test2=10000000;
//	cout<<(test1>test2)<<endl;
	while(t--){
		int n,m;
		double l,v;
		cin>>n>>m>>l>>v;
		bool allaccelerate=1;
		for(int i=1;i<=n;i++){
			cin>>dxx[i]>>vxx[i]>>axx[i];
		}
//		cout<<"ok"<<endl;
		for(int i=1;i<=n;i++){
			double dx=dxx[i],vx=vxx[i],ax=axx[i];
			inlaw[i]=0;
			if(ax<0)allaccelerate=0;
			if(vx>v&&ax>=0){
				a[i][0]=dx;
				a[i][1]=l;
			}
			else if(vx>v&&ax<0){
				a[i][0]=dx;
				a[i][1]=min(l,dx+(v*v-vx*vx)/2/ax-ninf);
			}
			else if(vx<=v&&ax>0){
				a[i][0]=dx+(v*v-vx*vx)/2/ax+ninf;
				a[i][1]=l;
			}
			else inlaw[i]=1;
		}
		int bmax=0;
		for(int i=1;i<=m;i++){cin>>b[i];bmax=max((int)b[i],bmax);}
//		cout<<bmax<<endl;
//		allaccelerate=0;
		if(allaccelerate){
//			cout<<"-----------------------"<<endl;
//			for(int i=1;i<=n;i++){
//				cout<<a[i][0]<<' '<<a[i][1]<<endl;
//			}
			int ans=n;
			for(int i=1;i<=n;i++){
				if(a[i][0]>bmax||inlaw[i])ans--;
			}
			cout<<ans<<' '<<m-1<<endl;
		}
		else{
			for(int i=1;i<=n;i++)cam[i].clear();
			int ans=0;
			for(int i=1;i<=m;i++)scam[i]=1,scar[i]=0;
			for(int i=1;i<=n;i++){
				if(inlaw[i])continue;
				bool flag=1;
				for(int j=1;j<=m;j++){
					if(a[i][0]<=b[j]&&b[j]<=a[i][1]){
						ans+=flag;flag=0;scar[i]=1;cam[i].push_back(j);
					}
				}
			}
			cout<<ans<<' ';
//			for(int i=1;i<=n;i++){
//				cout<<scar[i]<<endl;
//			}
//			for(int i=1;i<=n;i++){
//				cout<<a[i][0]<<' '<<a[i][1]<<endl;
//			}
			int rem=ans;
			int ans2=m;
			while(rem>0){
//				cout<<rem<<endl;
				for(int j=1;j<=m;j++)cnt[j]=0;
				for(int i=1;i<=n;i++){
					if(!scar[i])continue;
					for(int j=0;j<cam[i].size();j++){
						if(scam[cam[i][j]])
							cnt[cam[i][j]]++;
					}
				}
				int id=max_element(cnt+1,cnt+1+m)-cnt;
//				for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
//				cout<<id<<endl;
				ans2--;
				for(int i=1;i<=n;i++){
					if(scar[i]&&a[i][0]<=b[id]&&b[id]<=a[i][1]){
						scar[i]=0;
						rem--;
					}
				}
				scam[id]=0;
			}
			cout<<ans2<<endl;
		}
	}
	return 0;
}
