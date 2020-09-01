#include "controllers.h"
#include "views.h"

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

uint32_t g_ui32SysClock;
uint32_t g_ui32Flags;

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif







int controller_sintetizacao(void)
{
    int t = 0;
    int injetora = 0;
    int ciclo[3];
    int ciclo_total[3];

    int temperatura_1[2] = {10, 80};
    int temperatura_2[2] = {15, 90};
    int temperatura_3[2] = {20, 100};

    int temperatura[3] = {temperatura_1, temperatura_2, temperatura_3};

    int injetora_1_1[2] = {25, 10};
    int injetora_1_2[2] = {30, 11};
    int injetora_1_3[2] = {35, 12};

    int injetora_1[3] = {injetora_1_1, injetora_1_2, injetora_1_3};

    int peixe_1[2] = {40, 1};
    int peixe_2[2] = {45, 0};
    int peixe_3[2] = {50, 1};

    int peixe[3] = {peixe_1, peixe_2, peixe_3};

    ciclo_total[0] = sizeof(temperatura);
    ciclo_total[1] = sizeof(injetora_1);
    ciclo_total[2] = sizeof(peixe);


    while ((ciclo[0] > ciclo[0]) && (ciclo[1] > ciclo[1]) && (ciclo[2] > ciclo[2])) {

        //Trecho de verificaçao da temperatura
        if ciclo[0] <= ciclo_total[0] {

            if t >= temperatura[ciclo[0]][0] {
                UARTprintf("Setando temperatura para: %d", temperatura[ciclo[0]][1]);
                ciclo[0]++;
            }
        }

        //Trecho de verificaçao da injetora 1
        if ciclo[1] <= ciclo_total[1] {

            if t >= injetora_1[ciclo[1]][0] {
                UARTprintf("Injetando %d ml da injetora 1", injetora[ciclo[1]][1]);
                ciclo[1]++;
            }
        }

        //Trecho de verificaçao do peixinho
        if ciclo[2] <= ciclo_total[2] {

            if t >= peixe[ciclo[2]][0] {

                if peixe[ciclo[2]][1] == 0 {

                    UARTprintf("Desligando o peixinho");

                }
                else {

                    UARTprintf("Ligando o peixinho");

                }
                ciclo[2]++;
            }
        }
    }

//    g_ui32SysClock = MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
//                                             SYSCTL_OSC_MAIN |
//                                             SYSCTL_USE_PLL |
//                                             SYSCTL_CFG_VCO_480), 120000000);
//    ConfigureUART();
//    UARTprintf("\033[2JTimers example\n");
//    UARTprintf("T1: 0  T2: 0");
//    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
//    ROM_GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1);
//    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
//    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
//    ROM_IntMasterEnable();
//    ROM_TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
//    ROM_TimerConfigure(TIMER1_BASE, TIMER_CFG_PERIODIC);
//    ROM_TimerLoadSet(TIMER0_BASE, TIMER_A, g_ui32SysClock);
//    ROM_TimerLoadSet(TIMER1_BASE, TIMER_A, g_ui32SysClock / 2);
//    ROM_IntEnable(INT_TIMER0A);
//    ROM_IntEnable(INT_TIMER1A);
//    ROM_TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
//    ROM_TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
//    ROM_TimerEnable(TIMER0_BASE, TIMER_A);
//    ROM_TimerEnable(TIMER1_BASE, TIMER_A);
//
//    while(1)
//    {
//    }
}


int controller_demonstration(void)
{
    return view_demonstration();
}
