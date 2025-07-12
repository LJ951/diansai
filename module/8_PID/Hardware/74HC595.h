#ifndef __74HC595_H_
#define __74HC595_H_

void hex_to_bin(uint8_t hex, int *bin);
void stoeage_Init(void);
void stoeage_W(uint8_t data);
void stoeage_Clear(void);
void stoeage_Update(void);
void stoeage_Out(uint8_t data);

#endif
