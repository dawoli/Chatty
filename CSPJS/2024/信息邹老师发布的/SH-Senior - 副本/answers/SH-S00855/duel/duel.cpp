#include<bits/stdc++.h>
using namespace std;
int n, r[100009], cnt;
bool b1[100009], b2[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1 ; i<=n ; i++)
		cin>>r[i];
	sort(r+1, r+1+n);
	for(int i=1 ; i<=n ; i++){
		for(int j=i+1 ; j<=n ; j++){
			if(r[i]<r[j] && !b2[j]){
				b1[i] = 1;
				b2[j] = 1;
				break;
			}
		}
	}
	for(int i=1 ; i<=n ; i++){
		if(!b1[i]) cnt++;
	}
	cout<<cnt;
}
