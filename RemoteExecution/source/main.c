// Get binary data over serial, store it in memory, execute it from memory.
// Written by UNIX - LibXenon.org

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "video_init.h"

#include <xenon_uart/xenon_uart.h>
#include <elf/elf.h>

// An array of bytes containing the ELF magic number
unsigned char ELF_MAGIC[5] = {0x7f, 0x45, 0x4c, 0x46};

// Point at a specific memory address
unsigned char *address = (unsigned char *) 0xA00000;

int main(){
	videoInit();

	if(kbhit()){
		// Read from UART
		unsigned char data = getch();

		// If sizeof data is equal to 4 bytes
		if(sizeof(data) == 0x4){
			if(strcmp(data, ELF_MAGIC)) printf("!! UNIX ELF DETECTED.\n");
		}
		else{
			printf("!= UNKNOWN FILE DETECTED.\n");
			exit(-1);
		}
	}

	return 0;
}

