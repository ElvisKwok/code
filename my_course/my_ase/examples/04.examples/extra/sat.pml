/* Copyright 2007 by Moti Ben-Ari under the GNU GPL; see readme.txt */

active proctype P() {
        bool p, q, r;
        bool result;

        if :: p = true :: p = false fi;
        if :: q = true :: q = false fi;
        if :: r = true :: r = false fi;

        result = 
                (p || r)  && (!p || !r) &&
                (p || !q) && (!p || q)  &&
                (q || !r) && (!q || !r);

        printf("p = %d, q = %d, r =%d\n", p, q, r);
        printf("Result = %d\n", result);
        assert(!result)
}
