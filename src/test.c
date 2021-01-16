#include "vector.h"

#include <stdio.h>

int main()
{
    CREATE_STACK(VECTOR(int), vec);

    for (int i = 0; i < 255; ++i)
    {
        CALL(vec, push_back, i);
    }

    const int* val = CALL(vec, c_at, 22);
    printf("%d\n", *val);

    CALL(vec, clear);
    DELETE_STACK(vec);
    
    return 0;
}
