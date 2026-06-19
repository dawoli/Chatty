#include<bits/stdc++.h>
using namespace std;
int ps[1000001],os[1000001],n,coun;
void calc(int a1,int b1,int a2,int b2){
    int i;
    if(a1>=b1) return;
    for(i=a2;i<=b2-1;i++){
        if(ps[a1+1]==os[i]) break;
    }
    if(i==b2-1)coun++;
    calc(a1+1,a1+1+(i-a2),a2,i);
    calc(a1+1+(i-a2)+1,b1,i+1,b2-1);
}
int qw(int b)
{
	int ans = 1, base = 2;
	while(b > 0)
    {
		if(b & 1)
			ans *= base;

        base *= base;
		b >>= 1;
	}
	return ans;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ps[i];
    }
    for(int i=0;i<n;i++){
        cin>>os[i];
    }
    calc(0,n-1,0,n-1);
    cout<<qw(coun);
    return 0;
}
