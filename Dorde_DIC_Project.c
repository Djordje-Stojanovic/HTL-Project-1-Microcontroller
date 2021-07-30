/******************************************************************************

Author: Dorde Stojanovic
supervisor: Roland Lezuo
Class: 5BHEL
Last Update: 25.01.2021
Programm: This program is related to the dic-project of first semester of th 5BHE-FSST-class
Github-Respo: https://github.com/Djordje-Stojanovic/FSST/tree/main/Stojanovic_DIC_PROJECT/Stojanovic_DIC_PROJECT

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------------
//this function configures all the clock related settings
//the clock address room goes from 0x40021000 to 0x400213FF
void configure_clock()
{
    //AHB Configuration
    //Address = 0x40021000+0x14
    //config = 0x00020000
    //related bits = bit 17 - IOPA EN
    uint32_t *rcc_ahbenr
    rcc_ahbenr = 0x40021000 + 0x14
    *rcc_ahbenr |= 0x00020000

    //APB Configuration
    //Address = 0x40021000+0x18
    //config = 0x00004200
    //related bits = bit 14 - usart1 clock, bit 9 - adc interface clock
    uint32_t *rcc_apb2enr
    rcc_apb2enr = 0x40021000 + 0x18
    *rcc_apb2enr |= 0x00004200

    //USART1SW Configuration
    //Address = 0x40021000+0x30
    //config = 0x00000003
    //related bits = 0 and 1 - usart1sw
    uint32_t *rcc_cfgr3
    rcc_cfgr3 = 0x40021000 + 0x30
    *rcc_cfgr3 |= 0x00000003
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//this function configures all the pin related settings
//the pin or GPIOA address room goes from 0x48000000 to 0x480003FF
void configure_pins()
{
    //Pin Type configuration
    //Address = 0x48000000+0x00
    //config = 0x00280050
    //related bits = bit 4 to bit 7 - for max485 output
    //related bits = bit 18 to bit 21 - for alternate functions
    uint32_t *gpiox_moder
    gpiox_moder = 0x48000000+0x00
    *gpiox_moder |= 0x00280050

    //Alternate Functions configuration
    //Address = 0x48000000+0x24
    //config = 0x00000110
    //related bits = bit 4-11 - for alternate function 1
    uint32_t *gpiox_afrh
    gpiox_afrh = 0x48000000+0x24
    *gpiox_afrh |= 0x00000110

    //GPIOA pins configuration
    //Address = 0x48000000+0x14
    //config = 0x0000000C
    //related bits = 2 and 3 - for pins PA02 and PA03
    uint32_t *gpiox_odr
    gpiox_odr = 0x48000000+0x14
    *gpiox_odr |= 0x0000000C
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//this function configures all the USART related settings
//the pin or GPIOA address room goes from 0x40013800-0x40013BFF
void configure_usart()
{
    //control register 1 Configuration
    //Address = 0x40013800+0x00
    //config = 0x0000060C
    //related bits = bit 2 - receiver enable
    //related bits = bit 3 - transmitter enable
    //related bits = bit 9 - parity selection
    //related bits = bit 10 - parity control enable
    //related bits = bit 28 and bit 12 - data word length
    uint32_t *usart_cr1
    usart_cr1 = 0x40013800+0x00
    *usart_cr1 |= 0x0000060C

    //baudrate configuration
    //Address = 0x40013800+0x0C
    //config = 0x000000D1
    //related bits = bit 7, 6, 4, 0 - to
    //to prouce the number 209 which we calculated
    uint32_t *usart_brr
    usart_brr = 0x40013800+0x0C
    *usart_brr |= 0x000000D1

    //usart enabling
    //Address = 0x40013800+0x00
    //config = 0x00000001
    //related bits = 2 and 3 - for pins PA02 and PA03
    uint32_t *gpiox_odr
    gpiox_odr = 0x48000000+0x14
    *gpiox_odr |= 0x00000001
}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
int main()
{
    //All configurations that have to do with clock are done after this
    configure_clock();

    //All configurations that have to do with pins are done after this
    configure_pins();

    //All configurations that have to do with the usart are done after this
    configure_usart();

    return 0;
}
//------------------------------------------------------------------------------













