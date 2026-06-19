#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
      if(n==1){
            cout<<51;
            return 0;
      }
    vector<string> a(n);
    vector<string> b;
    int cnt=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0) b.push_back(a[i]);
        else{
            bool flag=true;
            for(int j=0;j<cnt;j++){
                if(b[j]==a[i]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                b.push_back(a[i]);
                cnt++;
            }
        }
    }
    cout<<52-cnt;
    return 0;
}
