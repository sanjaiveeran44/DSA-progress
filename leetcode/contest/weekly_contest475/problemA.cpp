class Solution {
public:
    int minimumDistance(vector<int>& arr) {
        unordered_map<int,vector<int>>indexMap;
        for(int i = 0;i < arr.size();i ++){
            indexMap[arr[i]].emplace_back(i);
        }
        int result = INT_MAX;
        for(auto &entry : indexMap){
            const auto &positions = entry.second;
            if(positions.size() < 3) continue;

            int n = positions.size();
            for(int a = 0;a < n;a ++){
                for(int b = a+1;b < n;b++){
                    for(int c = b+1;c < n;c++){
                        int totalDist = abs(positions[a]-positions[b])+abs(positions[b]-positions[c])+abs(positions[c]-positions[a]);
                        result = min(result, totalDist);
                    }
                }
            }
        }
        return (result == INT_MAX) ? -1:result;
    }
};