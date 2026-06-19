#include <bits/stdc++.h>
using namespace std;
int T;
int n, m, L, V;

struct car{
    int d, v, a;
};

struct state{
    double overin, overout;
    int a;
};

vector<car> vehicle;
vector<int> detect;
vector<int> use;

int ans = 0;
int ans2 = 0;

int cnt(state st){
    int cnt = 0;
    for(int i=0; i<detect.size(); i++){
        int detector = detect[i];
        if(detector >= st.overin && detector <= st.overout){
            cnt++;
        }
    }
    return cnt;
}

int cnt2(state st){
    int cnt = 0;
    for(int i=0; i<use.size(); i++){
        int detector = use[i];
        if(detector >= st.overin && detector <= st.overout && detector >= 0){
            cnt++;
        }
    }
    return cnt;
}

void solve() {
    vector<state> query;
	fill(use.begin(), use.end(), 0);
    ans = 0;
    ans2 = 0;
    for(auto it:vehicle){
        int d = it.d, v = it.v, a = it.a;
        double overin, overout;
        double out;
        if(a >= 0){
        	out = L;
		}
        else{
            double s = (V*V - v*v)/2/a;
            if(d+s > L) out = L;
            else out = d+s;
        }

        if(a == 0){
            if(v <= V)
                continue;
            if(v >= V){
                overin = d;
                overout = out;
            }
        }
        else{
            double s = (V*V - v*v)/2/a;
            if(d+s > out){
                if(a > 0)
                    continue;
                else{
                    overin = d;
                    overout = out;
                }
            }
            else{
                if(a > 0){
                    overin = d+s;
                    overout = out;
                }
                else{
                    overin = d;
                    overout = d+s;
                }
            }
        }
        state s;
        s.overin = overin, s.overout = overout, s.a = 1;
        query.push_back(s);
        int cnts = cnt(s);
        if(cnts > 0){
            ans++;
    	}
    }
    
    for(int i=0; i<detect.size(); i++)
        use[i]=detect[i];
    for(int i=0; i<use.size(); i++){
        use[i] = -1;
        int ava = 0;
        for(auto j:query){
            int count=cnt2(j);
            if(count>0){
                ava++;
            }
        }
        if(ava == ans){
            ans2++;
        }
        use[i]=detect[i];
    }
}

int main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n >> m >> L >> V;
        vehicle.resize(n);
        for(int i=0; i<n; i++) {
            cin >> vehicle[i].d >> vehicle[i].v >> vehicle[i].a;
        }
        detect.resize(m);
        use.resize(m);
        fill(detect.begin(), detect.end(), 0);
        fill(use.begin(), use.end(), 1);
        for(int i=0; i<m; i++)
            cin >> detect[i];
        solve();
        cout << ans << " " << ans2 << endl;
    }
    return 0;
}
