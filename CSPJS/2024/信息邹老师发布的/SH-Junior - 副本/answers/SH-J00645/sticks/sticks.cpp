#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int num[]={6,2,5,5,4,5,6,3,7,6};
int sum(int n){
    if(n==0)return 6;
    int ans=0;
    while(n){
        ans+=num[n%10];
        n/=10;
    }
    return ans;
}
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int flg=1;
        scanf("%d",&n);
        for(int i=1;i<N;i++){
            if(sum(i)==n){
                printf("%d\n",i);
                flg=0;
                break;
            }
        }
        if(flg)puts("-1");
    }
	return 0;
}
