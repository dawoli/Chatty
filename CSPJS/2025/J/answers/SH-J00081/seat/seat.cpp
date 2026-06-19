#include<bits/stdc++.h>
using namespace std;
long long n,m,rp_,ri_,ans_,all_,xiao_;
vector<long long> pe_(all_+1);
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	all_=n*m;
	for(int i=1;i<=all_;i++){
		cin>>pe_[i];
	}
	rp_=pe_[1];
	for(int i=1;i<=all_;i++){
		if(pe_[i]<rp_){
			xiao_++;
		}
	}
	ri_=all_-xiao_;
	cout<<ri_<<" ";
	ans_=ceil(ri_*1.0/n);
	cout<<ans_<<" ";
	if(ans_%2!=0){
//		cout<<"ÆæÊý"; 
		cout<<ri_%(n+1);
		return 0;
	}
	else{
//		cout<<"Å¼Êý"; 
		ans_=n-(ri_-1)%n;
		cout<<ans_;
		return 0;
	}
	return 0;
}



























