#include <bits/stdc++.h>
using namespace std;

int T,n,nums[200001];
long long dfs(int index, int lastR, int lastB){
	if(index==n){
		return 0;
	}
	long long R=0,B=0;
	if(nums[index]==lastR){
		R=nums[index];
	}
	if(nums[index]==lastB){
		B=nums[index];
	}
	if(R+nums[index]+lastB>=B){
		R += dfs(index+1, nums[index], lastB);
	}
	if(B+lastR+nums[index]>=R){
		B += dfs(index+1, lastR, nums[index]);
	}
	return max(R,B);
}
int main(){
	freopen("color2.in","r",stdin);
//	freoepn("color.out","w",stdout);
	
	cin>>T;
	for(int _=0;_<T;++_){
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>nums[i];
		}
		cout<<dfs(0,-1,-1)<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
