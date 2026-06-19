#include<iostream>
#include<cstdio>
using namespace std;
int arr[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int r;
		cin>>r;
		arr[r]++;
	}
	int ans=n;
	int rm=0;
	for(int i=1;i<=100000;i++){
		if(i>1){
			int t=min(arr[i],rm);
			rm-=t;
			ans-=t;
		}
		rm+=arr[i];
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
