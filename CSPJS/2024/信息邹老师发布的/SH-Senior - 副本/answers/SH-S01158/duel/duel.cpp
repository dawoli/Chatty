#include <bits/stdc++.h>

using namespace std;

int n;
int mons[100000];
int vis[100000];
int killed[100000];
int num;
int nummin;
void dfs()
{
    for(int i=1;i<=n;i++){
        if(vis[i]){
            continue;
        }
        if(killed[i]){
            continue;
        }
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            if(killed[j]){
                continue;
            }
            if(mons[i]>mons[j]){
                vis[i]=true;
                killed[j]=true;
                num--;
                nummin=min(nummin,num);
                dfs();
                vis[i]=false;
                killed[j]=false;
                num++;
            }
        }
    }
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    num=n;
    nummin=n;
    for(int i=1;i<=n;i++){
        cin>>mons[i];
    }
    dfs();
    cout << nummin << endl;
    return 0;
}
