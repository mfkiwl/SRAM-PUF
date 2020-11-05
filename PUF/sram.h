/*
* Created by Abel Gomez 03/15/2020
* Adapted from Ade Setyawan code, available at: 
* https://github.com/Tribler/software-based-PUF
*/
#ifndef SRAM_H
#define SRAM_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <bcm2835.h>

using namespace std;

class SRAM {
private:
    uint32_t maxram = 131072; //number of bytes in 23LC1024 SRAM
    uint32_t maxpage = 4096;  //number of pages in 23LC1024 SRAM    
    
    uint8_t read8(uint32_t address);
    void write8(uint32_t address, uint8_t data_byte);
    void read32(uint32_t address, uint8_t* buffer);
    void write32(uint32_t address, uint8_t* buffer);
  
public:
    SRAM();
    
    uint32_t get_max_ram();
    uint32_t get_max_page();
    
    void turn_off();
    void turn_on();
    
    void write_page(long page, bool is_one);
    void read_page(uint32_t page, uint8_t* result);
    uint8_t read_byte(long location);
    void write_byte(long address, uint8_t data);
    void write_all_zero();
    void write_all_one();
};

#endif //SRAM_H
