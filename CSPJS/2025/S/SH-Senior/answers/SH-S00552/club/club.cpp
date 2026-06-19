#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
using std::fstream;
using std::cin;
using std::cout;
using std::endl;
#define NMAX 100001
int c[3][NMAX],limit[NMAX],order[NMAX],N;
long long ans=-1;
int left[3];

void dfs(int index,long long sum){
	if(index==N){
		ans=std::max(ans,sum);
		return;	
	} 
	int id=order[index];
	if(sum+limit[index]<=ans) return;
	auto cmp=[&](const int &lhs,const int &rhs){
		return c[lhs][id]>c[rhs][id];
	};
	int ps[3]{0,1,2};
	std::sort(ps,ps+3,cmp);
	for(int i:ps){
		if(left[i]==0) continue;
		--left[i];
		dfs(index+1,sum+c[i][id]);
		++left[i];
	}
}

int main(){
	fstream in("club5.in");
	std::ofstream out("club.out");
	int T; in>>T;
	Start:
	cout<<T<<" ";
	ans=-1;
	in>>N;
	left[0]=left[1]=left[2]=N/2;
	for(int i=0;i<N;++i){
		in>>c[0][i]>>c[1][i]>>c[2][i];
		limit[i]+=std::max({c[0][i],c[1][i],c[2][i]});
		order[i]=i;
	}
	auto cmp=[](int &lhs,int &rhs){return std::max({c[0][lhs],c[1][lhs],c[2][lhs]})>std::max({c[0][rhs],c[1][rhs],c[2][rhs]});};
	std::sort(order,order+N,cmp);
	for(int i=N-1;i>=0;--i){
		limit[i]=limit[i+1]+std::max({c[0][order[i]],c[1][order[i]],c[2][order[i]]});
	}
	dfs(0,0);
	out<<ans<<endl;
	if(--T>0) goto Start;
	in.close();
	out.close();
	return 0;
}

