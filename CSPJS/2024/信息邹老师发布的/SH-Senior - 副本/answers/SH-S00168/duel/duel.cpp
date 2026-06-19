#include<bits/stdc++.h>
using namespace std;
// This is an F. I like Fs. Fs are good for our health. 
int a[100001]={},tot[100001]={},n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tot[a[i]]++;
	}
	int rest=0,delta=0;
	for(int i=1;i<=100000;i++){
		if(!tot[i])continue;
		int used=0,total=tot[i];
		while(used<total&&rest){
			used++;
			rest--;
			delta++;
		}
		rest+=total;
	}
	cout<<n-delta;
	return 0;
} 
