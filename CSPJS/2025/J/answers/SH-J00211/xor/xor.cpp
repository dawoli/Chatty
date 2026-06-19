//  贪心策略：能选择长度短的区间就不选择长度长的； 
#include<iostream>
#include<cstdio> 
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int n=0,k=0;
const int N=5e5+5;
int a[N]={};
int qz[N]={};
map<int,int> ys;
struct qj{
	int l,r;
};
vector<qj> wc;
int tl,tr;
int solve(int l,int r){
	wc.clear();
	int ans=0;
	if(l>r) return 0; 
	tl=0;
	tr=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		qz[i]=-1;
	}
	ys[0]=l-1;
	qz[l-1]=0;
	for(int i=l;i<=r;i++){
		
		qz[i]=qz[i-1]^a[i];
		ys[qz[i]]=i;
//		cout<<qz[i]<<" ";
		int x=k^qz[i];
		if(qz[i]==k){
			int teml=l-1;
			if(i-teml<tr-tl+1){
				tl=teml+1;
				tr=i;
				wc.clear();
				qj qj1;
				qj1.l=tl;
				qj1.r=i;
				wc.push_back(qj1);
			}
			else if(i-teml==tr-tl+1){
				tl=teml+1;
				tr=i;
				qj qj1;
				qj1.l=tl;
				qj1.r=i;
				wc.push_back(qj1);
			}
		}
		else if((qz[ys[x]]==x)&&ys[x]!=i ){
		
			int teml=ys[x];
		//	cout<<l<<" "<<r<<" "<<teml<<" "<<i<<endl;
			if(i-teml<tr-tl+1){
				tl=teml+1;
				tr=i;
				wc.clear();
				qj qj1;
				qj1.l=tl;
				qj1.r=i;
				wc.push_back(qj1);
			}
			else if(i-teml==tr-tl+1){
				tl=teml+1;
				tr=i;
				qj qj1;
				qj1.l=tl;
				qj1.r=i;
				wc.push_back(qj1);
			}
		}
	}
//	cout<<" "<<l<<" "<<r<<endl;
	if(!wc.empty()){
		ans++;
		for(int i=0;i<wc.size();i++){
			int tl=wc[i].l;
			int tr=wc[i].r;	
			ans=max(solve(l,tl-1)+solve(tr+1,r)+1,ans);
		}
		return ans;
	}
	else{
		return 0; 
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<solve(1,n);
	return 0;
} 
