#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

const int ON = 1, OFF = 0;
vector<int> vertexes;
vector<int> degree_out;
vector<vector<int>> adjoint_matrix;
vector<pair<int, int>> num_pairs;
int size;
void generate_conflict_map(vector<int> arr, int n)
{
    num_pairs = vector<pair<int, int>>();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] == arr[j]) num_pairs.push_back({i, j});
    size = num_pairs.size();
    if (size == 0) return;
    vertexes = vector<int>(size);
    degree_out = vector<int>(size, 0);
    adjoint_matrix = vector<vector<int>>(size, vector<int>(size, OFF));
    for (int i = 0; i < size; i++) vertexes[i] = arr[num_pairs[i].second];
    for (int i = 0; i < size; i++) 
        for (int j = 0; j < size; j++)
        {
            auto u = num_pairs[i];
            auto v = num_pairs[j];
            if (u == v) continue;
            if (max(u.first, u.second) < min(v.first, v.second) || max(v.first, v.second) < min(u.first, u.second))
            {    adjoint_matrix[i][j] = ON; adjoint_matrix[j][i] = ON; degree_out[i]++;}
        }
}

int color()
{
    if (size == 0) return 0;
    vector<int> answers(size, 0);
    vector<bool> vis(size, false);
    stack<int> stk;
    stk.push(0);

    int total = 0, last = 0;
    for (int i = 0; i < size; i++)
        if (degree_out[i] == 0)
            answers[i] = vertexes[i];
    while(!stk.empty())
    {
        int p = stk.top();
        stk.pop();

        if (vis[p])
        {
            vector<int> temp;
            int max = 0;
            int max_index = 0;
            for (int i = 0; i < size; i++)
                if (adjoint_matrix[i][p] == ON)
                {
                    if (vertexes[i] > max) {max = vertexes[i]; max_index = i;}
                    temp.push_back(i);
                }

            for (auto v : temp)
                if ( v != max_index)
                    answers[v] = 0;
            continue;
        } else answers[p] = vertexes[p];

        vis[p] = true;

        if (degree_out[p] > 0)
        for (int i = 0; i < size; i++)
            if (adjoint_matrix[p][i] == ON)
                stk.push(i);     
    }

    for (auto v : answers)
        total += v;

    return total;    
}

void loop()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    generate_conflict_map(arr, n);
    cout << color() << endl;
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
        loop();
    return 0;
}