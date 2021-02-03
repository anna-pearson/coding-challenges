using namespace std;

#include <string>
#include <vector>
#include <sstream>

class Solution {
public:

    void AddToProcessedVals(vector<int>& processedVals, int currValCounter, int currVal) {
        processedVals.push_back(currValCounter);
        processedVals.push_back(currVal);
    }

    void ProcessVals(vector<int>& vals, vector<int>& processedVals) {
        int currVal = vals[0];
        int currValCounter = 1;

        for (size_t i = 1; i < vals.size(); ++i) {
            // if we encounter a different value than the one we are currently counting, 
            // log the count amount and start counting again
            if (vals[i] != currVal) {
                AddToProcessedVals(processedVals, currValCounter, currVal);

                currVal = vals[i];
                currValCounter = 1;
            }
            else {
                ++currValCounter;
            }
        }
        AddToProcessedVals(processedVals, currValCounter, currVal);

        vals = processedVals;
    }

    string IntVecToString(vector<int>& vec) {
        std::stringstream ss;
        for (size_t i = 0; i < vec.size(); ++i)
        {
            ss << vec[i];
        }
        return ss.str();
    }


    string countAndSay(int n) {
        vector<int> vals{ 1 };
        vector<int> processedVals{};

        for (size_t i = 2; i <= n; ++i) {
            processedVals.clear();
            ProcessVals(vals, processedVals);
        }

        return IntVecToString(vals);
    }
};
