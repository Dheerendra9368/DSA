class MedianFinder {
public:
priority_queue<int> left;
priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()>0 && left.top()<num){
            right.push(num);
            if(right.size()>left.size()+1){
                left.push(right.top());
                right.pop();
            }
        }
        else{
             left.push(num);
            if(left.size()>right.size()+1){
                right.push(left.top());
                left.pop();
            }
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            double a=left.top();
            double b=right.top();
            return (a+b)/2;
        }
        else if(left.size()>right.size()){
            double b=left.top();
            return b;
        }
        else{
            double b=right.top();
            return b;
        }
    }
};
