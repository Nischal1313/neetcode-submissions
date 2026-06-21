#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, vector<int>> runs;
        unordered_map<char, vector<int>> gaps;
        unordered_map<char, int> last_run_start;

        int i = 0;
        while (i < s.size()) {
            char current_char = s[i];
            int run_len = 0;
            int run_start = i;
            while (i < s.size() && s[i] == current_char) {
                run_len++;
                i++;
            }
            if (!runs[current_char].empty()) {
                gaps[current_char].push_back(run_start - (last_run_start[current_char] + runs[current_char].back()));
            }
            last_run_start[current_char] = run_start;
            runs[current_char].push_back(run_len);
        }

        int result = 0;

        for (auto& [ch, ch_runs] : runs) {
            auto& ch_gaps = gaps[ch];

            // try every window of consecutive runs
            for (int left = 0; left < ch_runs.size(); left++) {
                int current_len = ch_runs[left];
                int remaining_k = k;
                int best = current_len;

                for (int right = left + 1; right < ch_runs.size(); right++) {
                    int gap = ch_gaps[right - 1];
                    if (remaining_k >= gap) {
                        remaining_k -= gap;
                        current_len += gap + ch_runs[right];
                    } else {
                        break;
                    }
                    best = max(best, current_len);
                }

                // use remaining k to extend
                best = min((int)s.size(), best + remaining_k);
                result = max(result, best);
            }
        }

        return result;
    }
};