#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream fin("seat.in");
    ofstream fout("seat.out");
    int n,m,c,r,rank=1,a[105];
    fin>>n>>m;
    for(int i=0;i<n*m;++i){
        fin>>a[i];
        if(i>0&&a[i]>a[0]){
            ++rank;
        }
    }
    c=int(ceil(1.0*rank/n));
    if(c%2==0){
        r=n-rank%n+1;
    } else {
        r=rank%n;
        if(r==0)r=n;
    }
    fout<<c<<" "<<r<<endl;
    return 0;
}