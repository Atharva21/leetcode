class Solution {
private:
    // int strcmp(const string& a, const string& b) {
    //     const int m = a.size();
    //     const int n = b.size();
    //     int i=0, j=0;
    //     while(i<m&&j<n) {
    //         if(a[i] == b[j]) {++i;++j;continue;}
    //         if(a[i] > b[j]) return 1;
    //         else return -1;
    //     }
    //     if(i == m && j == n) return 0;
    //     if(i == m) return -1;
    //     return 1;
    // }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        string search = "";
        // for(auto& w: products) cout << w << " ";
        // cout << endl << endl;
        int lo=0, hi=products.size()-1;
        for(auto& c: searchWord) {
            string ubs = search + (char)(c+1);
            search += c;
            vector<string> temp;
            // cout << "for searchstring " << search << ": ";
            lo = lower_bound(products.begin()+lo, products.end()-(products.size()-hi-1), search) - products.begin();
            hi = lower_bound(products.begin()+lo, products.end()-(products.size()-hi-1), ubs) -1 - products.begin();
            // if(lo > hi) break;
            // cout << "lo: " << lo << " and hi: " << hi << endl;
            int k=0;
            for(int i=lo;i<=hi;++i) {temp.push_back(products[i]);++k;if(k == 3) break;}
                
            ans.push_back(temp);
        }
        return ans;
    }
};