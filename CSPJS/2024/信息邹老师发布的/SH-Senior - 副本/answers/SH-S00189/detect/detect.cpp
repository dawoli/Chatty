#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
void fre(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
}
int d[3005],v[3005],a[3005],p[100005];
bool vis[100005];
int n,m,L,V;
map<int,int> ma;
void sovel(){
	for(int i=0;i<n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]==0&&a[i]>=V)ma[a[i]]=d[i];
			if(a[i]>0)ma[a[i]]=(V*V-v[i])/(2*a[i]);
		}
		int ans1=0,ans2=0;
		for(int i=0;i<m;i++){
			cin>>p[i];
			for(int j=0;j<n;j++){
				if(ceil(sqrt(v[j]*v[j]+2*a[j]*(p[i]-d[i])))>V&&vis[j]==0){
					ans1++;
					ans2++;
					vis[j]=1;
				}
			}
		}
		cout<<ans1-1<<" "<<ans2-1<<endl;
}
/*void sovel1(){
	for(int i=0;i<n;i++){
		cin>>d[i]>>v[i]>>a[i];
		if(a[i]==0&&a[i]>=V)ma[a[i]]=make_pair(d[i],L);
		if(a[i]>0&&(V*V-v[i])/(2*a[i])<L)ma[a[i]]=make_pair((V*V-v[i])/(2*a[i]),L);
		if(a[i]<0&&(V*V-v[i])/(2*a[i])>0)ma[a[i]]=make_pair(0,(V*V-v[i])/(2*a[i]));
	}
	int ans1=0,ans2=0;
		for(int i=0;i<m;i++){
			cin>>p[i];
			for(int j=0;j<n;j++){
				if(ma[j].f<=p[i]&&p[i]<=ma[j].s){
					ans1++;
				}
			}
		}
	cout<<ans1-1<<" "<<rand()%ans1<<endl;
}*/
int main(){
	fre();
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>L>>V;
		ma.clear();
		//if(n<=20)sovel1();
		sovel();
	}
	return 0;
}
