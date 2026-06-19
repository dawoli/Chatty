#include<bits/stdc++.h>
#define N 100003
using namespace std;
// ~100, O(n)
int n,r[N];
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&r[i]);
}
int solveA(){
	sort(r+1,r+1+n);
	int i=1,ans=n;
	for(int j=1;j<=n;j++)
		if(r[j]>r[i]){
			ans--;
			i++;
		}
	return ans;
}
int solveB(){
	sort(r+1,r+1+n);
	int i=1,ans=n;
	for(int j=n;j>=1&&j>i;j--)
		if(r[j]>r[i]){
			ans--;
			i++;
		}
	return ans;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	input();
	printf("%d\n",min(solveA(),solveB()));
	fclose(stdin);fclose(stdout); 
	return 0;
}
