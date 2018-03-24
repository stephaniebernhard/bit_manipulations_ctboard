/* -----------------------------------------------------------------
 * --  _____       ______  _____                                    -
 * -- |_   _|     |  ____|/ ____|                                   -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems    -
 * --   | | | '_ \|  __|  \___ \   Zurich University of             -
 * --  _| |_| | | | |____ ____) |  Applied Sciences                 -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland     -
 * ------------------------------------------------------------------
 * --
 * -- main.c
 * --
 * -- main for Computer Engineering "Bit Manipulations"
 * --
 * -- $Id: main.c 744 2014-09-24 07:48:46Z ruan $
 * ------------------------------------------------------------------
 */
//#include <reg_ctboard.h>
#include "utils_ctboard.h"

#define ADDR_DIP_SWITCH_31_0 0x60000200
#define ADDR_DIP_SWITCH_7_0  0x60000200
#define ADDR_LED_31_24       0x60000103
#define ADDR_LED_23_16       0x60000102
#define ADDR_LED_15_8        0x60000101
#define ADDR_LED_7_0         0x60000100
#define ADDR_BUTTONS         0x60000210

// define your own macros for bitmasks below (#define)
/// STUDENTS: To be programmed

#define BRIGHT 0xC0
#define DARK 0xCF
#define MASK_T0 0x01
#define MASK_T1 0x02
#define MASK_T2 0x04
#define MASK_T3 0x08



/// END: To be programmed

int main(void)
{
    uint8_t led_value = 0;

    // add variables below
    /// STUDENTS: To be programmed
	
		uint8_t button_value = 0;
		uint8_t count = 0;
		uint8_t last = 0;
		uint8_t rising = 1;
		uint8_t push_count = 0;
		// uint8_t output = 0xaa;
		uint8_t output = 0;
		
		


    /// END: To be programmed

    while (1) {
        // ---------- Task 3.1 ----------
        led_value = read_byte(ADDR_DIP_SWITCH_7_0);

        /// STUDENTS: To be programmed

				led_value = led_value | BRIGHT;
				led_value = led_value & DARK;

        /// END: To be programmed

        write_byte(ADDR_LED_7_0, led_value);

        // ---------- Task 3.2 and 3.3 ----------
        /// STUDENTS: To be programmed

				// read buttons
				button_value = read_byte(ADDR_BUTTONS);
				// mask first 4 bits 
				button_value = button_value & 0x0F;
				
				// count to LED_15_8
				if(button_value == 00000001) {
						count++;
				} 
				write_byte(ADDR_LED_15_8, count);
				
				// edge detection
				rising = ~last & button_value;
				
				//count push events to LED_31_24
				if(rising & MASK_T0){
					push_count++;
				} 
				write_byte(ADDR_LED_31_24, push_count);
				
				// 3.3 additional functions when you press a button
				if(rising & MASK_T0){
					output = output >> 1;
				} else if(rising & MASK_T1){
					output = output << 1;
				} else if(rising & MASK_T2){
					output = ~output;
				} else if(rising & MASK_T3) {
					output = read_byte(ADDR_DIP_SWITCH_7_0);
				}
				write_byte(ADDR_LED_23_16, output);
				
				
				// edge detection
					last = button_value;
				
        /// END: To be programmed
    }
}
