//
//  main.cpp
//  cs32Proj2
//
//  Created by Anthony Chen on 4/20/23.
//

#include <iostream>
#include <string>
#include <cassert>
#include "Sequence.h"

int main() {
    
//    Sequence ss;
//        assert(ss.size() == 0);
//        assert(ss.empty() == true);
//        assert(ss.erase(0) == false);
//        ItemType value;
//        assert(ss.get(0, value) == false);
//        assert(ss.remove("aa") == 0);
//        assert(ss.set(0, "aa") == false);
//        assert(ss.insert(0, "aa") == 0); // a
//        assert(ss.insert(0, "cc") == 0); // b a
//        assert(ss.size() == 2);
//        assert(ss.empty() == false);
//        assert(ss.insert("dd") == 2); // b a c
//
//        assert(ss.insert("aa") == 0); // a b a c
//    //ss.dump();
//        assert(ss.erase(0) == true); // b a c
//        ItemType x;
//        assert(ss.get(0, x) && x == "cc");
//    //    ss.dump();
//        assert(ss.remove("aa") == 1); // b c
//    //    ss.dump();
//        assert(ss.set(0, "aa") == true); // a c
//        //ss.dump();
//        assert(ss.find("aa") == 0);
//        assert(ss.find("cc") == -1);

    
        Sequence ee;
    //    ee.dump();
    //    ss.dump();
    //    ee.swap(ss);
    //    ee.dump();
    //    ss.dump();
//    //    ee.swap(ss);
//        assert(ee.insert(0, "aa") == 0); // a
//        assert(ee.insert(1, "cc") == 1); // a b
//        assert(ee.insert(2, "dd") == 2); // a b c
//        ee.dump();
//        ee.swap(ss);
//        // ee: a c
//        // ss: a b c
//        ee.dump();
//        ss.dump();
//        assert(ee.size() == 2);
//        assert(ss.size() == 3);
//
//        assert(subsequence(ss, ee) == -1);
//        assert(ss.remove("cc") == 1); // ss: a c
//        ss.dump(); // a c
//    //    ee.dump(); // a c
//        assert(subsequence(ss, ee) == 0);
//        assert(ss.insert(2, "cc") == 2);
//        assert(ee.insert(1, "cc") == 1);
//        assert(ee.insert(2, "dd") == 2);
//    //    ss.dump();
//    //    ee.dump();
//        assert(subsequence(ss, ee) == -1);

        Sequence a;
        Sequence b;
        assert(subsequence(a, b) == -1);
        assert(a.insert(0, "aa") == 0);
        assert(subsequence(a, b) == -1);
        assert(subsequence(b, a) == -1);
        assert(b.insert(0, "aa") == 0);
    //    a.dump();
    //    b.dump();
        assert(subsequence(a, b) == 0);

        Sequence c;
        Sequence d;
        Sequence result;
        assert(c.insert(0, "aa") == 0);
        assert(c.insert(1, "cc") == 1);
        assert(c.insert(2, "dd") == 2);

        assert(d.insert(0, "1") == 0);
        assert(d.insert(1, "2") == 1);
        assert(d.insert(2, "3") == 2);
        c.dump();
        d.dump();
        concatReverse(c, d, result);
        result.dump();

        Sequence e = c;
        c.dump();
        e.dump();
        concatReverse(c, e, result);
        result.dump();

        Sequence f = c;
        c.dump();
        f.dump();
        concatReverse(c, d, f);
        f.dump();



    Sequence s;
        assert(s.size() == 0);
        assert(s.empty() == true);
        assert(s.erase(0) == false);
        assert(s.insert(0, "a") == 0);
        assert(s.size() == 1);
        assert(s.empty() == false);
        assert(s.erase(0) == true);
        assert(s.size() == 0);
        assert(s.empty() == true);
        assert(s.insert("a") == 0);
        assert(s.insert("b") == 1);
        assert(s.insert(-1, "c") == -1);
        assert(s.insert(3, "c") == -1);
        assert(s.size() == 2);
        assert(s.erase(1) == true);
        assert(s.size() == 1);
        assert(s.insert(1, "a") == true);
        assert(s.remove("a") == 2);
        assert(s.size() == 0);
        assert(s.empty() == true);
        assert(s.insert("Hello") == 0);
        assert(s.insert("Hello") == 0);
        std::string copier = "Bye";
        s.set(0, copier);
        assert(copier == "Bye");
        std::string copier_two = "Hello";
        s.get(0, copier_two);
        assert(copier_two == "Bye");
        s.get(1, copier_two);
        assert(copier_two == "Hello");
        assert(s.find("a") == -1);
        assert(s.find("Bye") == 0);
        assert(s.find("Hello") == 1);
        Sequence t;
        assert(t.insert("a") == 0);
        assert(t.insert("b") == 1);
        assert(t.insert("c") == 2);
        assert(t.size() == 3);
        t.swap(s);
        assert(t.find("a") == -1);
        assert(t.find("b") == -1);
        assert(t.find("c") == -1);
        assert(t.find("Bye") == 0);
        assert(t.find("Hello") == 1);
        assert(t.size() == 2);
        assert(s.find("Bye") == -1);
        assert(s.find("Hello") == -1);
        assert(s.find("a") == 0);
        assert(s.find("b") == 1);
        assert(s.find("c") == 2);
        assert(s.size() == 3);
        Sequence z(s);
        assert(z.find("a") == 0);
        assert(z.find("b") == 1);
        assert(z.find("c") == 2);
        assert(z.size() == 3);
        z = t;
        assert(z.find("a") == -1);
        assert(z.find("b") == -1);
        assert(z.find("c") == -1);
        assert(z.find("Bye") == 0);
        assert(z.find("Hello") == 1);
        assert(z.size() == 2);

    std::cerr << "Passed" << std::endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    // std::cout << "passed all tests" << std::endl;
}
