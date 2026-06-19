#include <bits/stdc++.h> 
using namespace std;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	int n;
	cin>>n;
	int enemy[n];
	for(int i=0;i<n;i++) cin >> enemy[i];
	int i=0,j=n;
	for(int i=0,j=n-1;i<j;i++,j--){
		if(enemy[i]>enemy[j]){
		    swap(enemy[i],enemy[j]);
	    }
	};
	int out=0;
	for(int i=0;i<n;i++) cout << enemy[i]<<endl;
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
