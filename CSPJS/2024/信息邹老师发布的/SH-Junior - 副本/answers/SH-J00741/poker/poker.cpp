#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int N;
    cin >> N;
    int A = 0;
    vector<string> strs1(N);

    for (int i = 0;i < N;i++){
        cin >> strs1[i];
    }

    for (int i = 0;i < N;i++){
        for (int j = i;j < N;j++){
            if (strs1[i] == strs1[j] && i != j){
                A++;
            }
        }
    }

    int sum = 52 + A - N;

    cout << sum;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
