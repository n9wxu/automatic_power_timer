/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F15313
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set BUTTON aliases
#define BUTTON_TRIS                 TRISAbits.TRISA0
#define BUTTON_LAT                  LATAbits.LATA0
#define BUTTON_PORT                 PORTAbits.RA0
#define BUTTON_WPU                  WPUAbits.WPUA0
#define BUTTON_OD                   ODCONAbits.ODCA0
#define BUTTON_ANS                  ANSELAbits.ANSA0
#define BUTTON_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define BUTTON_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define BUTTON_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define BUTTON_GetValue()           PORTAbits.RA0
#define BUTTON_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define BUTTON_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define BUTTON_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define BUTTON_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define BUTTON_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define BUTTON_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define BUTTON_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define BUTTON_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA1
#define LED_LAT                  LATAbits.LATA1
#define LED_PORT                 PORTAbits.RA1
#define LED_WPU                  WPUAbits.WPUA1
#define LED_OD                   ODCONAbits.ODCA1
#define LED_ANS                  ANSELAbits.ANSA1
#define LED_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED_GetValue()           PORTAbits.RA1
#define LED_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set POWER aliases
#define POWER_TRIS                 TRISAbits.TRISA2
#define POWER_LAT                  LATAbits.LATA2
#define POWER_PORT                 PORTAbits.RA2
#define POWER_WPU                  WPUAbits.WPUA2
#define POWER_OD                   ODCONAbits.ODCA2
#define POWER_ANS                  ANSELAbits.ANSA2
#define POWER_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define POWER_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define POWER_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define POWER_GetValue()           PORTAbits.RA2
#define POWER_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define POWER_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define POWER_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define POWER_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define POWER_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define POWER_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define POWER_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define POWER_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set CURRENT aliases
#define CURRENT_TRIS                 TRISAbits.TRISA4
#define CURRENT_LAT                  LATAbits.LATA4
#define CURRENT_PORT                 PORTAbits.RA4
#define CURRENT_WPU                  WPUAbits.WPUA4
#define CURRENT_OD                   ODCONAbits.ODCA4
#define CURRENT_ANS                  ANSELAbits.ANSA4
#define CURRENT_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define CURRENT_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define CURRENT_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define CURRENT_GetValue()           PORTAbits.RA4
#define CURRENT_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define CURRENT_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define CURRENT_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define CURRENT_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define CURRENT_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define CURRENT_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define CURRENT_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define CURRENT_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set VBAT aliases
#define VBAT_TRIS                 TRISAbits.TRISA5
#define VBAT_LAT                  LATAbits.LATA5
#define VBAT_PORT                 PORTAbits.RA5
#define VBAT_WPU                  WPUAbits.WPUA5
#define VBAT_OD                   ODCONAbits.ODCA5
#define VBAT_ANS                  ANSELAbits.ANSA5
#define VBAT_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define VBAT_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define VBAT_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define VBAT_GetValue()           PORTAbits.RA5
#define VBAT_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define VBAT_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define VBAT_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define VBAT_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define VBAT_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define VBAT_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define VBAT_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define VBAT_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/