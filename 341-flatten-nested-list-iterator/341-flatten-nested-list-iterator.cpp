/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    int n, i;
    vector<NestedInteger> list;
    unordered_map<int, NestedIterator*> iterators;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        n = nestedList.size();
        i = 0;
        list = nestedList;
        for(int j=0;j<n;++j) {
            if(list[j].isInteger()) {
                continue;
            }
            // cout << j << " " << endl;
            iterators[j] = new NestedIterator(list[j].getList());
        }
    }
    
    int next() {
        if(i >= n) return -1;
        if(list[i].isInteger()) {
            return list[i++].getInteger();
        }
        if(iterators[i]->hasNext()) {
            return iterators[i]->next();
        } else {
            ++i;
            return next();
        }
    }
    
    bool hasNext() {
        if(i >= n) return false;
        if(list[i].isInteger()) return true;
        for(int j=i;j<n;++j) {
            if(list[j].isInteger()) return true;
            if(iterators[j]->hasNext()) return true;
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */