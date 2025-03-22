class Disjointset{
    vector<int>parent,rank;
public:
    Disjointset(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int findU(int x){
        if(x==parent[x])return x;
        return parent[x]=findU(parent[x]);
    }
    void Union(int u,int v){
        int ult_u=findU(u);
        int ult_v=findU(v);
        if(ult_u==ult_v)return;
        if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }
        else if(rank[ult_u]>rank[ult_v])parent[ult_v]=ult_u;
        else{
            parent[ult_u]=ult_v;
            rank[ult_v]++;
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        Disjointset ds(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            ds.Union(u,v);
        }
        map<int,set<int>>component;
        map<int,int>edge;
        for(int i=0;i<n;i++){
            int ultp=ds.findU(i);
            component[ultp].insert(i);
        }
        for (auto& ed : edges) {
            int root = ds.findU(ed[0]);
            edge[root]++;
        }
        int c=0;
        for(auto el:component){
            int nodes=el.second.size(); 
            int expected=((nodes)*(nodes-1))/2;
            int actual=edge[el.first];
            if(expected==actual)c++;
        }
        return c;
    }
};
