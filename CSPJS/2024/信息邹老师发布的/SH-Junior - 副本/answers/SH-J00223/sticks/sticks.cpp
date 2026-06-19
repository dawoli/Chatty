#include<iostream>
#include<algorithm>
#include<cstdio>
#define INF 1e9
using namespace std;
int T,n;
long long ans=INF;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int solve(int n,long long number){
    if(n==0){
        ans=min(ans,number);
        return ans;
    }
    if(n<0) return ans;
    for(int i=0;i<10;i++){
        if(number==0&&i==0||i==3||i==5||i==9)continue;//0-
        solve(n-num[i],number*10+i);
    }
    return ans;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
    cin>>T;
    for(int o=0;o<T;o++){
    	ans=INF;
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<solve(n,0)<<endl;
    }
    return 0;
} 
