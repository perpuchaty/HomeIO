/*
 * flash.c
 *
 *  Created on: 7 lut 2024
 *      Author: Sowa
 */
#include "main.h"
#include "system.h"

// Function to erase a flash page
void EraseFlashPage (uint32_t PageAddress)
{
  FLASH_EraseInitTypeDef EraseInitStruct;
  uint32_t PageError = 0;

  // Erase settings
  EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
  EraseInitStruct.Page = PageAddress;
  EraseInitStruct.NbPages = 1;

  HAL_FLASH_Unlock (); // Unlock the flash

  // Erase the page
  if (HAL_FLASHEx_Erase (&EraseInitStruct, &PageError) != HAL_OK)
    {
      // Error occurred while erasing the flash page
      // Handle error here
    }

  HAL_FLASH_Lock (); // Lock the flash
}

// Function to program flash memory
void ProgramFlash (uint32_t Address, uint8_t *Data, uint32_t DataLength)
{
  HAL_StatusTypeDef status = HAL_OK;

  HAL_FLASH_Unlock (); // Unlock the flash

  for (uint32_t i = 0; i < DataLength / 8; ++i)
    {
      uint64_t value = 0;
      for (int j = 0; j < 8; ++j)
	{
	  value |= ((uint64_t) Data[i * 8 + j] << (j * 8));
	}
      status = HAL_FLASH_Program (FLASH_TYPEPROGRAM_DOUBLEWORD,
				  Address + (i * 8), value);
      if (status != HAL_OK)
	{
	  // Error occurred while programming flash
	  // Handle error here
	}
    }

  HAL_FLASH_Lock (); // Lock the flash
}

void ProgramSettings (struct Settings *settings)
{
  EraseFlashPage (127); //Erase last page, we are working on 256k CPU, last page is 127 then.

  // Calculate the size of the struct
  size_t struct_size = sizeof(struct Settings);

  // Program the settings structure into flash
  ProgramFlash (FLASH_SETTINGS_PAGE_ADDRESS, (uint8_t*) settings, struct_size);
}

void ReadSettingsFromFlash (uint32_t Address, struct Settings *settings)
{
  // Calculate the size of the struct
  size_t struct_size = sizeof(struct Settings);

  // Copy the data from flash to the struct instance
  memcpy (settings, (struct Settings*) Address, struct_size);
}
