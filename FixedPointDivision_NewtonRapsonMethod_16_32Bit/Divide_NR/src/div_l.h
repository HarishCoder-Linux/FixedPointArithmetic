/*
 * div_l.h
 *
 *  Created on: Jul 18, 2019
 *      Author: uids8702
 */

#ifndef DIV_L_H_
#define DIV_L_H_

int32_t div_l (int32_t var1, int32_t var2)
{
    int32_t var_out = 0;
    int32_t iteration;
    uint32_t L_num;
    uint32_t L_denom;

    if ((var1 > var2) || (var1 < 0) || (var2 < 0))
    {
        printf ("Division Error var1=%d  var2=%d\n", var1, var2);
        abort(); /* exit (0); */
    }
    if (var2 == 0)
    {
        printf ("Division by 0, Fatal error \n");
        abort(); /* exit (0); */
    }
    if (var1 == 0)
    {
        var_out = 0;
    }
    else
    {
        if (var1 == var2)
        {
            var_out = 0x7fffffff; //1
        }
        else
        {
            L_num   =  (uint32_t)var1;
            L_denom =  (uint32_t)var2;

            for (iteration = 0; iteration < 31; iteration++)
            {
                var_out <<= 1;
                L_num <<= 1;

                if (L_num >= L_denom)
                {
                    L_num =  L_num-  L_denom;
                    var_out += 1;
                }
            }
        }
    }
    return (var_out);
}

#endif /* DIV_L_H_ */
