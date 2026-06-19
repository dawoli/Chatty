#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
int n,r[N];
bool flag=1;
void solve1(){
	int one=0,two=0;
	for(int i=1;i<=n;i++)
	    if(r[i]==1)
	        one++;
	    else
	        two++;
	int ans=0;
	if(one>=two)
	    ans=one;
	else
	    ans=two;
	printf("%d\n",ans);
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf ("%d",&n);
	for(int i=1;i<=n;i++){
	    scanf ("%d",&r[i]);
	    if(r[i]>2)flag=0;
	}
	 
	if(flag==1){
		solve1();
		return 0;
	}
		int cnt=n;
		sort(r+1,r+1+n);
	    int j=1;
		for(int i=1;i<n;i++)
		    for(int k=j+1;k<=n;k++){
			    if(r[k]>r[i] && k>j){
			        cnt--;
			        j=k;
			        break;
				}
				 
			}
			printf("%d\n",cnt);
	return 0;
}
