class MedianFinder {
public:
    priority_queue<int> mnHeap;
    priority_queue<int, vector<int>, greater<int>> mxHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mnHeap.size() == 0 && mxHeap.size() == 0) {
            mxHeap.push(num);
            return;
        }
        if(mxHeap.top() >= num) {
            mnHeap.push(num);
        } else mxHeap.push(num);
        if(abs((int)mnHeap.size() - (int)mxHeap.size()) > 1) {
            if(mnHeap.size() > mxHeap.size()) {
                int n = mnHeap.top();
                mnHeap.pop();
                mxHeap.push(n);
            } else {
                int n = mxHeap.top();
                mxHeap.pop();
                mnHeap.push(n);
            }
        }
    }
    
    double findMedian() {
        int sz = mnHeap.size() + mxHeap.size();
        if (mnHeap.size() > mxHeap.size()) {
            return mnHeap.top();
        }

        if (mxHeap.size() > mnHeap.size()) {
            return mxHeap.top();
        }
        return (mnHeap.top() + mxHeap.top()) / double(2.0);
    }
};
