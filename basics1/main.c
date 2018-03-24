#include "utils_ctboard.h"

#define SWITCHES 0x60000200
#define LEDS 0x60000100
#define ROTARY 0x60000211
#define DISPLAY 0x60000110

const uint8_t displayseg[] = {
	0xC0, //0
	0xF9, //1
	0xA4, //2
	0xB0, //3
	0x99, //4
	0x92, //5
	0x82, //6
	0xF8, //7
	0x80, //8
	0x90, //9
	0x88, //A
	0x83, //b
	0xC6, //C
	0xA1, //d
	0x86, //E
	0x8E, //F
};

int main(void){
	while(1){
		
		//task 5
		//uint8_t switches = read_byte(SWITCHES);
		//write_byte(LEDS, switches);
		
		// task 6.1
		uint32_t switchesall = read_word(SWITCHES);
		write_word(LEDS, switchesall);
		
		// task 6.2
		uint8_t rotary = read_byte(ROTARY);
		uint8_t rotarymasked = rotary & 0x0F ;
		
		write_byte(DISPLAY, displayseg[rotarymasked]);
	}
}
