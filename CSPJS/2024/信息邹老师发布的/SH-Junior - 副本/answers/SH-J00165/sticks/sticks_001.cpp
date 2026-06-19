#include <bits/stdc++.h>
using namespace std;

map<int,int> map1;
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    map1[1] = 2;
    map1[7] = 3;
    map1[4] = 4;
    map1[2] = 5;
    map1[3] = 5;
    map1[5] = 5;
    map1[0] = 6;
    map1[6] = 6;
    map1[9] = 6;
    map1[8] = 7;

    int ques;
    cin >> ques;
    for(int i = 1; i <= ques; i++){
        int n;
        cin >> n;

        switch (n){
            case 1: {printf("-1");continue;}
            case 2: {printf("1");continue;}
            case 3: {printf("7");continue;}
            case 4: {printf("4");continue;}
            case 5: {printf("2");continue;}
            case 6: {printf("6");continue;}
            case 7: {printf("8");continue;}
            case 8: {printf("10");continue;}
            case 9: {printf("18");continue;}
            case 10: {printf("23");continue;}
            case 14: {printf("88");continue;}
            case 18: {printf("208");continue;}
        }

        int k = ceil(1.0*n/7);
        if(n % 7 == 0){
            for(int i = 1; i <= k; i++){
                cout << '8';
            }
            cout <<<endl;
            continue;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
