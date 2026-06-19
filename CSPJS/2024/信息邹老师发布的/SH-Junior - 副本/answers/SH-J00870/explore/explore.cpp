#include <bits/stdc++.h>

using namespace std;

void func(){
    int n,m,k;
    cin>>n>>m>>k;
    int x,y,d;
    cin>>x>>y>>d;
    string map[1145];
    for(int i = 0; i<n; i++){
        cin>>map[i];
    }

    int xp,yp;
    bool walked[1145][1145] = {};
    for(int i = 0; i<k; i++){
        walked[y][x] = true;
        xp = x;
        yp = y;
        switch (d){
            case 0:
                yp++;
                break;
            case 1:
                xp++;
                break;
            case 2:
                yp--;
                break;
            case 3:
                xp--;
                break;
        }
        if(xp>n || xp<=0 || yp>m || yp<=0 || map[xp-1][yp-1] == 'x'){
            d = (d+1)%4;
        }else{
            x = xp;
            y = yp;
        }
        walked[y][x] = true;
    }

    int ans = 0;
    for(int i = 1; i<=1000; i++){
        for(int j = 1; j<=1000; j++){
            if (walked[j][i])
                ans++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        func();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
