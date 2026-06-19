#include<bits/stdc++.h>
using namespace std;
int n;
int r[100010];
int mor[100010];
bool use[100010];
bool cmp(int a,int b){
	return a<b;
}
int ans;
void solve(){
	sort(r+1,r+n+1,cmp);
	ans=n;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(use[j]==0 && r[j]>r[i]){
				mor[i]=j;
				use[j]=1;
				ans--;
				break;
			}
		}
	}
	cout<<ans<<endl;
}
int cnt,sum[100010];
struct node{
	int id;
	int val;
}st[100010];
bool cmp1(node a,node b){
	return a.val<b.val;
}
int minu[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		st[r[i]].id++;st[r[i]].val=r[i];
		if(st[r[i]].id-1==0) cnt++;
	}
	if(n<=30) solve();
	else{
		ans=n;
		for(int i=1;i<=100001;i++) if(!st[i].val) st[i].val=0x3f3f3f3f;
		sort(st+1,st+100000+1,cmp1);
		for(int i=cnt;i>=1;i--){
			sum[i]=sum[i+1]+st[i].id;
		}
		for(int i=1;i<=cnt;i++){
			cout<<st[i].id<<" ";
		}
		cout<<endl;
		for(int i=1;i<=cnt;i++){
			cout<<sum[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<cnt;i++){
			sum[i+1]-=minu[i+1];
			if(sum[i]<=0){
				break;
			}
			if(st[i].id>sum[i+1]){
				ans-=sum[i+1];
			}else if(st[i].id<=sum[i+1]){
				ans-=st[i].id;
				sum[i+2]=sum[i+1]-st[i].id;
				if(i==2) minu[i+1]=st[i].id;
				minu[i+2]=st[i].id-st[i+1].id;
				if(minu[i+2]<0) minu[i+2]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
5
1 2 3 1 2

10
136 136 136 2417 136 136 2417 136 136 136

*/
//75
