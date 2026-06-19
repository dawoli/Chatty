#include <iostream>
using namespace std;
long long nums[100001]={0},flag=9,mn;
int core[8]={0,0,1,7,4,2,0,8},mindex;

void extend(int e){
	for(int i=flag;i<=e;i++){
		
		mn=999999999999;
		mindex=i;
		for(long j=i-7;j<i-1;j++){
			if(nums[j]<mn){
				mn=nums[j];
				mindex=j;
			}
		}
		
		nums[i]=mn*10+core[i-mindex];
	}
	flag=e+1;
}

int main(){
	freopen("./sticks.in","r",stdin);
	freopen("./sticks.out","w",stdout);
	
	nums[1]=-1;
	nums[2]=1;
	nums[3]=7;
	nums[4]=4;
	nums[5]=2;
	nums[6]=6;
	nums[7]=8;
	nums[8]=10;
	
	int n,k=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		if(k>=flag){
			extend(k);
		}
		cout<<nums[k]<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
