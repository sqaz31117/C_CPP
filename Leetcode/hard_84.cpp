class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(0);
        heights.insert(heights.begin(), 0);
        heights.insert(heights.end(), 0);

        int n = heights.size();
        int area = 0;

        for (int i = 1; i < n; i++) {
            while (heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int w = i - st.top()-1;
                area = max(area, h*w);
            }
            st.push(i);
        }
        return area;
    }
};