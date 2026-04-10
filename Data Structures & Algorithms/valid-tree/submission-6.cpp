class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n - 1 < edges.size()) return false;
        vector<int> p(n, 0);

        for(int i = 0; i < n; i++) p[i] = i;

        for(auto e: edges) {
            if(!unite(p, e[0], e[1])) return false;
        }

        int t = -1;

        for(auto &a: p) {
            if(t == -1) t = find(p, a);
            else if(t != find(p, a)) return false;
        }

        return true;
    }

    bool unite(vector<int> &p, int x, int y){
        int px = find(p, x);
        int py = find(p, y);
        if(px == py) return false;
        p[px] = py;
        return true;
    }

    int find(vector<int> &p, int x) {
        if(x == p[x]) return x;
        return find(p, p[x]);
    }

};
