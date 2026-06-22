class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        
        vector<int> freq_t(256, 0);
        for (char c : t) {
            freq_t[c]++;
        }

        int required = 0;
        for (int i = 0; i < 256; i++) {
            if (freq_t[i] > 0) {
                required++;
            }
        }

        vector<int> window_freq(256, 0);
        int formed = 0;

        int left = 0;
        int min_len = INT_MAX;
        int min_start = 0;

        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            
        
            window_freq[c]++;
            
        
            if (freq_t[c] > 0 && window_freq[c] == freq_t[c]) {
                formed++;
            }

            
            while (formed == required) {
            
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }

            
                char left_char = s[left];
                window_freq[left_char]--;
                
            
                if (freq_t[left_char] > 0 && window_freq[left_char] < freq_t[left_char]) {
                    formed--;
                }
                
                left++;
            }
        }

        return (min_len == INT_MAX) ? "" : s.substr(min_start, min_len);
    }
};