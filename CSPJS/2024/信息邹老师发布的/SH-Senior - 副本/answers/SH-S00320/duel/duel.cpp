#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,r[N],cnt;
bool u[N],o[N];
bool cmp(int a,int b){
	return a<=b;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r,r+n+1,cmp);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(r[i]>r[j] && o[j]==0 && u[i]==0){
				cnt++;
				o[j]=1;
				u[i]=1;
			}
		}
	}
	cout<<n-cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
