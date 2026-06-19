#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=1,r=1,tp,sum=0;//?
	//第一个可以杀的 
	while(r<=n){
		if(a[l]<a[r]){
			sum++;
			l++;
			r++;
		}
		else{
			r++;
		}
	}
	cout<<n-sum;
	return 0;
} 
