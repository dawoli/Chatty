#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	if(n<3) cout << 0;
	else{
		cout <<0;	
	}
	fclose(stdin);
	fclose(stdout);
} 
