#include<bits/stdc++.h>
using namespace std;
const int inf=2e9,N=1e5+5;
int t,n,ans;
struct value{
	int val,id;
};
bool cmp(value x,value y){
	return x.val>y.val;
}
struct node{
	int val[5],del[5],id[5];
}a[N];
priority_queue<pair<int,int> > q[5];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
	  cin>>n; ans=0;
	  for(int i=1;i<=n;i++){
	  	value num[5];
	  	for(int j=1;j<=3;j++) cin>>num[j].val,num[j].id=j;
	  	sort(num+1,num+4,cmp);
	    for(int j=1;j<=3;j++) a[i].val[j]=num[j].val,a[i].id[j]=num[j].id,a[i].del[j]=num[j+1].val-num[j].val;
	    a[i].del[3]=-inf;
	  }
	  while(!q[1].empty()) q[1].pop();
	  while(!q[2].empty()) q[2].pop();
	  while(!q[3].empty()) q[3].pop();
	  for(int i=1;i<=n;i++){
	  	if(q[a[i].id[1]].empty()||int(q[a[i].id[1]].size())+1<=n/2){
	  	  q[a[i].id[1]].push({a[i].del[1],i}),ans+=a[i].val[1];
	  	  continue;
	  	}
	  	if(a[i].val[1]+q[a[i].id[1]].top().first>a[i].val[2]){
	  	  int exv=q[a[i].id[1]].top().first,mdf=q[a[i].id[1]].top().second;
	  	  ans+=a[i].val[1]+exv;
	  	  q[a[i].id[1]].pop(),q[a[i].id[1]].push({a[i].del[1],i});
	  	  q[a[mdf].id[2]].push({a[mdf].del[2],mdf});
	  	}
	  	else q[a[i].id[2]].push({a[i].del[2],i}),ans+=a[i].val[2];
	  }
	  cout<<ans<<endl;
	}
	return 0;
}
