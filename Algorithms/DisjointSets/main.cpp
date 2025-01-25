// GROUP:   X
// ID:      XXXXXXXX
// Assign:  02
// Assign:  DisjointSets
// UVA:     10608
// Name:    XXX MY FULL NAME

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct DisjointSets
{
    int n;
    int* parent;
    int* num_nodes;

    void Initialize(int _n) {
        n = _n;
        parent = new int[n+1];
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        num_nodes = new int[n+1];
        for(int i = 1; i <=n; i++) {
            num_nodes[i] = 1;
        }
    }
    void Destroy() {
        delete[] parent;
        delete[] num_nodes;
        n = 0;
    }
    int Find(int i) {
        if(parent[i] == i) {
            return i;
        }
        return Find(parent[i]);
    }
    bool Union(int i, int j) {
        int iParent = Find(i);
        int jParent = Find(j);

        if(iParent == jParent) {
            return 0;
        }


        int iSize = num_nodes[iParent];
        int jSize = num_nodes[jParent];


        if(iSize > jSize) {
            parent[jParent] = iParent;
            num_nodes[iParent] += jSize;
        } else {
            parent[iParent] = jParent;
            num_nodes[jParent] += iSize;
        }

        return 1;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        DisjointSets s;
        s.Initialize(n);
        while (m--) {
            int a, b;
            cin >> a >> b;
            s.Union(a, b);
        }
        int max = s.num_nodes[1];
        for (int i = 1; i <= s.n; i++) {
            if (s.num_nodes[i] > max) {
                max = s.num_nodes[i];
            }
        }
        cout << max << endl;
        s.Destroy();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
