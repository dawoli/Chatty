#include <bits/stdc++.h>
using namespace std;
int T;
int N, M, L, V;
int d[100005];
int v[100005];
int a[100005];
int p[100005];
struct node{
    int s;
    int e;
} idx[3005];
int cidx;
bool cmp(node a, node b) {
    if(a.s != b.s) return a.s < b.s;
    return a.e < b.e;
}

void method1(int N, int M, int L, int V) {
    cidx = 0;
    sort(p + 1, p + M + 1);
    int speeders = 0;
    for(int i = 1; i <= N; i++) {
        if(a[i] == 0) {
            if(v[i] > V) {
            	speeders++;
//            	cout << i << " speeds" << endl; 
                int l = 1;
                int r = M;
                while(l < r) {
                	int mid = (l + r) >> 1;
                	if(p[mid] < d[i]) l = mid + 1;
                	else r= mid;
				}
				cidx++;
				idx[cidx].s = l;
				idx[cidx].e = M;
				
			}
        }
        else if(a[i] > 0) {
            if(v[i] > V) {
                speeders++;
//                cout << i << " speeds" << endl; 
                
                int l = 1;
                int r = M;
                while(l < r) {
                	int mid = (l + r) >> 1;
                	if(p[mid] < d[i]) l = mid + 1;
                	else r= mid;
				}
				cidx++;
				idx[cidx].s = l;
				idx[cidx].e = M;
                continue;
            }
            long long dist = (V * V - v[i] * v[i]);
            if(dist % (2 * a[i]) == 0) dist /= 2 * a[i];
            else dist /= 2 * a[i], dist++;
            if(d[i] + dist > L) continue;
            int l = 1;
            int r = M;
            int msd = d[i] + dist;
            while(l < r) {
                int mid = (l + r) >> 1;
                if(p[mid] < msd) l = mid + 1;
                else r = mid;
            }
            if(p[l] < msd) continue;
            speeders++;
//            cout << i << " speeds" << endl; 
            cidx++;
            idx[cidx].s = l;
            idx[cidx].e = M;
        }
        else {
            if(v[i] < V) continue;
            long long dist = (v[i] * v[i] - V * V);	
            a[i] = abs(a[i]);
            if(dist % (2 * a[i]) == 0) dist /= 2 * a[i], dist--;
            else dist /= 2 * a[i];
            int msd = d[i] + dist;
            int l = 1;
            int r = M;
            while(l < r) {
                int mid = (l + r) >> 1;
                if(p[mid] < d[i]) l = mid + 1;
                else r = mid;
            }
            int hh = l;
            
            l = 1;
            r = M;
            while(l < r) {
                int mid = (l + r) >> 1;
                if(p[mid] <= msd) l = mid + 1;
                else r = mid;
            }
            l = r - 1;
            if(l < hh) continue;
            cidx++;
            idx[cidx].s = hh;
            idx[cidx].e = l;
            speeders++;
//            cout << i << " speeds" << endl; 
        }
    }
    sort(idx + 1, idx + cidx + 1, cmp);
    int needed = 1;
//    cout << cidx << endl;
//    cout << idx[1].s << " " << idx[1].e << endl;
    for(int i = 1; i < cidx; i++) {
//    	cout << idx[i + 1].s << " " << idx[i + 1].e << endl;
        if(idx[i].e < idx[i + 1].s) {
            needed++;
//            cout << i << "need" << endl;
            continue;
        }
        else if(idx[i].e >= idx[i + 1].e) continue;
        else idx[i + 1].e = idx[i].e;
    }
    cout << speeders << " " << M - needed << endl;
}

void method2(int N, int M, int L, int V) {
    int speeders = 0;
    for(int i = 1; i <= N; i++) {
    	if(a[i] == 0) {
    		if(d[i] > p[M]) continue;
    		if(v[i] > V) speeders++;
    		continue;
		}
		if(p[M] < d[i]) continue;
		if(v[i] > V) {
			speeders++;
			continue;
		}
        int dt = p[M] - d[i];
        long long v_sq = v[i] * v[i] + (2 * a[i] * dt);
        if(v_sq > V * V) speeders++;
    }
    if(speeders) cout << speeders << " " << M - 1 << endl;
    else cout << 0 << " " << M << endl; 
}




void ddd() {
    cin >> N >> M >> L >> V;
    for(int i = 1; i <= N; i++) {
        cin >> d[i] >> v[i] >> a[i];
    }
    for(int i = 1; i <= M; i++) {
        cin >> p[i]; 
    }
    if(N <= 20) method1(N, M, L, V);
    else {
	    bool c = 1; 
	    for(int i = 1; i <= M && c; i++) {
	        if(a[i] < 0) c = 0;
	    }
	    if(c) method2(N, M, L, V);
	    else method1(N, M, L, V);
	}
}
int main() {
     freopen("detect.in", "r", stdin);
     freopen("detect.out", "w", stdout);

    cin >> T;
    while(T--) ddd();

    return 0;
}