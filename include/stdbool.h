#ifndef BOOL_H
#define BOOL_H

#if defined(__STDC__) && defined(__STDC_VERSION__)
    #if __STDC_VERSION__ <= 202311L // Check version, type `bool` was defined in C23 as a keyword.
        #define bool int
        #define true 1
        #define false 0
    #else
        ... // Nothing need to do.
    #endif // __STDC_VERSION__ <= 202311L
#endif // defined(__STDC__) && defined(__STDC_VERSION__)
#endif //BOOL_H
