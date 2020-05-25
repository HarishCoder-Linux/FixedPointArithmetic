#ifndef DIVIDE_H
#define DIVIDE_H

typedef float  float32_t;
typedef double float64_t;
typedef int   int32_t;
typedef long long int   int64_t;
typedef unsigned int   uint32_t;
typedef short int int16_t;

int16_t div_s (int16_t var1, int16_t var2);
int32_t div_l (int32_t var1, int32_t var2);
int32_t norm_l (int32_t L_var1);
void test_div_s(float32_t *amax_diff);

#endif //DIVIDE_H
