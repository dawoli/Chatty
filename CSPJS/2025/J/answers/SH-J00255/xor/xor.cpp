#include<bits/stdc++.h>
using namespace std;
int n,k;
int nums[5000005];
int xor_result[1005][1005];
struct Line{
	int l,r;
};
vector<Line> vec;
bool bump(Line l1,Line l2){
	return l2.l<=l1.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	for(int i=1;i<=n;i++){
		int res=nums[i];
		xor_result[i][i]=res;
		for(int j=i+1;j<=n;j++){
			res=res^nums[j];
			xor_result[i][j]=res;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(xor_result[i][j]==k){
				vec.push_back({i,j});
			}
		}
	}
	int res=vec.size(),index=0;
	for(int i=1;i<vec.size();i++){
		if(!bump(vec[index],vec[i])) index=i;
		else res--;
	}
	cout<<res<<endl;
	fclose(stdin);
	fclose(stdout);	
}
