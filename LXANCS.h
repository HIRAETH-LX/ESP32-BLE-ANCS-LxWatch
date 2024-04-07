#ifndef LXANCS_H
#define LXANCS_H

//#include "messagePage.h"

extern "C"{
    #include "trans_pwm.h"
    #include "messagePage.h"
}


extern "C" void lx_ancs_begin();
extern "C" void lx_ancs_end();
#endif
