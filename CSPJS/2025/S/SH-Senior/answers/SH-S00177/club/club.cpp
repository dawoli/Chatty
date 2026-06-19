#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const int N = 1e5+10; ////////// 1e5!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int n, mann; // man:every section mans <= man
struct Man{
    int num;
    pair<int, int> p[4]; // ManYiDu
}a[N];
int d[N];
int se[4];

bool cmp1(pair<int,int> a, pair<int,int> b){
    if(a.second >= b.second){
        return true;
    }
    return false;
}

bool cmp2(Man a, Man b){
    if(a.p[1].second >= b.p[1].second){
        return true;
    }
    return false;
}

bool cmp3(Man a, Man b){
    if(a.p[1].second > b.p[1].second){
        return true;
    }else if(a.p[1].second == b.p[1].second && a.p[2].second >= b.p[2].second){
        return true;
    }
    return false;
}

void funa(){
    int sum = 0, nowman = 0;
    sort(a+1, a+1+n, cmp2);
    for(int i = 1; i <= n; i++){
        nowman++;
        if(nowman <= mann) sum += a[i].p[1].second;
        else break;
    }
    printf("%d\n", sum);
}

void funb(){
    int sum = 0, nowman = 0, idx = 1;
    sort(a+1, a+1+n, cmp3);
    for(int i = 1; i <= n; i++){
        nowman++;
        if(nowman <= mann) sum += a[i].p[1].second;
        else{
            nowman = 1;

            sum += a[i].p[1].second;
        }
    }
    printf("%d\n", sum);
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while(T--){
        bool f_a = true, f_b = true;
        scanf("%d", &n);
        mann = n / 2;
        for(int i = 1; i <= n; i++){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if(!(y == 0 && z == 0)){
                f_a = false;
            }
            if(!(z == 0)){
                f_b = false;
            }

            a[i].p[1] = make_pair(1, x);
            a[i].p[2] = make_pair(2, y);
            a[i].p[3] = make_pair(3, z);
            sort(a[i].p + 1, a[i].p + 4, cmp1);
        }

        if(f_a){
            funa();
        }else if(f_b){
            funb();
        }else{
            // KO
        }
    }


    return 0;
}

/*
bool cmp2(Man a, Man b){
    if(a.best == 1 && b.best != 1){
        return true;
    }else if(b.best == 1 && a.best != 1){
        return false;
    }else if(a.best < b.best){
        return true;
    }else{
        if(a.a1 > b.a1){
            return true;
        }else if(a.a1 == b.a1 && a.a2 > b.a2){
            return true;
        }else if(a.a1 == b.a1 && a.a2 == b.a2 && a.a3 > b.a3){
            return true;
        }
        return false;
    }
}
*/
