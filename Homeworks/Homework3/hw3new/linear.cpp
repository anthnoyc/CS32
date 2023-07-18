//#include <string>
//#include <cassert>
//#include <iostream>
//using namespace std;

//
//bool somePredicate(string s){
//    return s == "a";
//}

bool allTrue(const string a[], int n){
    // the smallest step
    bool first_pos = somePredicate(a[0]);
    if(n <= 0){
    // once we are no longer checking values and we dont return a false, then that means all are true
        return true;
    } else if (n == 1){
    // if the size is one, and the result is a false, then return false
        return first_pos;
    } else {
    // a + 1 means starting from the next value in the string. advancing the pointer forward one. therefore decrease the elements checking by 1
        return first_pos && allTrue(a + 1, n - 1);
    }
}


int countTrue(const string a[], int n){
    // base case = checking one value if it is true
    // n - 1 until the size is 1, then check for one element
    // how to make counter?
    // true = 1, so add up all trues?

    if(n <= 0){
        // if there are no strings to check (invalid n, return 0). treat it as zero elements
        return 0;
    }
    if(somePredicate(a[0])){
        return (countTrue(a + 1, n - 1) + somePredicate(a[0]));
    }
        // move the array pointer over one, then decrease number of things to be considered by 1
    return countTrue(a + 1, n - 1);
}


// I dont think this one works yet
int firstTrue(const string a[], int n){
    if(n <= 0){
        return -1;
    }
    if(somePredicate(a[0])){
        // once you get true, start going back
        return 0;
    }
    if(firstTrue(a, n) == -1){
        return -1;
    }
    return firstTrue(a + 1, n - 1);
}



int positionOfMax(const string a[], int n){
    // start on both sides, increment inwards based on which one is larger
    string left = a[0];
    string right = a[n - 1];
    if(n <= 0){
        return -1;
    }
    if(n == 1){
        return 0;
    }
    if(left >= right){
        return positionOfMax(a, n - 1);
    }
    return 1 + positionOfMax(a + 1, n - 1);
}


bool contains(const string a1[], int n1, const string a2[], int n2){
    if(n2 <= 0){
        // this is first because regardless
        return true;
    }
    if(n1 <= 0 || n1 < n2){
        return false;
    }
    if(a1[0] == a2[0])
        return contains(a1 + 1, n1 - 1, a2 + 1, n2 - 1);
    return contains(a1 + 1, n1 - 1, a2, n2);
}


//int main(){
//    string a[5];
//    a[0] = "a";
//    a[1] = "a";
//    a[2] = "a";
//    a[3] = "b";
//    a[4] = "a";
//
//    assert(allTrue(a, 5) == false);
//
//    assert(countTrue(a, 5) == 4);
//    assert(firstTrue(a, 5) == 0);
//    assert(positionOfMax(a, 5) == 3);
//
//    string aa[3];
//    aa[0] = "a";
//    aa[1] = "b";
//    aa[2] = "a";
////assert(contains(a, 5, b, 3) == true);
//
//    string b[3];
//        string c[3];
//        b[0] = "a";
//        b[1] = "b";
//        b[2] = "c"; // b: a b c
//        c[0] = "a";
//        c[1] = "b";
//        c[2] = "c"; // c: a b c
//        assert(contains(b, 3, c, 3) == true);
//        c[2] = "b"; // c: a b b
//        assert(contains(b, 3, c, 3) == false);
//        string d[4];
//        d[0] = "a";
//        d[1] = "c";
//        d[2] = "b";
//        d[2] = "c";
//        assert(contains(d, 3, c, 3) == false);
//        string e[0];
//        assert(contains(d, 4, e, 0) == true);
//        string g[0];
//        assert(contains(g, 0, e, 0) == true);
//
//
//    cout << "Passed" << endl;
//}
