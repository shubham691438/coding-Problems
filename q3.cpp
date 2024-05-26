#include <iostream>
#include <vector>

using namespace std;


    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        
        vector<int> counts(100005, 0);
        int dominantCnt = 0;
        int dominantNum = -1;
        int involvedCnt = 0;
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) {
                ans += i;
                counts[nums1[i]]++;
                if (counts[nums1[i]] > dominantCnt) {
                    dominantCnt = counts[nums1[i]];
                    dominantNum = nums1[i];
                }
                involvedCnt++;
            }
        }
        if (dominantCnt > involvedCnt / 2) {
            for (int i = 0; i < n; ++i) {
                if (nums1[i] != nums2[i] && nums1[i] != dominantNum && nums2[i] != dominantNum) {
                    counts[nums1[i]]++;
                    involvedCnt++;
                    ans += i;
                    if (dominantCnt <= involvedCnt / 2) {
                        return ans;
                    }
                }
            }
            return -1;
        }
        else {
            return ans;
        }
    }


int main() {
    int n;
    cin >> n;
    vector<int> nums1(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums1[i];
    }

    int m; 
    cin >> m;
    vector<int> nums2(m);

    for (int i = 0; i < m; ++i) {
        cin >> nums2[i];
    }

    cout<<minimumTotalCost(nums1, nums2)<<endl;;
    

    return 0;
}
