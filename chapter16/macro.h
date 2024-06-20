#ifndef MYMACRO
    #define MYMACRO
    #define HARMONIC_MEAN(X, Y) (1.0/((1.0/(X) + 1.0/(Y))/2))
    #define DIG_IN_RAD(X) ((X) * 4.0 * atan(1) / 180.0)
    #define SKIP while(getchar() != '\n') continue;
#endif