
    void removeBad(vector<Restaurant*>& v)
    {
        vector<Restaurant*>::iterator itr = v.begin();
        while(itr != v.end()){
            if((*itr)->stars() <= 2){
                vector<Restaurant*>::iterator deleter = itr;
                delete *deleter;
                itr = v.erase(itr);
            } else {
                itr++;
            }
        }
        
        
    }
