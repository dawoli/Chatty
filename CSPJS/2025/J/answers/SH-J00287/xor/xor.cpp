#include <bits/stdc++.h>
using namespace std;
long long a[500005],n,k,maxk=-1,nowf,nowk,flagbool,flagback=0,flagi=1,flagstop[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=1;i<=n;i++){
		flagbool=1;
		nowk=0;
		for (int c=1;c<=flagi;c++){
			if (flagstop[c]==i){
				flagbool=0;
			}
		}
		long long j=i;
		nowf=0;
		if (flagbool==1){
			int flagnowstop=0;
			while(j<=n){
				nowf^=a[j];
				if (nowf==k || a[j]==k){
					nowk++;
					nowf=0;
					flagstop[flagi]=1;
					flagi++;
					flagnowstop=1;
				}
				j++;
			}
		}
		maxk=max(maxk,nowk);
		nowk=0;
	}
	cout << maxk;
	return 0;
}
