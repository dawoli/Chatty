#include<bits/stdc++.h>
using namespace std;
#define int long long
struct stu{
	int f[5];
}a[100005];
//¶à²âÒªÇå¿Õ 
int t,n,num[4],q,m,ans;
int u1,u2;
vector<int> v;
bool cmp(int ix,int iy){
	int valuex=a[ix].f[q]-max(a[ix].f[u1],a[ix].f[u2]);
	int valuey=a[iy].f[q]-max(a[iy].f[u1],a[iy].f[u2]);
	return valuex<valuey;
}
bool f[4][100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(false);
	cin>>t;
	for(int _=0;_<t;_++){
		cin>>n;
		num[1]=num[2]=num[3]=0;
		v.clear();
		ans=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			cin>>a[i].f[1]>>a[i].f[2]>>a[i].f[3];
		}
		for(int i=1;i<=n;i++){
			if(a[i].f[1]>=a[i].f[2]&&a[i].f[1]>=a[i].f[3]){
				f[1][i]=1;
				num[1]++;
			}
			else if(a[i].f[2]>=a[i].f[3]){
				f[2][i]=1;
				num[2]++;
			}
			else{
				f[3][i]=1;
				num[3]++;
			}
			
		}
		
		if(num[1]>=num[2]&&num[1]>=num[3]){q=1;u1=2;u2=3;}
		else if(num[2]>=num[3]){q=2;u1=1;u2=3;}
		else{q=3;u1=1;u2=2;}
		for(int i=1;i<=n;i++){
			if(f[q][i]){
				v.push_back(i);
			}
		}
		
		//for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
		//cout<<"\n";
		
		if(v.size()>n/2){
			sort(v.begin(),v.end(),cmp);
			for(int i=0;i<v.size()-n/2;i++){
				ans+=max(a[v[i]].f[u1],a[v[i]].f[u2]);
				//cout<<v[i]<<" "; 
			}
			for(int i=v.size()-n/2;i<v.size();i++){
				ans+=a[v[i]].f[q];
				//cout<<v[i]<<" "; 
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(f[q][i])ans+=a[i].f[q];
				//cout<<i<<" "<<ans<<endl;
			}
		}
		for(int i=1;i<=n;i++){
			if(f[u1][i])ans+=a[i].f[u1];
			if(f[u2][i])ans+=a[i].f[u2];
			//cout<<i<<" "<<ans<<endl;
		}
		cout<<ans<<endl;
		
	}
} 
