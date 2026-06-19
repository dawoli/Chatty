#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int n,k,ans;
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vector<long long> nums(n,0);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	vector<long long> pnums=nums;
	for(int i=1;i<n;i++){
		pnums[i] ^= pnums[i-1];
	}
	if(n<=2){
		for(int i:nums){
			if(i==k) ans++;
		}
		cout<<ans;
	}else{
		int prep=-1;
		for(int i=0;i<n;i++){
			if((pnums[i]==k&&prep==-1)||((pnums[i]^pnums[prep])==k)){
				ans++;
				prep=i;
			}
		}
		cout<<ans;
	}
	return 0;
}
