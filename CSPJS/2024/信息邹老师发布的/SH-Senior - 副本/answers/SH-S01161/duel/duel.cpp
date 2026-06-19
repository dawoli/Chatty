#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
long long n,a[maxn],loc[maxn],ans=0;
bool val[maxn];
priority_queue<long long> q;
priority_queue<long long> Q[maxn]; 

bool cmp(long long x,long long y){
	return x>=y; 
}


int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	for(long long i=1;i<=100005;i++)
		val[i]=false;

	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	long long k=1,x;
	while(!q.empty()){
		x=q.top();
		q.pop();
		if(!val[x]){
			Q[1].push(x);
			val[x]=true;
			loc[x]=1;
		}
		else{
			Q[loc[x]+1].push(x);
			loc[x]++;
			k++;
		}
	}
	for(int i=1;i<=k;i++){
		if(!Q[i].empty()) ans++;
	}
	cout<<ans<<endl;
	
	return 0;

}
