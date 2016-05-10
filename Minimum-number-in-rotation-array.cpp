
/************************************************************************
这道题的难点就是考虑一种极端的情况，给出的序列中出现较多的相等的数字时，类似
快排的方式不能起作用只能通过遍历的方式求出最小值。
*************************************************************************/
class Solution {
public:
    int minNumberInRotateArray(vector<int> totateArray) 
    {
        int length = totateArray.size();
        if(length == 0)
            return 0;
        int index1 = 0;
        int index2 = length - 1;
        int indexMid = index1;
        while(totateArray[index1] >= totateArray[index2])
        {
            if(index2 - index1 == 1)
            {
                indexMid = index2;
                break;
            }
            
            indexMid = (index1 + index2)/2;
            
            if(totateArray[index1] == totateArray[index2]
              && totateArray[indexMid] == totateArray[index1])
                return MinInOrder(totateArray,index1,index2);
            
            if(totateArray[indexMid] >= totateArray[index1])
                index1 = indexMid;
            else if(totateArray[indexMid] <= totateArray[index2])
                index2 = indexMid;
        }
        return totateArray[indexMid];
    }
private:
    int MinInOrder(vector<int> a,int index1,int index2)
    {
        int result = a[index1];
        for(int i = index1 + 1; i <= index2; ++i)
        {
            if(result > a[i])
                result = a[i];
        }
        return result;
    }
};
