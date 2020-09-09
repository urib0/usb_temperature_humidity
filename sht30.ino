#include <Wire.h>

static uint8_t command_softreset[] = { 0x30, 0xA2 }; 

static uint8_t suc_addr = 0;

void sht30_init( uint8_t addr  ){
  suc_addr = addr;
  Wire.begin();
  sht30_reset();
}

void sht30_reset(){
  Wire.beginTransmission( suc_addr );
  Wire.write( command_softreset, sizeof( command_softreset ) );
  Wire.endTransmission();
  delay(10);
}
