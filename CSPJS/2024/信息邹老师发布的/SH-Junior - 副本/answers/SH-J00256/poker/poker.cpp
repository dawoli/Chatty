#include <bits/stdc++.h>
using namespace std;
char a,b;
bool p[55];
int n,cnt,t;
int main() {
  freopen("poker.in","r",stdin);
  freopen("poker.out","w",stdout);
  cin>>n;
  for (int i=1;i<=n;i++) {
  	cin>>a>>b;
  	if (a=='D') t=0;
  	if (a=='C') t=13;
    if (a=='H') t=26;
    if (a=='S') t=39;
    if (b=='A') p[t+1]=1;
    else if (b=='T') p[t+10]=1;
         else if (b=='J') p[t+11]=1;
              else if (b=='Q') p[t+12]=1;
                   else if (b=='K') p[t+13]=1;
                        else p[t+b-48]=1;
  }
  for (int i=1;i<=52;i++)
    if (p[i]) cnt++;
  cout<<52-cnt;
  return 0;
}
