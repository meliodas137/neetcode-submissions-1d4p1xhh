class MedianFinder {
public:
    MedianFinder() {
    }
    int s1 = 0;
    int s2 = 0;
    priority_queue<int, vector<int>, std::greater<int>> minHeap;
    priority_queue<int> maxHeap;

    void addNum(int num) {
        if(s1 > s2) {
            if(num <= minHeap.top()) {
                maxHeap.push(num);
                s2++;
            }
            else {
                maxHeap.push(minHeap.top());
                s2++;
                minHeap.pop();
                minHeap.push(num);
            }
        }
        else if(s1 < s2) {
            if(num >= maxHeap.top()) {
                minHeap.push(num);
                s1++;
            }
            else {
                minHeap.push(maxHeap.top());
                s1++;
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
        else if(s1 == s2) {
            if(s1 == 0) {
                minHeap.push(num);
                s1++;
            }
            else if(num >= maxHeap.top()){
                minHeap.push(num);
                s1++;
            }
            else {
                maxHeap.push(num);
                s2++;
            }
        }
        return;
    }
    
    double findMedian() {
        if(s1 == s2) return (maxHeap.top() + minHeap.top())/(2.0);
        if(s1 > s2) return minHeap.top();
        return maxHeap.top();
    }
};
