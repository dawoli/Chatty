#include <bits/stdc++.h>
// É¨ÃèÏß 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

struct Car{
	i64 a;
	i64 v,in,out,l,r;
};

void solve() {
	int n,m,L,V;
	std::cin>>n>>m>>L>>V;
    std::vector<Car> cars(n);
    for(Car& i:cars){
    	std::cin>>i.in>>i.v>>i.a;
    	if(i.a<0) {
    		i.out=i.in-i.v*i.v/2/i.a;
    		if(i.out>L) i.out=L;
		}	    
    	else i.out=L;
    	if(i.v>V) {
    		i.l=i.in;
    		if(i.a<0)
    		    i.r=i.in-i.v*(i.v-V)/i.a;
    		else i.r=i.out;
		} else if(i.a==0) i.l=i.r=L+1;
		else if(i.a<0) i.l=i.r=L+1;
    	else if(i.a>0) {
    		i.l=i.in+i.v*(V-i.v)/i.a;
    		i.r=i.out;
		}
	}
	std::vector<int> flag(m);
	for(int i=0;i<m;i++) flag[i]=false; 
	std::vector<i64> det(m);
	for(auto& i:det){
		std::cin>>i;
	}
	int ans1=0;
	for(auto& i:cars){
		if (i.l==L+1) continue;
		auto st = std::lower_bound(det.begin(),det.end(),i.l);
		auto end = std::upper_bound(det.begin(),det.end(),i.r);
	    if(st<end) ans1++;
	    i.l=st-det.begin();
	    i.r=end-det.begin();
	    for(auto j=i.l;j<i.r;j++){
	    	flag[j]++;
		}
	}
	int ans2=0,maxx=0;
	for(auto& i:flag) {
		maxx=std::max(i,maxx);
		std::cout<<i<<'\n';
	}
	
	for(auto& i:flag) {
		if(i==maxx) ans2++;
	}
	ans2=m-ans2;
	std::cout<<ans1<<' '<<ans2<<'\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);	
	int t;
	std::cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
