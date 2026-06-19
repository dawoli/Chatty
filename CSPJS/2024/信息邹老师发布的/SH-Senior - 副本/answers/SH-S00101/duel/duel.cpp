#include <bits/stdc++.h>
using namespace std;
int n,r[100009],cnt,j=1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;for (int i=1;i<=n;++i) cin>>r[i];sort(r+1,r+n+1);
	for (int i=1;i<=n;++i){
		if (r[i]>r[j]) ++cnt,++j;
	}
	printf("%d\n",n-cnt);
	fclose(stdin);fclose(stdout);
	return 0;
}
