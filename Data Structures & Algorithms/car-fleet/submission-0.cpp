#include <algorithm>
#include <vector>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<std::pair<int, int>> cars;
        cars.reserve(position.size());
        
        for (int i = 0; i < position.size(); ++i) {
            cars.emplace_back(position[i], speed[i]);
        }
        
        // Sort by position (ascending)
        std::sort(cars.begin(), cars.end(), 
                  [](const auto& a, const auto& b) { return a.first < b.first; });
        
        int fleets = 0;
        double last_time = -1.0; // - to start
        
        for (int i = (int)cars.size() - 1; i >= 0; --i) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            if (time > last_time) {
                fleets++;
                last_time = time;
            }
        }
        return fleets;
    }
};