
#include <os.h>

void  OSTimeDlyHMSM_User (CPU_INT16U   hours,
                          CPU_INT16U   minutes,
                          CPU_INT16U   seconds,
                          CPU_INT32U   milli,
                          OS_OPT       opt,
                          OS_ERR      *p_err) 
{
    CPU_BOOLEAN isPrivileged = CPU_IsPrivileged();

    if(!isPrivileged) {
        SVCall(CPU_SVCALL_RAISE_PRIVILEGE);
    }

    OSTimeDlyHMSM(hours, minutes, seconds, milli, opt, p_err);
    
    if(!isPrivileged) {
        SVCall(CPU_SVCALL_LOWER_PRIVILEGE);
    }
}

