class Solution {
private:
    vector<int> colors;
    vector<vector<int>> graph;
    int n;
    
    bool validColor(int i=0, int color=0) {
        if(colors[i] != -1) return false;
        int oppColor = color == 1 ? 0 : 1;
        colors[i] = color;
        for(auto& nbr: graph[i]) {
            if(colors[nbr] != -1) {
                if(colors[nbr] == color) return false;
                continue;
            }
            if(!validColor(nbr, oppColor)) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        this->graph = graph;
        n = graph.size();
        colors.resize(n, -1);
        for(int i=0;i<n;++i) {
            if(colors[i] != -1) continue;
            if(!validColor(i)) return false;
        }
        // cout << "s";
        for(int i=0;i<n;++i) {
            int col = colors[i];
            // cout << "for i: " << i << " and col: " << col << " # ";
            for(auto& nbr: graph[i]) {
                // cout << nbr << "'s color is: " << colors[nbr] << " ";
                if(colors[nbr] == -1 || colors[nbr] == col) return false;
            }
            // cout << endl;
        }
        return true;
    }
};