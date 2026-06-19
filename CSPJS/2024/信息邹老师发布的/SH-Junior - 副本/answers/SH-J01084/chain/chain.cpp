#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;cin>>t;
	srand(time(0));
	for(int i=0;i<t;i++){
		cout<<rand()%2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
