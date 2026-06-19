#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];
struct qujian{
	int start;
	int end;
};
qujian can[2000000];
int index=1;
int digui(int now,int last,int choose){
	int ans=now;
	for(int i=choose+1;i<index;i++){
		if(can[i].start<=can[last].end) continue;
		ans=max(digui(now,last,i),digui(now+1,i,i));	
	}
	return ans;
}
void solveBF(){
	for(int i=1;i<=n;i++){
		int yhh=0;
		for(int j=i;j<=n;j++){
			yhh=yhh^a[j];
			if(yhh==k){
				can[index].start=i;
				can[index++].end=j;
			}
		}
	}
	int ans=-1;
	for(int i=1;i<=index;i++){
		ans=max(ans,digui(1,i,i));
	}
	cout<<ans;
}
void solve(){
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=1000) solveBF();
	else solve();
	return 0;
}
