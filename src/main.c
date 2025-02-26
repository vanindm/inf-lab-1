#include <matrix.h>
#include <stdio.h>
#include <types.h>

int main(int argc, char **argv)
{
    error_t* error = NULL;
    void* c1 = read(getComplexFieldInfo(), &error);
    void* c2 = read(getComplexFieldInfo(), &error);
    if (error)
    {
       displayError(error);
       return 1;
    }
    write(getComplexFieldInfo(), c1, &error);
    write(getComplexFieldInfo(), c2, &error);
    return 0;
}
