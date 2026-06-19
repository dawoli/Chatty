#include<bits/stdc++.h>
#define N 100005
#define M 1000005
using namespace std;
int t,n,m,l,mv,d[N],v[N],a[N],p[N];
int flag1=1,flag2=1,flag3=1,ans1=0,ans2=0;
map<int,int> s;
map<int,int>::iterator it;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>l>>mv;
		for(int j=1;j<=n;j++) cin>>d[j]>>v[j]>>a[j];
		for(int j=1;j<=m;j++) cin>>p[j];
		for(int j=1;j<=n;j++){
			if(a[j]==0){
				flag2=flag3=0;
			}
			else if(a[j]>0){
				flag1=flag3=0;
			}
			else{
				flag1=flag2=0;
			}
		}
		if(flag1){
			for(int j=1;j<=n;j++){
				if(v[j]>mv&&d[j]<=p[m]) ans1++;
			}
			if(ans1!=0) cout<<ans1<<" "<<m-1<<endl;
			else cout<<ans1<<" "<<m<<endl;
		}
		else if(flag2){
			for(int j=1;j<=n;j++){
				if(v[j]>mv&&d[j]<=p[m]) ans1++;
				else if(v[j]==mv&&d[j]<p[m]) ans1++;
				else if(v[j]<mv){
					int x=(mv*mv-v[j]*v[j])/(2*a[j]);
					if((d[j]+x)<p[m]) ans1++;
				}
			}
			if(ans1!=0) cout<<ans1<<" "<<m-1<<endl;
			else cout<<ans1<<" "<<m<<endl;
		}
		else if(flag3){
			for(int j=1;j<=n;j++){
				if(v[j]<=mv) continue;
				else{
					double x;
//					if(((mv*mv-v[j]*v[j])*10/(2*a[j])+5)/10==floor((mv*mv-v[j]*v[j])/(2*a[j]))) x=(mv*mv-v[j]*v[j])/(2*a[j])+1;
//					else x=(mv*mv-v[j]*v[j])/(2*a[j]);
					x=(mv*mv-v[j]*v[j])/(2*a[j]);
					if(d[j]+x>p[m]){
						ans1++;
						s[d[j]]++;
						s[d[j]+floor(x)]--;
					}
					else if(*lower_bound(p+1,p+m+1,d[j])<d[j]+x){
						ans1++;
						s[d[j]]++;
						s[d[j]+floor(x)]--;
					}
				}
			}
			int tmp=0,cnt=0;
			for(it=s.begin();it!=s.end();it++){
				tmp+=it->second;
				if(tmp==0) cnt++;
			}
			cout<<ans1<<" "<<m-cnt<<endl;
		}
		ans1=0;
		ans2=0;
	}
	return 0;
}
