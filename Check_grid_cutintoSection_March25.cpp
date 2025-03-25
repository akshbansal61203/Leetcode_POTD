class Solution {
public:
    vector<vector<int>>merged(vector<vector<int>>&a){
        vector<vector<int>>mer;
        sort(begin(a),end(a));
        mer.push_back(a[0]);
        for(int i=1;i<a.size();i++){
            int l2=a[i][0];
            int r2=a[i][1];
            int r1=mer.back()[1];
            if(l2<min(r1,r2)){
                mer.back()[1]=max(mer.back()[1],r2);
            }
            else{
                mer.push_back({l2,r2});
            }
        }
        return mer;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>x;
        vector<vector<int>>y;
        for(auto el:rectangles){
            int x1=el[0];
            int y1=el[1];
            int x2=el[2];
            int y2=el[3];
            x.push_back({x1,x2});
            y.push_back({y1,y2});
        }
        vector<vector<int>>ans1=merged(x);
        vector<vector<int>>ans2=merged(y);
        if(ans1.size()>=3||ans2.size()>2)return true;
        return false;
    }
};
