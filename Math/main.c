#include "libMath.h"
#include "vector.h"

int main(int argc, char* argv[])
{
    vector vekt;
    vector_init(&vekt, 1);

    push_back(&vekt, (void *) 2147483648);
    for (size_t i = 0; i < vekt.size; ++i)
        printf("%li\n", (int64_t) vekt.value[i]);

    return 0;
}

