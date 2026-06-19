#include<iostream>
#include<cstdio>
using namespace std;
const int N=100100;
int a,n,bucket[N],mx;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		bucket[a]++;
	}
	for(int i=0;i<N;i++){
		mx=max(mx,bucket[i]);
	}
	cout<<mx<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
