#define SHT30_ADDR 0x44

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect
  }
  delay(1000);
  Serial.println("SHT30 start");
  
  sht30_init( SHT30_ADDR );
  
}

void loop() {
  
  // put your main code here, to run repeatedly:
  uint32_t ui_temp = 0;
  uint32_t ui_hum = 0;

  sht30_get_th( &ui_temp, &ui_hum );

  Serial.print("temp:");
  Serial.println(ui_temp, DEC);
  Serial.print("hum:");
  Serial.println(ui_hum, DEC);

  delay( 1000 );
}
