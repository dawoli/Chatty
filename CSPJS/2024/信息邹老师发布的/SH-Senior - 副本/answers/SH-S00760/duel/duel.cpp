#include<bits/stdc++.h>
using namespace std;
int n,r[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	int i=2,j=1;
	while(r[i]==r[1])i++;
	for(i;i<=n;i++){
		if(r[i]>r[j]){
			j++;
		}
	}
	cout<<n-j+1<<endl; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
