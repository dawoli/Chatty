#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]==a[j-1])sum+=a[i];
		}
	}
	cout<<sum;
	close(stdin);
	close(stdout);
	return 0;
}
