vector<int> parent;

void make_set(int v){
    parent[v] = v;
}

int find_set(int v){
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        parent[b] = a;
    }
}

int union_mod(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        parent[b] = a;
        return 1;
    }
    return 0;
}

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = n;

        parent = vector<int>(n);
        for(int i=0; i<n; i++){ make_set(i); }
        
        for( auto x : edges ){
            res -= union_mod(x[0], x[1]);
        }

        return res;
    }
};
