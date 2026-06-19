#include <bits/stdc++.h>
using namespace std;
#define int long long

int T,n,m,L,V,p[100010];

double eps = 0.0001;  // 浮点数精度问题

struct Car {
    double d,v,a;
    double TX(double t) {
        return v * t + 0.5 * a * t * t;
    }
    double XT(double x) {
        ;
    }
    double XV(double x) {
        double res = v * v + 2 * a * (x - d);
        if (abs(res) <= eps) {  // res == 0
            return 0;  // 若等于0则返回0，直接判定不超速
        } else if (res >= 0) {  // 匀减速运动的速度确保大于0
            return sqrt(res);
        } else {
            return -1.0;
        }
    }
    double wholeT() {
        if (a >= 0) {  // 对于匀加速运动，计算到终点的时间
            ;
        } else {  // 对于匀减速运动，需要多计算到刹车的时间
            ;
        }
    }
    double VX() {  // 由初速度计算加速到超速所发生的位移
        if (a == 0) {
            return -1;
        }
        return d + (V * V - v * v) / 2 / a;
    }
} car[100010];

int isdel[100010]; 

//int DFS(int depth, int i) {
//    if () {
//        return;
//    }
//    ++cnt;
//    isdel[
//    Record[i].erase(j);
//    DFS();
//    Record[i].erase(j);
//}

signed main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&T);
    while (T--) {
        scanf("%lld %lld %lld %lld",&n,&m,&L,&V);
        for (int i=1; i<=n; ++i) {
            scanf("%lf %lf %lf",&car[i].d,&car[i].v,&car[i].a);
        }
        for (int i=1; i<=m; ++i) {
            scanf("%lld",&p[i]);
        }
        sort(p+1,p+m+1);
        int cnt = 0;
        set<int> overSpeed;  // 超速的车辆统计（去重）
		set<int> Record[100010];  // Record[i]存储了所有记录i车超速的测速仪
        // for (int j=1; j<=n; ++j) {  // 车
        //     for (int i=1; i<=m; ++i) {  // 测速仪
        //         double v_t_ = car[j].XV(p[i]);
        //         if (abs(v_t_) <= eps) {  // v_t_ == 0
        //             continue;
        //         } else if (v_t_ > 0) {
        //             if (v_t_ - V > eps) {  // 除去相等的情况
        //                 ++cnt1;
        //                 overSpeed.insert(i);
        //                 break;
        //             }
        //         } else {
        //             continue;  // 已经刹车了，肯定不超速
        //         }
        //     }
        // }
        for (int i=1; i<=n; ++i) {  // 车
            if (car[i].v <= V and car[i].a < 0) {  // 初速度达不到且匀（减）速
                continue;  // 一定不超速
            }
            if (car[i].a == 0) {
                if (car[i].v > V) {
                    overSpeed.insert(i);
                    for (int j=1; j<=m; ++j) {
                        Record[i].insert(j);
                            // printf("%d %d\n",i,j);
                    }
                }
                continue;
            }
            double overV_X = car[i].VX();
                // printf("%d %lf ",i,overV_X);
            if (car[i].a > 0) {
                if (overV_X > L) {  // 过了终点后才超速
                    continue;
                }
                for (int j=m; j>=1; --j) {  // 测速仪倒着搜
                    if (overV_X < p[j]) {
                        overSpeed.insert(i);
                        Record[i].insert(j);
                            // printf("%d %d\n",i,j);
                        // break;
                    }
                }
            } else {
                for (int j=1; j<=m; ++j) {  // 测速仪正着搜
                    if (overV_X > p[j] and car[i].d <= p[j]) {  // 保证经过该站点
                        overSpeed.insert(i);
                        Record[i].insert(j);
                            // printf("%d %d\n",i,j);
                        // break;
                    }
                }
            }
                // printf("%d\n",overSpeed.back() == i);
        }
        for (int j=1; j<=m; ++j) {  // 测速仪
            bool flag = 1;
            for (int i=1; i<=n; ++i) {  // 车
                    // printf("%d %d %d\n",j,Record[i].size(),*Record[i].begin());
                if (Record[i].size() == 1 and *Record[i].begin() == j) {
                    flag = 0;  // 有一辆车只有这个测速仪能测出超速
                }
            }
            if (flag) {
                ++cnt;
//                for (int k=1; k<=m; ++k) {
//                    ;
//                }
            }
        }
        // for (int j=1; j<=m; ++j) {
        //     for (int i=1; i<=n; ++i) {
        //         if (Record[i].size() == 1 and *Record[i].begin() == j) {
        //             dp[i][0] = dp[i-1]; // 有一辆车只有这个测速仪能测出超速
        //         } else {
        //             dp[i][0] = max(dp[i],dp[i-1] + 1);
        //             dp[i][1] = max();
        //             //
        //         }
        //     }
        // }
        printf("%lld ",overSpeed.size());
        printf("%lld\n",cnt);
    }
    return 0;
}
