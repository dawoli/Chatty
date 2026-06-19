#include <cstdio>
using namespace std;
#define GET(BEGIN_, END_) (a[END_+1]^a[BEGIN_])
int b_[500000+1] /* the count. */;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    int x[n], a[n+1]; a[0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++) {
        a[i+1] = a[i+1-1] ^ x[i];
    }
    /*
    int a[n][n];
    for (int i = 0; i < n; i++) {
        a[i][i] = x[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            a[i][j] = a[i][j-1] ^ x[j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            printf("[%d,%d]=%d\t", i, j, a[i][j]);
        }
        printf("\n");
    }
    */
    /*
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            //printf("[%d,%d]=%d\t", i, j, a[j+1]^a[i]);
        }
        printf("\n");
    }
    int begin_ = 5, end_ = 10;
    printf("[%d,%d]=%d\n", begin_, end_, a[end_+1]^a[begin_]);
    for (int i = begin_; i <= end_; i++) printf("%d(%d) ", x[i], a[i+1]^a[begin_]);
    */
    //printf("%d", n);
    
    b_[0] = 0;
    //int*b = b_+1;
    for (int end_ = 0; end_ < n; end_++) {
        int cnt=0;
        b_[1+end_] = -1;
        for (int begin_ = end_; begin_ >= 0; begin_--) {
            cnt = 0;
            if (GET(begin_,end_) == k) cnt++;
            int v = b_[1+begin_-1]+cnt;
            if (v > b_[1+end_]) b_[1+end_] = v;
            //printf("%d([..~%d])+%d[%d~%d] ", b_[1+begin_-1], begin_-1, cnt, begin_, end_);
        }
        //printf("\n");
    }
    printf("%d\n", b_[1+n-1]);
    return 0;
}
