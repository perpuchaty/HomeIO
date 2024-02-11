/*
 * flash.h
 *
 *  Created on: 7 lut 2024
 *      Author: Sowa
 */

#ifndef SRC_FLASH_H_
#define SRC_FLASH_H_

#define FLASH_PAGE_TO_ERASE  127   // Example: Erase page 63
#define FLASH_SETTINGS_PAGE_ADDRESS 0x0803F800 //Address of the last page
#define FLASH_PAGE_0 0x08000000 //Address of the last page

void EraseFlashPage(uint32_t PageAddress);
void ProgramFlash(uint32_t Address, uint8_t* Data, uint32_t DataLength);

#endif /* SRC_FLASH_H_ */
