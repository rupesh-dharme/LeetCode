class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> records;
        for (auto &op : ops) {
            int n = op.size();
            if (isdigit(op[n-1])) {
                records.push_back(stoi(op));
            }
            else if (op == "C") records.pop_back();
            else if (op == "D") records.push_back(records.back() * 2);
            else records.push_back(records[records.size()-1] + records[records.size()-2]);
        }
        return accumulate(records.begin(), records.end(), 0);
    }
};