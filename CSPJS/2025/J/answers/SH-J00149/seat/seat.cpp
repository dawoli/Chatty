#include<bits/stdc++.h>
using namespace std;
int n,m,ans,hang,lie,score;
bool tmp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>score;
	for(int i = 0;i < n * m - 1;i++){
		int tmp;
		cin>>tmp;
		if(tmp > score)
			ans++;
	}
	ans++;
	if(ans % n == 0){
		tmp = ((ans - ans % n) / n) % 2;
		lie = (ans - ans % n) / n;
		if(tmp == 0)
			hang = 2 * n - ans + 1;
		else
			hang = ans - (lie - 1) * n;
	}else{
		tmp = (((ans - ans % n) / n) + 1) % 2;
		lie = ((ans - ans % n) / n) + 1;
		if(tmp == 0)
			hang = 2 * n - ans + 1;
		else
			hang = ans - (lie - 1) * n;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
