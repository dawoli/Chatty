#include<bits/stdc++.h>
using namespace std;

int m,n,a[105],s[11][11],x=0,y=0,k=0,cnt=0;

int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=0;i<m*n;i++){
cin>>a[i];
cnt++;
}

for(int i=0;i<cnt;i++){
if(a[0]<a[i])
k++;
}

x=k/n;
if(x%2==0)
y=k%n;
else
y=n-(k%n)-1;

cout<<x+1<<' '<<y+1;

return 0;
}
