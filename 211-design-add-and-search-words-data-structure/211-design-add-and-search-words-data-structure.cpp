class Node {
public:
    bool isLeaf;
    Node* children[26];
    Node() {
        isLeaf = false;
        for(int i=0;i<26;++i) children[i] = NULL;
    }
};

class WordDictionary {
private:
    Node* root = NULL;
    
    bool dfs(Node* node, string word, int cur) {
        if(!node || cur == word.size()) return false;
        if(cur == word.size()-1) {
            if(word[cur] == '.') {
                for(int i=0;i<26;++i) {
                    if((node->children[i]) && (node->children[i]->isLeaf)) return true;
                }
                return false;
            } else {
                int idx = word[cur]-'a';
                return ((node->children[idx]) && (node->children[idx]->isLeaf));
            }
        }
        if(word[cur] == '.') {
            for(int i=0;i<26;++i) {
                if(dfs(node->children[i], word, cur+1)) return true;
            }
            return false;
        } else {
            int idx = word[cur]-'a';
            return dfs((node->children[idx]), word, cur+1);
        }
    }
    
    // void debugDfs(Node* node) {
    //     if(!node) return;
    //     bool visited = false;
    //     for(int i=0;i<26;++i) {
    //         if(!(node->children[i])) continue;
    //         if(!visited)
    //             cout << endl;
    //         visited = true;
    //         char c = 'a' + i;
    //         if(node->children[i]->isLeaf) {
    //             cout << " " << c << "L";
    //         } else {
    //             cout << " " << c;
    //         }
    //         debugDfs(node->children[i]);
    //     }
    // }
    
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        auto temp = root;
        for(auto& c: word) {
            if(!(temp->children[c-'a'])) {
                temp = temp->children[c-'a'] = new Node();
            } else {
                temp = temp->children[c-'a'];
            }
        }
        temp->isLeaf = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */