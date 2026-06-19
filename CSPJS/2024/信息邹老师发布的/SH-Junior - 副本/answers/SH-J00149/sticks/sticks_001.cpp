#include<bits/stdc++.h>
using namespace std;
int aa[10] = {0,0,1,7,4,2,6,8,19,18};
int a[10] = {0,0,1,7,4,2,0,8,19,18};
int b[50];
int dp[1001];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin>>n;
    for(int i = 0;i<n;i++){
        cin>>b[i];
    }
    int amax = 0;
    for(int i = 0;i<n;i++){
        amax = max(b[i],amax);
    }
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2;i<=amax;i++){
        if(i<=9){
            dp[i] = aa[i];
        }else{
            dp[i] = 100001;
            for(int j = 2;j<8;j++){
                dp[i] = min(dp[i],dp[i-j]*10 + a[j]);
            }
            for(int k = 8;k<10;k++){
                dp[i] = min(dp[i],dp[i-k]*100 + a[k]);
            }
        }
    }
    for(int i = 0;i<n;i++){
    	if(b[i] == 1){
    		cout<<-1<<endl;
		}else{
			cout<<dp[b[i]]<<endl;
		}

    }
    return 0;
}

