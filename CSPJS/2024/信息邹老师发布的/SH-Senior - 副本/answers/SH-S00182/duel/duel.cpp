#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#define int long long
int a[100005],n;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	std::cin>>n;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	std::sort(a+1,a+1+n);
	std::priority_queue<int,std::vector<int>,std::greater<int>> q;
	for(int i=1;i<=n;i++){
		if(!q.empty()){
			int pre=q.top();
			if(a[i]>pre){
				q.pop();
			}
		}
		q.push(a[i]);
	}
	std::cout<<q.size()<<"\n";
	return 0;
}
