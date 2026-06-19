#include<bits/stdc++.h>
#define kMaxN 100005
using namespace std;
int a[kMaxN];
bool b[kMaxN];
int n,sz;
int crm=0,nth=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	sz=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	while(1){
		crm=0,nth=0;//最多能移除的个数，不能攻击的个数
		int nthnum=a[sz-1];
		int i;
		for(i=sz-1;i>=0;i--){
			if(a[i]==nthnum){
				nth++;
			}
			else{
				break;
			}
		}
		if(nth==sz){
			break;
		}
		for(;i>=0;i--){
			if(!b[i]){
				b[i]=1;
				crm++;
			}
			if(crm>=nth){
				break;
			}
		}
		if(crm==0){
			break;
		}
		sz-=crm;
	}
	cout<<sz;
	return 0;
}
