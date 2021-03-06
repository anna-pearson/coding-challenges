using namespace std;

#include <algorithm>
#include <vector>

class Solution {
public:

    int CalcVolume(const int& height, const int& width) {
        return height * width;
    }

    int maxArea(vector<int>& height) {

        int currWidth = height.size() - 1;
        int maxVol = CalcVolume(min(height.front(), height.back()), currWidth);

        int* leftPtr = &height.front();
        int* rightPtr = &height.back();

        while (leftPtr != rightPtr) {
            if (*leftPtr <= *rightPtr) {
                ++leftPtr;
            }
            else if (*leftPtr > * rightPtr) {
                --rightPtr;
            }
            --currWidth;
            int newVol = CalcVolume(min(*leftPtr, *rightPtr), currWidth);

            if (newVol > maxVol) {
                maxVol = newVol;
            }
        }
        return maxVol;
    }
};
