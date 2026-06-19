#include<bits/stdc++.h>
using namespace std;
int r[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> r[i];
	}
	int ans=n;
	sort(r+1,r+n+1);
	for(int i=1,j=2;i<=n&&j<=n;){
		//i:±»¹¥»÷ j:¹¥»÷ 
		if(r[i]<r[j])ans--,i++,j++;
		else j++;
	}
	cout << ans;
	return 0;
}
