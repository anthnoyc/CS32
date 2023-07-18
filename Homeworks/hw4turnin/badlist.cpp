
    void removeBad(list<Restaurant*>& li)
    {
        list<Restaurant*>::iterator itr = li.begin();
        while(itr != li.end()){
            //parenthesis needed to reference the restaurant pointer
            if((*itr)->stars() <= 2){
                //need to destroy the restaurant pointer
                list<Restaurant*>::iterator deleter = itr;
                delete *deleter;
                itr = li.erase(itr);
            } else{
                itr++;
            }
        }
    }
