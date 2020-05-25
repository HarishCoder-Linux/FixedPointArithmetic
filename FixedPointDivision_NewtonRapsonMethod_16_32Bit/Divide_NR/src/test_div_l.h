/*
 * test_function1.h
 *
 *  Created on: Jul 18, 2019
 *      Author: uids8702
 */

#ifndef TEST_DIV_L_H_
#define TEST_DIV_L_H_

void test_div_l(float32_t *amax_diff)
{
	/*Testing the 16-bit division code*/
	int32_t number_of_tests = 1<<25;
	srand(2345);

	float32_t max_diff = 0.0;

	for(int i=((1<<25)-1); i < number_of_tests; i++)
	{
		int32_t num, denom;
		int32_t num_sh, denom_sh;
		float32_t result_f, result_fxd;
		int32_t result_32;
		float32_t diff;


		num     = (rand() & 0x3fff)*(rand() & 0x7fff);
		denom   = (rand() & 0x7fff)*(rand() & 0x7fff);

		num_sh   = norm_l(num);
		denom_sh = norm_l(denom);

		printf("i = %d, num =%x, denom = %x num_sh=%d denom_sh=%d\n", i, num, denom,num_sh, denom_sh);

		result_f   = (float32_t) num/(float32_t) denom;

		if((num != 0) && (denom !=0))
		{
			denom <<= denom_sh;

			if(num_sh > 0) {
				num <<= (num_sh - 1);
			}

			result_32 = div_l(num, denom);


			if(num_sh > 0)
			{
				result_fxd = (float32_t)result_32*(float32_t)(1<<denom_sh)/(((float32_t)(1<<30) * 2.0)*  (float32_t)(1<<(num_sh -1)));
			}
			else
			{
				result_fxd = (float32_t)result_32*(float32_t)(1<<denom_sh)/((float32_t)(1<<30) * 2.0);
			}

			diff = result_fxd - result_f;

			diff = (diff > 0.0)? diff: (0.0- diff);

			if(max_diff < diff)
			{
				max_diff = diff;
			}


			if(diff > 0.0001)
			{

				result_32 = div_l(num, denom);


				if(num_sh > 0)
				{
					result_fxd = (float32_t)result_32*(float32_t)(1<<denom_sh)/(((float32_t)(1<<30) * 2.0)*  (float32_t)(1<<(num_sh -1)));
				}
				else
				{
					result_fxd = (float32_t)result_32*(float32_t)(1<<denom_sh)/((float32_t)(1<<30) * 2.0);
				}



			}

			printf("i = %d, num =%x, denom = %x diff=%f max_diff=%f\n", i, num, denom,diff, max_diff);

		}//if((num != 0) && (denom !=0))
	}

	*amax_diff = max_diff;
}

#endif /* TEST_DIV_L_H_ */
