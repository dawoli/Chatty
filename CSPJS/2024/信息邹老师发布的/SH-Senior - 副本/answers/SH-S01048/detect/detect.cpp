#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V,ans1,ans2;
vector<int> add[10000005],ers[10000005];
queue<int> q,q2;
int laz[10000005],dect[10000005],ad[10000005];
void calc(int id,int v,int a,int d){
	if(a>0){
		if(v>V){
			add[d].push_back(id);
			ad[id]=d;
			ers[L+1].push_back(id);
		}
		else{
			int s=(V-v)*(V+v)/(2*a)+1+d;
			if(s<=L){
				add[s].push_back(id);
				ad[id]=s;
				ers[L+1].push_back(id);
			}
			else ans1--;
		}
	}
	else if(a<0){
		if(v>V){
			add[d].push_back(id);
			ad[id]=d;
			int s=(v-V)*(v+V)/(2*(-a))+1+d;
			if((v-V)*(v+V)%(2*(-a))==0) s--;
			//if(T==19) cout<<id<<" "<<d<<" "<<s<<endl;
			if(s<=L){
				ers[s].push_back(id);
			}
			else ers[L+1].push_back(id);
		}
		else ans1--;
	}
	else{
		if(v>V){
			ad[id]=d;
			add[d].push_back(id);
			ers[L+1].push_back(id);
		}
		else ans1--;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		while(!q.empty()){
			q.pop();
		}
		while(!q2.empty()){
			q2.pop();
		}
		ans1=n;
		ans2=m;
		for(int i=1;i<=n;i++){
			int di,vi,ai;
			cin>>di>>vi>>ai;
			calc(i,vi,ai,di);
		}
		for(int i=1;i<=m;i++){
			int p;
			cin>>p;
			dect[p]++;
		}
		int maxn=-100;
		for(int i=0;i<=L+1;i++){
		    for(auto j:ers[i]){
				if(laz[j]) continue;
				laz[j]=1;
				if(maxn<ad[j]) ans1--;
				else{
					ans2--;
					while(!q.empty()){
						laz[q.front()]=1;
						q.pop();
					}
				}
			}
			for(auto j:add[i]){
				q2.push(j);
			}
			if(dect[i]){
			    maxn=i;	
			    while(!q2.empty()){
			    	q.push(q2.front());
			    	q2.pop();
				}
			}
		}
		cout<<ans1<<" "<<ans2<<endl;
		for(int i=0;i<=L+1;i++){
			add[i].clear();
			ers[i].clear();
			dect[i]=0;
		}
		for(int i=1;i<=n;i++){
			laz[i]=0;
			ad[i]=0;
		}
	}
}
