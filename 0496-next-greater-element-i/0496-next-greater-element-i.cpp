class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> ans(num1.size(),-1);
        // vector<int> temp(num2.size(),-1);

        // stack<int> st;
        // for(int i =nums2.size()-1;i>=0;i--){
        //     while(!st.empty()&& st.top()>=nums2[i]){
        //         st.pop();

        //     }

        //     if(!st.empty()) st.top()= nums2[i];
        //     st.push(nums2[i]);
        // }

        vector<int> ans;
        for(int i =0; i<nums1.size();i++){
        int num =-1;
        int p =0;

            for(int j =0; j<nums2.size();j++){
                if( p==0){
                    if(nums1[i]==nums2[j]){
                        p++;
                    }
                    continue;
                }

                if(nums2[j]>nums1[i]){
                    num = nums2[j];
                    break;
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
};