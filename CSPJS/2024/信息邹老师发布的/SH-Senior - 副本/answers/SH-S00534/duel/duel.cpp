#include<bits/stdc++.h>
using namespace std;
int n,nums[100005],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	} 
	sort(nums+1,nums+n+1);
	int le=1,ri=2;
	for(int i=1;i<=n;i++){
		if(nums[i]>nums[le]){
			ri=i;
			break;
		}
	}
	while(ri<=n){
		if(nums[ri]>nums[le]){
			ans--;
			le++,ri++;
		}
		else{
			ri++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

