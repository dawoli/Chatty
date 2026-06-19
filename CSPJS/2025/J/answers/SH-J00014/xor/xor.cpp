#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],m[500005],ans;

int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=0;i<n;i++){
cin>>a[i];
m[i]=a[i];
}

for(int i=0;i<n;i++){
if(m[i]==k){ 
ans++;
m[i]=-1;
}
}

for(int i=1;i<n;i++){
for(int j=0;j<n-i;j++){
if(m[j]==-1)
continue;
else if(m[j+1]==-1)
m[j]=-1;
else
m[j]=m[j]^m[j+1];

if(m[j]==k){ 
ans++;
m[j]=-1;
}
}
}

cout<<ans;

return 0;
}
