#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<vector<int>> seat(n,vector<int>(m,0));
	vector<int> nums(n*m);
	for(int i=0;i<n*m;i++){
		cin>>nums[i];
	}	
	int r=nums[0];
	sort(nums.begin(),nums.end());
	vector<int> c=nums;
	for(int i=0;i<m*n;++i){
		nums[i]=c[m*n-1-i];
	}
	int i=0,j=0,a=1;
	for(int k=0;k<n*m;++k){
		seat[i][j]=nums[k];
		i+=a;
		if(i==-1){
			i=0;
			a=1;
			j++;
		}
		if(i==n){
			i=n-1;
			a=-1;
			j++;
		}
	}	 
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(seat[i][j]==r){
				cout<<j+1<<" "<<i+1;
				return 0;
			}
		}
	}
	return 0;	 
}
