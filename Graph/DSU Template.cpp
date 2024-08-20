// Practise Problems 
// https://leetcode.com/problems/longest-consecutive-sequence/description/
// https://leetcode.com/problems/surrounded-regions/description/
// https://leetcode.com/problems/number-of-islands/description/
// https://leetcode.com/problems/friend-circles/
// https://leetcode.com/problems/redundant-connection/
// https://leetcode.com/problems/minimize-malware-spread/description/
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// https://leetcode.com/problems/satisfiability-of-equality-equations/
// https://leetcode.com/problems/accounts-merge/

class DSU{
    vector<int> parent;
    vector<int> size;
    vector<int> rank;
    
    public:
    DSU(int n){
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        size.resize(n+1,1);
        rank.resize(n+1,0);
    }
    
    int findparent(int a){
        if(a==parent[a]) return a;
        return parent[a]=findparent(parent[a]);
    }
    
    void unionBySize(int u, int v){
        int a=findparent(u);
        int b=findparent(v);
        if(a==b) return;
        if(size[a]>=size[b]){
            size[a]+=size[b];
            parent[b]=a;
        }else{
            size[b]+=size[a];
            parent[a]=b;
        }
    }
    
    void unionByRank(int u, int v){
        int a=findparent(u);
        int b=findparent(v);
        if(a==b) return;
        if(rank[a]==rank[b]){
            rank[a]+=1;
            parent[b]=a;
        }else if(rank[a]>rank[b]){
            parent[b]=a;
        }else{
            parent[a]=b;
        }
    }
};
