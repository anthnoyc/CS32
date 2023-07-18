

void listAll(const MenuItem* m, string path) // two-parameter overload
{
    //You will write this code.
    if(m->menuItems() == nullptr){
        return;
    }
    if(path != ""){
        cout << path << endl;
    }
    
    for(int j = 0; j < m->menuItems()->size(); j++){
        if(path == ""){
            listAll(m->menuItems()->at(j), m->menuItems()->at(j)->name());
        } else {
            listAll(m->menuItems()->at(j), path + "/" + m->menuItems()->at(j)->name());
        }
    }
}
