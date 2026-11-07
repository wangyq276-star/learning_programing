
long test(long x, long y, long z){
    long val = x + y + z;
    if (x < -3){
        if (y < z){
            val = x * y;
        }else{
            val = z * y;
        }
    }else if (x > 2){
        val = x * z;
    }
    return val;
}