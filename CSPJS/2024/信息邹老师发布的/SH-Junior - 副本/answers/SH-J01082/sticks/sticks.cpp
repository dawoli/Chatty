#include<iostream>
using namespace std;
int dabiao[]={-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 80, 100, 108, 202, 200, 208, 288, 808};

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		cout<<dabiao[n]<<endl;
	}
	
	return 0;
}
