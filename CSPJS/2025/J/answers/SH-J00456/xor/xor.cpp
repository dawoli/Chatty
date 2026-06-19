#include <bits/stdc++.h>
using namespace std;
deque<long long> d;
struct answer{
	long long start;
	long long final;
	bool operator<(const answer& other) const{
		return start>other.start;
	}
};
priority_queue<answer> ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	long long n,k,a,nowstart=0,nowfinal=0,sum=1;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a;
		d.push_back(a);
	}
	for(auto n:d) if(n==k) ans.push({n,n});
	for(long long i=0,j=0;i<d.size();j++){
		if(j==d.size()) j=0,i++;
		if(i==j) continue;
		long long sum=d[i];
		for(long long l=i+1;l<=j;l++) sum=sum^d[l];
		if(sum==k) ans.push({i,j});
	}
	if(ans.empty()){
		cout<<0;
		return 0;
	}
	nowstart=ans.top().start;nowfinal=ans.top().final;
	while(!ans.empty()){
		if(ans.top().start==nowstart&&ans.top().final<nowfinal) nowfinal=ans.top().final;
		if(ans.top().start==nowstart||ans.top().start<=nowfinal) {ans.pop();continue;}
		nowstart=ans.top().start;
		nowfinal=ans.top().final;
		sum++;
	}
	cout<<sum;
	return 0;
}
