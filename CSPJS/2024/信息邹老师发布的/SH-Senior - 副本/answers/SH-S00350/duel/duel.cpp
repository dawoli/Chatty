#include<bits/stdc++.h>
using namespace std;
int j[100009],r[100009],xb=1,cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>j[i];
	sort(j+1,j+n+1);
	for(int gj=2;gj<=n;gj++){
		if(j[gj]>j[xb]){
			j[xb]=0;
			xb++;
			cnt++;
		}
	}
	cout<<n-cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
