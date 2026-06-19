#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    long long cnt=0;
    if (n==3){
        if ((a[1]+a[2]+a[3])>2*max(a[1],max(a[2],a[3]))){
            cnt++;
        }
        cout << cnt;
        return 0;
    }else{
        for(int i=3;i<=n;i++){
            long long subcnt=1;
            long long m=1;
            for (int j=0;j<=i-1;j++){
                subcnt*=(n-j);
                m*=(j+1);
            }
            subcnt/=m;
            cnt+=subcnt;
        }
        cout << cnt%998244353;
    }
	return 0; 
}
