#include "gain_effect_control.h"
#include "gain_effect_process.h"

uint32_t gain_effect_update_coeffs(
    void const* params,
    void*       coeffs)
{
    *(float*)coeffs = pow((float)10, (float)ONE_TWENTYTH * *(float*)params);

    return 1;
}