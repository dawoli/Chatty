#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn],head=0,tail=0,ans,g;
bool isduel[maxn];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	memset(isduel,false,sizeof(isduel));
	cin>>n;ans=n;g=0;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	while(a[0]==a[tail]) tail++;
	while(tail<n&&g<n){
		tail++;head++;ans--;
		if(isduel[head-1]) g++;
		else g+=2;
		isduel[tail-1]=true;
		while(a[head]==a[tail]) tail++;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
