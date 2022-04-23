

// Question Link :: "https://leetcode.com/problems/encode-and-decode-tinyurl/"



// Solution //

class Solution {
public:
    
    int count;
    map<string, string> hashMap;
    
    Solution(){
        count = 1;
        hashMap.clear();
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        string encodedUrl = "https://tinyurl.com/" + to_string(count++);
        hashMap[encodedUrl] = longUrl;
        return encodedUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        return hashMap[shortUrl];
    }
};