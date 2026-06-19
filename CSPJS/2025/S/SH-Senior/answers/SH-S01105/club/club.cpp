#include<bits/stdc++.h>
using namespace std;
int t;
int a[100005][4],cl[100005];
void run(){
	int n;
	cin>>n;
	int num[4],ans=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q2;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q3;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i][1]=u;a[i][2]=v;a[i][3]=w;
		if(u>=v&&u>=w){
			num[1]++;
			ans+=u;
			cl[i]=1;
			if(u-v<=u-w) q1.push(make_pair(u-v,v));
			else q1.push(make_pair(u-w,w));
		}else if(u>=u&&v>=w){
			num[2]++;
			ans+=v;
			cl[i]=2;
			if(v-u<=v-w) q2.push(make_pair(v-u,u));
			else q2.push(make_pair(v-w,w));
		}else{
			num[3]++;
			ans+=w;
			cl[i]=3;
			if(w-u<=w-v) q3.push(make_pair(w-u,u));
			else q3.push(make_pair(w-v,v));
		}
	}
	if(num[1]<=n/2&&num[2]<=n/2&&num[3]<=n/2){
		cout<<ans<<endl;
		return;
	}else{
		while(q1.size()>n/2){
			pair<int,int> x=q1.top();
			q1.pop();
			ans-=x.first;
		}
		while(q2.size()>n/2){
			pair<int,int> x=q2.top();
			q2.pop();
			ans-=x.first;
		}
		while(q3.size()>n/2){
			pair<int,int> x=q3.top();
			q3.pop();
			ans-=x.first;
		}
		cout<<ans<<endl;
		return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		run();
	}
	return 0;
}
