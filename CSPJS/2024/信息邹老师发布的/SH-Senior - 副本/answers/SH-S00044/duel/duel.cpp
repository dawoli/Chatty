#include<bits/stdc++.h>
using namespace std;
int buck[100010];
int rr;
int nn;
int maxn;
long long numm;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>nn;
	for(int i=1;i<=nn;i++){
		cin>>rr;
		maxn=max(rr,maxn);
		buck[rr]++;
	}
	for(int i=2;i<=maxn;i++){
		numm+=buck[i-1];
		numm-=buck[i];
		if(numm<0){
			numm=0;
		}
	}
	numm+=buck[maxn];
	cout<<numm<<endl;

	return 0;
}
