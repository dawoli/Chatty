#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

int n;

const int N = 100005;

int arr[N][3]{};
int sel[3][3]{};
int sensi[3];

int ssist[3]{};

void dfs(int asi, int x) {
    if (x >= n) {
        ssist[asi] = max(ssist[asi], sensi[asi]);
        return;
    }

    for (int i = 0; i < 3; i++) { 
        dfs(asi, x + 1);x=21845
        sensi[asi] += arr[x][i];
        dfs(asi, x + 1);
        sensi[asi] -= arr[x][i];
        sel[asi][i]--;
    }
}

int s;

inline void cc() {
    if (s != 0) {
        abort();
    }
}

struct Data {
    pthread_t pt;
    int asi;
    int x;
};
static void* thread_start(void * opa) {
    Data* data = (Data*)opa;
    dfs(data->asi, data->x);
    if ((sel[data->asi][data->asi]*2) >= n) return 0;
    sel[data->asi][data->asi]++;
    sensi[data->asi] += arr[data->x][data->asi];
    dfs(data->asi, data->x);
    sensi[data->asi] -= arr[data->x][data->asi];
    sel[data->asi][data->asi]--;
    dfs(data->asi, data->x);
    return 0;
}

int main() {
    ifstream in("club.in");
    ofstream out("club.out");
    int t;
    in >> t;
    pthread_attr_t attr;
    s = pthread_attr_init(&attr);
    cc();

    auto datas = new Data[3];
    datas[0] = {0,1};
    datas[1] = {1,1};
    datas[2] = {2,1};

    while (t-->0) {
        ssist[0] = ssist[1] = ssist[2] = 0;
        in >> n;
        for (int i = 0; i < n; i++) {
            in >> arr[i][0] >> arr[i][1] >> arr[i][2];
        }

    pthread_create(&datas[0].pt, &attr, &thread_start, &datas[0]);
    cc();
    pthread_create(&datas[1].pt, &attr, &thread_start, &datas[1]);
    cc();
    pthread_create(&datas[2].pt, &attr, &thread_start, &datas[2]);
    cc();
    pthread_attr_destroy(&attr);
    void* shit;
    pthread_join(datas[0].pt, &shit);
    pthread_join(datas[1].pt, &shit);
    pthread_join(datas[2].pt, &shit);
    delete[] datas;
    
        cout << max(max(ssist[0], ssist[1]), ssist[2]) << endl;
    }
}