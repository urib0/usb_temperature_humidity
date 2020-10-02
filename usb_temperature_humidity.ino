#define SHT30_ADDR 0x44

#define STATUS_OK 0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect
  }
  delay(1000);
  
  sht30_init( SHT30_ADDR );
  
}

void loop() {
  
  // put your main code here, to run repeatedly:
  uint32_t ui_temp = 0;
  uint32_t ui_hum = 0;

  sht30_get_th( &ui_temp, &ui_hum );

  Serial.print("temp=");
  Serial.print(ui_temp, DEC);
  Serial.print(";hum=");
  Serial.print(ui_hum, DEC);
  Serial.print(";status=");
  Serial.print(STATUS_OK);
  Serial.print("\n");

  delay( 1000 );
}
