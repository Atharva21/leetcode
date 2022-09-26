class Solution {
private:
    int parent[26];
    int getParent(int child) {
        if(parent[child] == child)
            return child;
        return parent[child] = getParent(parent[child]);
    }
public:
    bool equationsPossible(vector<string>& equations) {
        // DSU problem. have a disjoint set of all equalities, if one unequal pair is found, 
        // and their parent is same we return false.
        
        for(int i=0;i<26;++i)
            parent[i] = i;
        
        for(auto& equation: equations) {
            if(equation[1] == '!') {
                continue;
            }
            parent[getParent(equation[3]-'a')] = getParent(equation[0]-'a');
        }
        
        for(auto& equation: equations) {
            if(equation[1] == '!') {
                if(getParent(parent[equation[0]-'a']) == getParent(parent[equation[3]-'a']))
                    return false;
            }
        }
        
        return true;
    }
};