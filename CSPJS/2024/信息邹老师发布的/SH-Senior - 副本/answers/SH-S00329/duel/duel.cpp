#include<bits/stdc++.h>
using namespace std;
int n,m[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	sort(m,m+n);
	int j=0;
	for(int i=0;i<n;i++){
		if(m[i]>m[j]){
			j++;
		}
	}
	cout<<n-j;
	return 0;
} 
