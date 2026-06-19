#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int lit_ans[21]={-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 68, 88};
	int t;
	cin>>t;
	int n;
	for(int i=1; i<=t; i++){
		cin>>n;
		if(n<=14) cout<<lit_ans[n];
		else{
			if(n%7==0){
				for(int j=1; j<=n/7; j++){
					cout<<'8';
				}
			}
			else if(n%7==1){
				cout<<"10";
				for(int j=1; j<n/7; j++){
					cout<<'8';
				}
			}
			else{
				cout<<lit_ans[n%7+7];
				for(int j=1; j<n/7; j++){
					cout<<'8';
				}
			}
		}
		cout<<endl;
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
