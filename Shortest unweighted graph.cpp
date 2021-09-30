#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000;

int front = 0, rare = 0, i, j, k, n, qu[MAX], p[MAX], father = 0, V;

int v = 0, visit[MAX], visited[MAX];

int G[50001][2], ribs;
vector <int> M[MAX];
vector <int> path_arr;


void spisuk_na_rebra() {
    for (int i = 0; i < ribs; i++) {
        for (int j = 0; j < 2; j++)
            cin >> G[i][j];
    }
}


void Spisuk_ot_Susedi() {

    for (i = 1; i <= n; i++) {
        M[i].push_back(0);
    }

    for (i = 0; i < ribs; i++) {

        M[G[i][0]].push_back(G[i][1]);
        M[G[i][1]].push_back(G[i][0]);
    }
}


void path(int r) {
    if (r != 0) {
        path_arr.push_back(r);
        path(p[r]);
    }
}



int main() {
    cout << "Enter the number of V: ";
    cin >> n;
    cout << "Enter the number of ribs: ";
    cin >> ribs;
    cout << "Enter the initial V for starting shortest path: ";
    cin >> V;

    spisuk_na_rebra();
    Spisuk_ot_Susedi();

    v = 1;
    visited[v] = 1;
    k = 1;
    p[v] = 0;
    father = v;

    while (k < n) {
        for (auto it = M[v].begin() + 1; it != M[v].end(); it++) {
            if (visited[*it] != 1 && visit[*it] != 1) {
                p[*it] = father;
                visit[*it] = 1;
                qu[rare++] = *it;
            }
        }
        v = qu[front++];
        father = v;
        k++;
        visit[v] = 0; visited[v] = 1;
    }

    path(V);

    for (auto it = path_arr.rbegin(); it != path_arr.rend(); it++) {
        cout << *it << " ";
    }

    cout << endl;



    return 0;
}
