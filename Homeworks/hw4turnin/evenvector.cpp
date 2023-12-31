
    void test()
    {
        int a[8] = { 1, 7, 6, 5, 8, 4, 3, 2 };
        vector<int> x(a, a+8);  // construct x from the array
        assert(x.size() == 8 && x.front() == 1 && x.back() == 2);
        removeEven(x);
        assert(x.size() == 4);
        sort(x.begin(), x.end());
        int expect[4] = { 1, 3, 5, 7 };
        for (int k = 0; k < 4; k++)
            assert(x[k] == expect[k]);
    }

