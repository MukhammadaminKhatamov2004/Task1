//#include <iostream>
//using namespace std;

//int main()
//{
//    double a, b, P;
//    printf("Width of the rectangle: ");
//    cin >> a;
//    printf("\nLength of the rectangle: ");
//    cin >> b;
//    P = (a + b) * 2;
//    printf("\nPerimeter of the rectangle - %4.1f", P);
//    return 0;
//}

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

vector<pair<int, int>> graph [100000];
bool used[100000];

int main() {
int m, n;
cin >> n >> m;

for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u]. push_back({w,v});
    graph[v]. push_back({w,u});
}
int mst_weight = 0;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> q;

q.push({0, 0});

while(!q.empty()) {
    pair<int, int> c = q.top;
    q.top;

    int dst = c.first, v = c.second;

    if(used[v]) {
        continue;
    }
    used[v] = true;
    mst_weight += dst;

    for(pair<int, int> e: graph[v]) {
        int u = e.second, len_vu = e.first;

        if(!used[u]) {
            q.push({len_vu, u});
        }
    }
}

cout << "Minimum spanning tree weight: " << mst_weight << endl;
}
