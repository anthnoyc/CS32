//
//  main.cpp
//  tree
//
//  Created by Anthony Chen on 5/8/23.
//
//
//#include <iostream>
//#include <string>
//#include <cassert>
//using namespace std;

// in the n1 element array a1 in the same order (though not
        // necessarily consecutively).  The empty sequence appears in a
        // sequence of length n1 in 1 way, even if n1 is 0.
        // For example, if a1 is the 7 element array
        //    "john" "sonia" "elena" "ketanji" "sonia" "elena" "samuel"
        // then for this value of a2            the function must return
        //    "john" "ketanji" "elena"                     1
        //    "john" "elena" "samuel"                      2
        //    "ketanji" "john" "elena"                     0
        //    "sonia" "elena" "samuel"                     3
int countIncludes(const string a1[], int n1, const string a2[], int n2){
    if (n2 <= 0){
        return 1;
    }
    if (n1 == 0){
        return 0;
    }
    if(a1[0] == a2[0]){
        // adds the sum of the values ahead
        return countIncludes(a1 + 1, n1 - 1, a2, n2) + countIncludes(a1 + 1, n1 - 1, a2 + 1, n2 - 1);
    }
    return countIncludes(a1 + 1, n1 - 1, a2, n2);
}

        // Exchange two strings
void exchange(string& x, string& y){
    string t = x;
    x = y;
    y = t;
}

void separate(string a[], int n, string separator, int& firstNotLess, int& firstGreater){
    if (n < 0)
        n = 0;
      
    firstNotLess = 0;
    firstGreater = n;
    int firstUnknown = 0;
    while (firstUnknown < firstGreater){
        if (a[firstUnknown] > separator){
            firstGreater--;
            exchange(a[firstUnknown], a[firstGreater]);
        } else {
            if (a[firstUnknown] < separator){
                exchange(a[firstNotLess], a[firstUnknown]);
                firstNotLess++;
            }
            firstUnknown++;
        }
    }
}

        // Rearrange the elements of the array so that
        // a[0] <= a[1] <= a[2] <= ... <= a[n-2] <= a[n-1]
        // If n <= 1, do nothing.
void order(string a[], int n){
    int less, greater;
    if(n <= 0){
        return;
    }
    // binary order (break into two parts, where everything left is less, everything right is more)
    separate(a, n, a[n / 2], less, greater);
    // split into two parts
    // order the first part (everything less than)
    order(a, less);
    // order the second part (starting from after the greater)
    order(a + greater, n - greater);
    return;  // This is not always correct.
}

//int main(){
//    string b[3];
//        string e[3];
//        b[0] = "a";
//        b[1] = "b";
//        b[2] = "b"; // b: a b c
//        e[0] = "a";
//        e[1] = "b";
//        // c: a b c
//    assert(countIncludes(b, 3, e, 2) == 2);
//        string d[4];
//        d[0] = "a";
//        d[1] = "c";
//        d[2] = "b";
//        d[2] = "c";
//
//    string cc[12];
//    cc[0] = "q";
//    cc[1] = "w";
//    cc[2] = "e";
//    cc[3] = "r";
//    cc[4] = "t";
//    cc[5] = "y";
//    cc[6] = "s";
//    cc[7] = "d";
//    cc[8] = "b";
//    cc[9] = "a";
//    cc[10] = "c";
//    cc[11] = "e";
//
//    order(cc, 12);
//    for(int i = 0; i < 12; i++){
//        cout << cc[i] << " ";
//    }
//
//    cout << "Passed" << endl;
//
//}
