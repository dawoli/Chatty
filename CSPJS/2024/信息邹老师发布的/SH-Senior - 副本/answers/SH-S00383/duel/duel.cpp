#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int a[N],cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=1,r=2;
	while(r<=n){
		if(a[r]>a[l]){
			cnt++;	
			l++;
		}
		r++;
	}
	printf("%d",n-cnt);
	return 0;
}
/*
10
136 136 136 2417 136 136 2417 136 136 136
*/
