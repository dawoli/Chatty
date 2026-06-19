#include<bits/stdc++.h>
using namespace std;
int n;
int a[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			cnt2++;
			if(cnt1) --cnt1;
		}
		else{
			cnt1+=cnt2;cnt2=1;
			if(cnt1) --cnt1;
		}
	}
	printf("%d",cnt1+cnt2);
	return 0;
} 
