#include<bits/stdc++.h>
using namespace std;
int n;
int r[100001];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&r[i]);
	}
	sort(r + 1,r + n + 1,less<int>());
	int duel = 0;
	for(int i = 1;i <= n;i++){
		if(r[duel] < r[i]){
			duel++;
		}
	}
	printf("%d",n - duel + 1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
