#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

  nums1.resize(m);
        nums2.resize(n);

        if (nums1.empty())
                nums1 = nums2;
        else{
            for (int i = nums1.size() - 1; i >= 0; i--){
                if (!nums2.empty() && nums1[i] <= nums2[nums2.size() - 1]){
                    nums1.insert(nums1.begin() + i + 1, nums2[nums2.size() - 1]);
                    nums2.erase(nums2.begin()+nums2.size() - 1);
                    i++;
            }

        }
        }

        cout << "[";
        for (int i = 0; i < nums1.size(); i++){
            cout << nums1[i] << ", ";
        }
        cout << "]" << endl;
}