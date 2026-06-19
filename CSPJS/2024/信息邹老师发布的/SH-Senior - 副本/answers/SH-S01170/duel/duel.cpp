#include<bits/stdc++.h>
using namespace std;
struct S{
	int gongji,fangyu;
}r[100005];
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	bool b[n+5]={};
	int ans=n;
	for(int i=0;i<n;i++){
		cin>>r[i].gongji;
		r[i].fangyu=r[i].gongji;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(r[i].gongji>r[j].fangyu&&b[i]==0){
				b[i]=1;
				r[j].gongji=0;
				r[j].fangyu=0x7fffffff;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(r[i].fangyu!=r[i].gongji){
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
