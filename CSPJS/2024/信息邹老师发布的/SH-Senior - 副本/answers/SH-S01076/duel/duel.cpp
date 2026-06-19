#include<iostream> 
#include<cstdio>
#include<algorithm>
const int N = 1e5+7;
int cnt[N];
void quick(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}
int main(){
	std::freopen("duel.in","r",stdin);
	std::freopen("duel.out","w",stdout);
	quick();
	int n;
	std::cin>>n;
	int L=0;
	for(int i=1,x;i<=n;++i){
		std::cin>>x;
		++cnt[x];
		L=std::max(L,x);
	}
	int s=0;
	for(int x=1;x<=L;++x){
		if(s<=cnt[x])s=0;
		else s-=cnt[x];
		s+=cnt[x];
	}
	std::cout<<s<<std::endl;
	return 0;
}
