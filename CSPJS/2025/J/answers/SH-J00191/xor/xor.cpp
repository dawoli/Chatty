#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int max_l=0;
	for(int left=0;left<n;++left){
		int c_max=arr[left];
		int c_min=arr[left];
		for(int right=left;right<n;++right){
			c_max=max(c_max,arr[right]);
			c_min=min(c_min,arr[right]);
			if(c_max-c_min<=k){
				max_l=max(max_l,right-left+1);
			}
		}
	}
	cout<<max_l<<endl;
}
