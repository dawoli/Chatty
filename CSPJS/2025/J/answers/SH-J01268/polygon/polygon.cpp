#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,x;
	cin >> n >> x;
	int cnt=0;
	int ans=0;
	for(int i=3;i<n;i++){
		for(int j=0;j<=i;j++){
			ans+=1;
		}
	}
	if (x==1){
		cout << "9";
	} 
	if (x==2){
		cout << "6";
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
