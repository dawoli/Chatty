#include<bits/stdc++.h>
using namespace std;
const int N=120000;
int n,t,w,a,b,c,t1,t2,sum1,sum2;
int p[4];
bool vis[N][3];
struct node{
	int a1,a2;
	int ad;
//	int id;
}v1[N];
map<int,int> cnt;
bool cmp(node x1,node x2){
	if(x1.a1==x2.a1)return x1.a2>x2.a2;
	else return x1.a1>x2.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		w=n/2;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			cnt[a]=1,cnt[b]=2,cnt[c]=3;
			t1=max(a,max(b,c));
			t2=min(a,min(b,c));
			v1[i].a1=t1;
			v1[i].a2=a+b+c-t1-t2;
			v1[i].ad=cnt[t1];
//			v1[i].id=i;
//			if(t1==t2||t1==v1[i].a2)vis[v1[i].id][v1[i].ad]=1;
		}
		sort(v1+1,v1+n+1,cmp);
		
		for(int i=1;i<=n;i++){
//			if(p[v1[i].ad]<w&&vis[v1[i].id][v1[i].ad]){
//				sum1+=v1[i].a1;
//				sum2+=v1[i].a2;
//			}
			if(p[v1[i].ad]<w){
				sum1+=v1[i].a1;
				sum2+=v1[i].a2;
				p[v1[i].ad]++;
			}
			else{
				sum2+=v1[i].a1;
				sum1+=v1[i].a2;
			}
		}
		cout<<max(sum1,sum2)<<endl;
//		cout<<sum1<<" "<<sum2<<endl;
		sum1=0,sum2=0;
		memset(p,0,sizeof(p));
		memset(vis,0,sizeof(vis));
	}
	
	
	
	return 0;
}
