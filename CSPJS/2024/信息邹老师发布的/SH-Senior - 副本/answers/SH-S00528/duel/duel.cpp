#include<bits/stdc++.h>
using namespace std;
int n,r[100009],ji[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>r[i];
		ji[r[i]]++;
	}
	sort(ji,ji+100009);
	cout<<ji[100008];
	return 0;
}
//HF#24THMC
