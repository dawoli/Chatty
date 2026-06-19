#include <iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<=n-1;i++){
		cin>>a[n];
	}
	int left=0,right=1,cnt=0;
	while(left<n-1){
		int tmp=0;
		for(int i=left;i<=right;i++){
			tmp=tmp+tmp^a[i];
		}
		if(tmp==k){
			cnt++;
			left=right+1;
			right = left+1;
		}
		else{
			if(right==n-1){
				left++;
				right = left+1;
			}
			else{
				right++;
			}
	    }
	}
	cout<<cnt+1;
	return 0; 
}
