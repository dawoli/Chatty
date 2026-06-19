#include<iostream>
#include<cstdio>
using namespace std;
int arr[1000];
int n;
int solve(int index=0,int red=-1,int blue=-1){
	if(index==n){
		return 0;
	}
	int ans=0;
	//red
	ans=max(solve(index+1,index,blue)+(red!=-1&&arr[red]==arr[index]?arr[red]:0),ans);
	//blue
	ans=max(solve(index+1,red,index)+(blue!=-1&&arr[blue]==arr[index]?arr[blue]:0),ans);
	return ans;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<solve()<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
}
