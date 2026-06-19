#include<bits/stdc++.h>
using namespace std;

const int NM = 1e3+10;

int n, m;
int a[NM];
int r_score;

bool cmp(int x, int y){
    return x > y;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=n*m; i++){
        cin >> a[i];
    }

    r_score = a[1];

    sort(a+1, a+n*m+1, cmp);

    int L = 1, R = n*m;
    int pos = 0;

    while(L <= R){
        int mid = (L+R) / 2;
        if(a[mid] == r_score){
            pos = mid;
            break;
        } else{
            if(a[mid] < r_score){
                R = mid-1;
            } else{
                L = mid+1;
            }
        }
    }

    int n_ans = (pos%n == 0) ? (n) : (pos%n);
    int m_ans = (pos%n == 0) ? (pos/n) : (pos/n + 1);
    if(m_ans%2 == 0){
        n_ans = n-n_ans+1;
    }

    cout << m_ans << " " << n_ans << endl;


    fclose(stdin);
    fclose(stdout);

    return 0;
}
