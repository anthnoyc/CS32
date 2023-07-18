#include "newSequence.h"
   #include <iostream>
   #include <cassert>
   using namespace std;

   int main()
   {
       Sequence s;
       assert(s.empty());
       assert(s.find(42) == -1);
       assert(s.size() == 0);
       assert(s.insert(42) == 0);
       assert(s.insert(1) == 0);
       assert(s.insert(4) == 1);
       assert(s.insert(5) == 2);
       assert(s.insert(6) == 3);
       assert(s.insert(45) == 5);
       assert(s.size() == 6  &&  s.find(42) == 4);
       // 1,4,5,6,42

       Sequence d;
       assert(d.insert(5) == 0);
       assert(d.insert(5) == 0);
       assert(d.insert(5) == 0);
       assert(d.insert(5) == 0);
       assert(d.insert(5) == 0);
       assert(d.insert(5) == 0);
       assert(d.insert(5) == 0);
       assert(d.size() == 7);
       // 5 5 5 5 5 5 5

       s.swap(d);

       assert(d.size() == 6  &&  d.find(42) == 4);
       assert(s.size() == 7 && s.find(5) == 0);

       assert(d.insert(42) == 4);
       assert(d.find(42) == 4);
       assert(d.remove(42) == 2);
       assert(d.erase(0) == true);
       assert(d.size() == 4);



       Sequence w;
           assert(w.empty() == true);
           assert(w.size() == 0);
           assert(w.insert(0, 23) == 0);
           assert(w.insert(159, 23) == -1);
           assert(w.insert(22) == 0);
           assert(w.insert(24) == 2); // 22, 23, 24
           assert(w.size() == 3);
           assert(w.erase(2) == true); // 22, 23
           assert(w.insert(1, 25) == 1); // 22, 25, 23
           assert(w.insert(1, 25) == 1); // 22, 25, 25, 23
           assert(w.remove(25) == 2); // 22, 23
           unsigned long p = 0;
           if (w.get(0, p))
               assert(p == 22);
           assert(w.set(0, 23) == true);
           assert(w.set(2, 23) == false);
           assert(w.find(23) == 0);
           assert(w.find(22) == -1);


//       Sequence j;
//       assert(j.empty());
//       assert(j.find("laobing") == -1);
//       assert(j.insert("laobing") == 0);
//       assert(j.size() == 1  &&  j.find("laobing") == 0);
       
//       Sequence a(1000);   // a can hold at most 1000 items
//              Sequence b(5);      // b can hold at most 5 items
//              Sequence c;         // c can hold at most DEFAULT_MAX_ITEMS items
//              ItemType v = "asd";
//
//                // No failures inserting 5 items into b
//              for (int k = 0; k < 5; k++)
//                  assert(b.insert(v) != -1);
//
//                // Failure if we try to insert a sixth item into b
//              assert(b.insert(v) == -1);
//
//                // When two Sequences' contents are swapped, their capacities are
//                // swapped as well:
//              a.swap(b);
//              assert(a.insert(v) == -1  &&  b.insert(v) != -1);

       cout << "Passed all tests" << endl;
   }
