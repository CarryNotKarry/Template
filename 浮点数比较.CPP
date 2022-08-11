    double eps=1e-8;
    inline  int  sgn( double  x) {//和0比，大于返1等于返0小于返-1
        return  (x > eps) - (x < -eps);
    }
    //x = 0 写成 sgn(x) == 0
    //x < 0 写成 sgn(x) < 0
    //x > 0 写成 sgn(x) > 0
    //x > y 写成 sgn(x - y) > 0
    //x == y 写成 sgn(x - y) == 0
    //x >= y 写成 sgn(x - y) >= 0