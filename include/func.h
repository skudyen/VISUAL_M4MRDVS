#ifndef	FUNC_H
#define FUNC_H

#include "sdk_api.h"

/* 
        Device Setting Traget 
*/
LX_DEVICE_TYPE mydivice_M4 = LX_DEVICE_M4_MEGA;

/*
        State check before running program
*/
#define checkTC(state)                                                              \
{                                                                                   \
    LX_STATE val = state;                                                           \
    if(LX_SUCCESS!=val)                                                             \
    {                                                                               \
        if(val > 0)                                                                 \
            printf("[MSG][ ERROR ] : %s\n", DcGetErrorString(val));                 \
        else if(val == LX_E_RECONNECTING)                                           \
            printf("[MSG][ RECONECT ] : ...\n");                                    \
        else                                                                        \
        {                                                                           \
            printf("[MSG][ PRESS ANY KEY TO EXIT  ]\n", DcGetErrorString(val));     \
            getchar();                                                              \
            DcCloseDevice(handle_cam);                                             \
            return (-1);                                                              \
        }                                                                           \
    }                                                                               \
} 



#endif