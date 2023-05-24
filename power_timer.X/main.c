/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F15313
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

#include <stdint.h>
#include <stdbool.h>

#define MAXIMUM_VOLTAGE      150UL
#define ALTERNATOR_THRESHOLD 125UL
#define MIN_VOLT_THRESHOLD   100UL

#define WDT_PERIOD_MS 16

#define WDT_PERIODS_PER_MIN 3750UL
#define DELAY_15MIN ( 15UL * WDT_PERIODS_PER_MIN )
#define DELAY_10MIN ( 10UL * WDT_PERIODS_PER_MIN )
#define DELAY_5MIN  (  5UL * WDT_PERIODS_PER_MIN )
#define DELAY_NONE  (  1  )

#define DELAY_COUNT DELAY_10MIN

#define HOLD_TIME 188
#define PRESS_TIME 3
#define FAST_BLINK_TIME 6
#define SLOW_BLINK_TIME 31


typedef struct systemState{
    unsigned long upTime;
    int debounceCount;
    int button_pv;
    unsigned long batteryVoltage;
    bool powerState;
    unsigned long onTimer;
}systemState_t;

#define NO_BUTTON 0
#define PRESSED 1
#define HELD 2

void battery_update(systemState_t *theState)
{
    unsigned int counts = ADC_GetConversion(VBAT);
    unsigned int volts = counts/401;
    
    theState->batteryVoltage = volts;
}

int button_update(systemState_t *theState)
{
    int pressed = NO_BUTTON;
    if( BUTTON_GetValue() == 0 )
    {
        theState->debounceCount ++;
    }
    else
    {
        if(theState->debounceCount > PRESSED)
        {
            pressed = true;
        }
        theState->debounceCount = 0;
    }
    theState->button_pv = pressed;
    return pressed;
}

bool vehicle_running(systemState_t *theState)
{
    return theState->batteryVoltage > ALTERNATOR_THRESHOLD;
}

bool output_isOn(systemState_t *theState)
{
    return theState->powerState;
}

void outputOff(systemState_t *theState)
{
    theState->powerState = false;
}

void outputOn(systemState_t *theState)
{
    theState->powerState = true;
}

bool battery_isHealthy(systemState_t *theState)
{
    bool healthy = true;
    if( theState->batteryVoltage < MIN_VOLT_THRESHOLD ||
            theState->batteryVoltage > MAXIMUM_VOLTAGE )
    {
        healthy = false;
    }
    return healthy;
}


void main(void)
{    
    systemState_t theState = {0};
    
    SYSTEM_Initialize();
    
    while (1)
    {
        LED_SetHigh();
        battery_update(&theState);
        int buttonValue = button_update(&theState);

        if( output_isOn(&theState) )
        {
            if( buttonValue == PRESSED || !battery_isHealthy(&theState) )
            {
                outputOff(&theState);
            }
            if( !vehicle_running(&theState) )
            {
                theState.onTimer --;
                if(theState.onTimer <= 0)
                {
                    outputOff(&theState);
                }
            }
        }
        else // POWER_OFF
        {
            if( battery_isHealthy(&theState) && ( vehicle_running(&theState) || buttonValue == PRESSED))
            {
                outputOn(&theState);
                theState.onTimer = DELAY_COUNT;
            }            
        }

        // Output drives
        if( output_isOn(&theState) )
        {
            POWER_SetHigh();
            // LED_SetHigh();
        }
        else
        {
            POWER_SetLow();
            //LED_SetLow();
        }
        LED_SetLow();
        CLRWDT();
        SLEEP();
    }
}
