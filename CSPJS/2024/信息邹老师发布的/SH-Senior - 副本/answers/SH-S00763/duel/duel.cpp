#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,cnt=0;
	int atmi[100005];
	bool atmior[100005];
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>atmi[i];
		atmior[i]=1;
	}
	for (int i=1;i<=n;i++){
		if (max(atmi[i],atmi[i+1])-min(atmi[i],atmi[i+1])>=1 && atmior[i] && atmior[i+1]){
			int x;
			if (atmi[i]>atmi[i+1]) x=i;
			else x=i+1;
			atmior[x]=0;
			min(atmi[i],atmi[i+1])
			continue;
		}
	}
	for (int i=1;i<=n;i++){
		if (!atmior){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
