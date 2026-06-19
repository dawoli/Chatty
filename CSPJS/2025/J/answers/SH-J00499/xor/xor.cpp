#include<bits/stdc++.h>
using namespace std;
int maxans=-1;
int n,k;
vector<int> pre;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	pre.push_back(0);
	
	cin>>n>>k;
	vector<int> nums(n);
	vector<bool> occupied(n,false);
	
	for(int i=0;i<n;i++){
		cin>>nums[i];
		if(i!=0){
			pre.push_back(pre[i-1] ^ nums[i]);
		}
	}
	pre[0]=nums[0];
	for(int i=0;i<n;i++) cout<<pre[i]<<" ";
	
	for(int i=0;i<n;i++){
		int ans=0;
		//cout<<"texting"<<i<<endl;
		for(int j=i;j<n;j++){
			if(!occupied[i]&&!occupied[j]){
				if(i==j){
					if(nums[i]==k){
						//cout<<"	from "<<i<<" to "<<j<<" is xlegal"<<endl;
						ans++;
						occupied[i]=true;
						i=j+1;
						j=i;
					}
				}
				else if(pre[i] ^ pre[j] == k){
					//cout<<"	from "<<i<<" to "<<j<<" is legal"<<endl;
					ans++;
					fill(occupied.begin()+i,occupied.begin()+j,true);
					i=j+1;
					j=i;
				}
			}
			else{
				
			}
		}
		//cout<<"	ans="<<ans<<endl;
		maxans=max(maxans,ans);
	}
	
	cout<<maxans;
	return 0;
}
