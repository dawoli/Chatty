#include<bits/stdc++.h>

using namespace std;
const int N = 100030;
int sum; 
int att[N];
int head=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> sum;
	for(int i=0;i<sum;i++){
		cin>> att[i];
	}
	sort(att,att+sum);
	for(int i=0;i<sum;i++){
		if(att[i]>att[head]){
			head++;
		}

	}
	cout<< sum-head << endl;
	return 0;
}
