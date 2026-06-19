#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans=0,maxx=0;
bool b[500005];
queue<pair<long long,long long> > p;
queue<pair<long long,long long> > q;

void dp(){
	if(q.empty()){
		while(!p.empty()){
			long long x=p.front().first;
			long long y=p.front().second;
			p.pop();
			q.push(make_pair(x,y));
		}
		maxx=max(maxx,ans);
		return ;
	}
	long long x=q.front().first;
	long long y=q.front().second;
	q.pop();
	p.push(make_pair(x,y));
	dp();
	bool f=1;
	for(int i=x;i<=y;i++){
		if(b[i]==1){
			f=0;
		}
	}
	if(f){
		for(int i=x;i<=y;i++){
			b[i]=1;
		}
		ans++;
		dp();
		ans--;
		for(int i=x;i<=y;i++){
			b[i]=0;
		}	
	}
	return ;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			int x=0;
			for(long long l=i;l<=j;l++){
				x^=a[l];
			}
			if(x==k){
				q.push(make_pair(i,j));
			}
		}
	}
	dp();
	cout<<maxx;
	return 0;
}
