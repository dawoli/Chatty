#include<bits/stdc++.h>
using namespace std;
vector<int>s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int tmp;
            cin>>tmp;
            s.push_back(tmp);
        }
    int scr=s[0];
    sort(s.begin(),s.end(),greater<int>());
    int rnk=0;
    for(int i=0;i<n*m;i++){
        if(s[i]==scr){
            rnk=i+1;
            break;
        }
    }
    //cout<<rnk<<endl;
    int col=ceil(1.0*rnk/n);
    int x=rnk%(2*n);
    if(x==0)x=2*n;
    int row=0;
    if(1<=x&&x<=n)row=x;
    else row=2*n-x+1;
    cout<<col<<" "<<row<<"\n";
    return 0;
}
//g++ -O2 -std=c++14 -static -Wall seat.cpp -o seat