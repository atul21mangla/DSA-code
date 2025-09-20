struct packet{
    int source,destination,timestamp;

    packet(int s , int d , int t){
        this->source = s;
        this->destination = d;
        this->timestamp = t;
    }

    string getUniqueId(){
        return to_string(source) + '_' + 
        to_string(destination)+'_'+to_string(timestamp);
    }
};


class Router {
public:
    int size;
    queue<packet>q;
    unordered_set<string>st;
    unordered_map<int,deque<int>>mpp;

    Router(int memoryLimit) {
        this->size = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        packet p(source,destination,timestamp);
        string uniqueId = p.getUniqueId();
        if(st.count(uniqueId))return false;

        st.insert(uniqueId);
        mpp[destination].push_back(timestamp);
        q.push(p);

        if(q.size()>size){
            packet temp = q.front();
            q.pop();
            st.erase(temp.getUniqueId());
            mpp[temp.destination].pop_front();
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.size()==0)return {};

        packet temp = q.front();
        q.pop();
        st.erase(temp.getUniqueId());
        mpp[temp.destination].pop_front();
        return {temp.source , temp.destination , temp.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {

        int startIdx = lower_bound(mpp[destination].begin(),
        mpp[destination].end(),startTime) - mpp[destination].begin();

        int endIdx = upper_bound(mpp[destination].begin(),
        mpp[destination].end(),endTime) - mpp[destination].begin();
        
        return endIdx-startIdx;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */