#include<bits/stdc++.h>
using namespace std;
string yyk[7]={"8","10","18","22","20","28","68"};
int lr[7]={0,-1,1,7,4,2,6};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("sticks1.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t){
		int n;
		cin>>n;
		if(n<7) cout<<lr[n];
		else{
			int i=n%7+7,j=n/7-1;
			cout<<yyk[i-7];
			for(;j>0;j--) cout<<'8';
		}
		cout<<endl;
		t--;
	}
	return 0;
}
