#include <iostream>
#include <algorithm>
using namespace std;

int scoresarr[10010];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m; cin >> n >> m;
    int totalPeople = n*m;
    for(int i = 1; i <= totalPeople; i++){
        cin >> scoresarr[i];
    }

    int targetScore = scoresarr[1];

    sort(scoresarr + 1, scoresarr + 1 + totalPeople);

    int targetIndex = 0;
    for(int i = 1; i <= totalPeople; i++){
        if(scoresarr[i] == targetScore) {
            targetIndex = totalPeople - i + 1;
            break;
        }
    }
    // cout << targetIndex << endl;

    int nowindex = 1;
    for(int i = 1; i <= m - 1; i += 2){
        for(int j = 1; j <= n; j++){
            // cout << "TRYING I = " << i << " J = " << j << " INDEX = " << nowindex << endl;
            if(nowindex == targetIndex){
                cout << i << " " << j << endl;
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
            nowindex++;
        }
        for(int j = n; j >= 1; j--){
            // cout << "TRYING I = " << i << " J = " << j << " INDEX = " << nowindex << endl;
            if(nowindex == targetIndex){
                cout << i + 1 << " " << j << endl;
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
            nowindex++;
        }
    }

    if(m % 2){
        int i = m;
        for(int j = 1; j <= n; j++){
            //cout << "TRYING I = " << i << " J = " << j << " INDEX = " << nowindex << endl;
            if(nowindex == targetIndex){
                cout << i << " " << j << endl;
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
            nowindex++;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}