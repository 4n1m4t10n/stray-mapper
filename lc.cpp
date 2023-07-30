#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Jump(vector<int>& nums, int pos, bool& goal) {
        int range = nums[pos];

        if ((range + pos) >= (nums.size() - 1)){
            goal = true;
            return;
        }
        
        while (range != 0){
            Jump(nums, pos + range, goal);

            if (goal)
                return;
            else
                range--;
        }
        
    }

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    bool goal = false;
        Jump(nums, 0, goal);
        return goal;
    
}