#include<bits/stdc++.h>
using namespace std;
int n, q;
pair<string, string> getDiff(string t1, string t2) {
    string da, db;
    for(int i = 0; i < t1.size(); i++) {
        if(t1[i] != t2[i]) {
            da = t1.substr(i, t1.size());
            db = t2.substr(i, t2.size());
            break;
        }
    }
    for(int i = t1.size() - 1; i > 0; i--) {
        if(t1[i] != t2[i]) {
            break;
        }
        da.pop_back();
        db.pop_back();
    }
    return make_pair(da, db);
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    map<string, string> mapping;
    map<pair<string, string>, int> diffCount;
    set<int> lengths;
    for(int i = 0; i < n; i++) {
        string tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        if(tmp1 == tmp2) {
            continue;
        }
        mapping[tmp1] = tmp2;
        lengths.insert(tmp1.size());
        diffCount[getDiff(tmp1, tmp2)]++;
    }
    while(q--) {
        string t1, t2;
        cin >> t1 >> t2;
        if(t1.size() != t2.size()) { // wish all of the samples were like this, but alas...
            cout << 0 << '\n';
            continue;
        }
        // find the differences between t1 & t2
        cout << diffCount[getDiff(t1, t2)] << '\n';
        
        // for(int i = 0; i < t1.size(); i++) {
        //     for(auto l : lengths) { // shuold be sorted from small to big
        //         if(l + i > t1.size()) {
        //             break;
        //         }
        //         string tmp = t1.substr(i, l);
        //         if(mapping.find(tmp)) {
        //             if(t2)
        //         }
        //     }
        // }
    }
    return 0;
}
