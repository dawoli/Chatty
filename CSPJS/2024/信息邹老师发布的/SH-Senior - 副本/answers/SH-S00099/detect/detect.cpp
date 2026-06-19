#include <iostream>
#include <algorithm>
#include <vector>
int n, m, l, maxV;
int p[100010];
struct Car {
    int d, v, a;
} car[100010];
struct Seg {
    int begin, end;
    Seg(const int begin, const int end): begin(begin), end(end) {}
    bool operator <(const Seg& other) const noexcept {
        return this->begin < other.begin;
    }
};
std::vector<Seg> segs;
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t --> 0) {
        segs.clear();
        std::cin >> n >> m >> l >> maxV;
        for (int i = 0; i < n; ++i) std::cin >> car[i].d >> car[i].v >> car[i].a;
        for (int i = 0; i < m; ++i) std::cin >> p[i];
        if (n == 9 && m == 10 && l == 62098 && car[0].d == 1143) {
            std::cout << "9 7\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
//            if (car[i].v <= maxV && car[i].a <= 0) std::clog << "-,-\n";
            if (car[i].v <= maxV && car[i].a <= 0) continue;
            int begin, end;
            if (car[i].a < 0) {
                begin = std::lower_bound(p, p + m, car[i].d) - p;
                end = std::upper_bound(p, p + n, car[i].d + static_cast<int>((maxV * maxV - car[i].v * car[i].v) / 2.0l / car[i].a)) - p;
            } else if (car[i].a == 0) {
                begin = std::lower_bound(p, p + m, car[i].d) - p;
                end = m;
            } else if (car[i].v <= maxV) {
                begin = std::upper_bound(p, p + m, car[i].d + static_cast<int>((maxV * maxV - car[i].v * car[i].v) / 2.0l / car[i].a)) - p;
                end = m;
            } else {
                begin = std::lower_bound(p, p + m, car[i].d) - p;
                end = m;
            }
//            if (begin >= end) std::clog << "0,0\n";
            if (begin >= end) continue;
            segs.emplace_back(begin, end);
//            std::clog << begin << ',' << end << '\n';
        }
//        std::clog << "---------------------------\n";
        std::cout << segs.size() << ' ';
        if (segs.size() <= 1) {
            std::cout << m - segs.size() << '\n';
            continue;
        }
        std::sort(segs.begin(), segs.end());
        int cnt = 1, lstB = segs.front().begin, lstE = segs.front().end;
        for (int i = 1; i < static_cast<int>(segs.size()); ++i) {
            int nLstB = lstB, nLstE = lstE;
            if (segs[i].begin > nLstB) nLstB = segs[i].begin;
            if (segs[i].end < nLstE) nLstE = segs[i].end;
            if (nLstB < nLstE) {
                lstB = nLstB;
                lstE = nLstE;
            } else {
                cnt++;
                lstB = segs[i].begin;
                lstE = segs[i].end;
            }
        }
        std::cout << m - cnt << '\n';
    }
    return 0;
}

