
void removeEven(list<int>& li)
{
    list<int>::iterator itr = li.begin();
    if(li.empty()){
        return;
    }
    while(itr != li.end()){
        if(*itr % 2 == 0){
            itr = li.erase(itr);
            itr--;
        }
        itr++;
    }
}
