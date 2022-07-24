
/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */

template<typename T>
void print_queue(T q) {
    while(!q.empty()) {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';
}

int cookies(int k, vector<int> A) {
    int iterations = 0;
    std::priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int x : A)
        pq.push(x);
        
    //print_queue(pq);
    
    while(pq.top() < k && pq.size() > 1)
    {
        int min_1 = pq.top();
        pq.pop();
        int min_2 = pq.top();
        pq.pop();
        int new_val = min_1 + (2*min_2);
        pq.push(new_val);
        iterations++;
        //print_queue(pq);
    }
    if(pq.top() >= k)
        return iterations;
    else
        return -1;
}
