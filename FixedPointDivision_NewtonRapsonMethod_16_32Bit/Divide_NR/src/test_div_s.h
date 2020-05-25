/*
 * test_div_s.h
 *
 *  Created on: Jul 18, 2019
 *      Author: uids8702
 */

#ifndef TEST_DIV_S_H_
#define TEST_DIV_S_H_


void test_div_s(float32_t *amax_diff)
{

	/*Testing the 16-bit division code*/
	int32_t number_of_tests = 1000;
	srand(2345);

	printf("value of srand(2345) = %d\n",rand());
	float32_t max_diff = 0.0;

	for(int i=999; i < number_of_tests; i++)
	{
		int16_t num, denom;
		int32_t num_sh, denom_sh;
		float32_t result_f, result_fxd;
		int16_t result_16;
		float32_t diff;


		num   = (rand() & 0x00003fff);// 14 bit set to 1
		denom = (rand() & 0x00007fff);// 15 bit set to 1

		num = 404;
		denom = 340;

		num_sh   = norm_l(num) - 16;
		denom_sh = norm_l(denom) - 16;

		printf("i = %d, num =%x, denom = %x num_sh=%d denom_sh=%d\n", i, num, denom,num_sh, denom_sh);
		printf("i = %d, dec_num =%d, dec_denom = %d num_sh=%d denom_sh=%d\n", i, num, denom,num_sh, denom_sh);

		result_f   = (float32_t) num/(float32_t) denom;
		printf("value of result_f = %f\n",result_f);
		printf("value of result_f in float = %f\n",result_f);

		if((num != 0) && (denom !=0))
		{
			denom <<= denom_sh;

			if(num_sh > 0) {
				num <<= (num_sh - 1);
			}

			result_16 = div_s(num, denom);
			printf("value of result_16 in fixed = %d\n",result_16);


			if(num_sh > 0)
			{
				result_fxd = (float32_t)result_16*(float32_t)(1<<denom_sh)/((float32_t)(1<<15)* (float32_t)(1<<(num_sh -1)));
				printf("if- value of result_fxd = %f\n",result_fxd);
			}
			else
			{
				result_fxd = (float32_t)result_16*(float32_t)(1<<denom_sh)/(float32_t)(1<<15);
				printf("else - value of result_fxd = %f\n",result_fxd);
			}

			diff = result_fxd - result_f;

			diff = (diff > 0.0)? diff: (0.0- diff);

			if(max_diff < diff)
			{
				max_diff = diff;
			}


			if(diff > 0.001)
			{

				result_16 = div_s(num, denom);


				if(num_sh > 0)
				{
					result_fxd = (float32_t)result_16*(float32_t)(1<<denom_sh)/((float32_t)(1<<15)* (float32_t)(1<<(num_sh -1)));
				}
				else
				{
					result_fxd = (float32_t)result_16*(float32_t)(1<<denom_sh)/(float32_t)(1<<15);
				}



			}

			printf("i = %d, num =%x, denom = %x diff=%f max_diff=%f\n", i, num, denom,diff, max_diff);

		}//if((num != 0) && (denom !=0))
	}

	*amax_diff = max_diff;
}

#endif /* TEST_DIV_S_H_ */
