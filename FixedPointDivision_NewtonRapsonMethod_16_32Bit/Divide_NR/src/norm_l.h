/*
 * norm_l.h
 *
 *  Created on: Jul 18, 2019
 *      Author: uids8702
 */

#ifndef NORM_L_H_
#define NORM_L_H_

int32_t norm_l (int32_t L_var1)
{
    int32_t var_out;

    if (L_var1 == 0)
    {
        var_out = 0;
    }
    else
    {
        if (L_var1 == (int32_t) 0xffffffffL)
        {
            var_out = 31;
        }
        else
        {
            if (L_var1 < 0)
            {
                L_var1 = ~L_var1;
            }
            for (var_out = 0; L_var1 < (int32_t) 0x40000000L; var_out++)
            {
                L_var1 <<= 1;
            }
        }
    }

    return (var_out);
}


#endif /* NORM_L_H_ */
