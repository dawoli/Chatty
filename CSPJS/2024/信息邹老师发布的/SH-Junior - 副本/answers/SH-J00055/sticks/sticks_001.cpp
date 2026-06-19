#include<bits/stdc++.h> 
using namespace std;
int t,n[100001],nott[55];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for(int q=0;q<t;q++){
		cin >> n[q];
	}
	for(int q=0;q<t;q++){
		if(n[q]<100){
			cout <<-1;
			continue;
		}
		if(n[q]%7==0)cout << 3;
		else{
			cout << 1;
			nott[q] = 1;
			n[q]--;
		}
		n[q]-=7;
		while(n[q]){
			cout << 3;
			n[q]-=7;
		}
		if(nott[q])cout << 6;
		cout << endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
