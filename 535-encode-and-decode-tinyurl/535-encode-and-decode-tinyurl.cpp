class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        for (auto& ch : longUrl) {
            if (ch != 255) ch++;
        }
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        for (auto &ch : shortUrl) {
            if (ch != 255) ch--;
        }
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));