class Solution {
private:
    unordered_map<string, string> short2long, long2short;
    const string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTUVWXYZ1234567890";
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = "https://www.tinyurl.com/";
        string code;
        do {
            code = "";
            for(int i=0;i<6;++i) {
                code += letters[rand()%letters.size()];
            }
        }while(short2long.find(shortUrl + code) != short2long.end());
        short2long[shortUrl + code] = longUrl;
        return long2short[longUrl] = shortUrl + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        cout << "got: " << shortUrl;
        return short2long[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));