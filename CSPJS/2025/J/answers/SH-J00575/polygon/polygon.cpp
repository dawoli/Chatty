#include<bits/stdc++.h>
void dfs(vector<int> &nums,vector<bool> &visited,int n,int i,int &cnt,vector<int> lens){
	if(nums.size()==i){
		int max=-1;
		for(int i=0;i<nums.size()){
			if(lens[nums[i]]>max){
				max=lens[nums[i]];
			}
		}
		int sum=0;
		for(int i=0;i<nums.size();++i){
			sum+=lens[nums[i]];
		}
		if(sum>max*2){
			cnt++;
		}
		return;
	}
	for(int j=0;j<n;++j){
		if(visited[j]==0){
			nums.push_back(j);
			visited[j]=1;
			dfs(nums,visited,n,i,cnt,lens);
			nums.pop_back();
			visited[j]=0;
		}	
	} 
}
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int> lens(n);
	for(int i=0;i<n;++i){
		cin>>lens[i];
	}
	int cnt=0;
	for(int i=3;i<n;++i){
		vector<int> nums;
		vector<bool> visited(n,0);
		dfs(nums,visited,n,i,cnt,lens)		
	}
	cout<<cnt%998244353;
	return 0;
}
