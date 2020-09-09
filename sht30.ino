#include <Wire.h>

static uint8_t command_softreset[] = { 0x30, 0xA2 };
static uint8_t command_highrep[] = { 0x24, 0x00 };

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

bool sht30_get_th( uint16_t *temp, uint16_t *hum){
  uint8_t buff[6] ={0};

  Wire.beginTransmission( suc_addr );
  Wire.write( command_highrep, sizeof( command_highrep ) );
  Wire.endTransmission();

  // 測定時間にMAX20msかかる
  delay(15);

  Wire.requestFrom( suc_addr, sizeof(buff) );
  if( Wire.available() != sizeof(buff) ){
    return false;
  }

  for( uint8_t i = 0; i < sizeof(buff); i++ ){
    buff[i] = Wire.read();
  }

  *temp = (uint16_t)buff[0] << 8 | buff[1];
  *hum = (uint16_t)buff[3] << 8 | buff[4];

  return true;
}
