/*  keyer_hardware.h */

// Serial port class definitions for various devices

#if defined(ARDUINO_MAPLE_MINI)||defined(ARDUINO_GENERIC_STM32F103C) //sp5iou 20180329
  #define PRIMARY_SERIAL_CLS USBSerial
  #define SECONDARY_SERIAL_CLS USBSerial 
#elif defined(ARDUINO_AVR_PROMICRO) || defined(ARDUINO_AVR_LEONARDO) || defined(ARDUINO_AVR_MICRO) || defined(ARDUINO_AVR_YUN) || defined(ARDUINO_AVR_ESPLORA) || defined(ARDUINO_AVR_LILYPAD_USB) || defined(ARDUINO_AVR_ROBOT_CONTROL) || defined(ARDUINO_AVR_ROBOT_MOTOR) || defined(ARDUINO_AVR_LEONARDO_ETH)  || defined(ARDUINO_SAMD_VARIANT_COMPLIANCE)
  #define PRIMARY_SERIAL_CLS Serial_
  #define SECONDARY_SERIAL_CLS Serial_ 
#elif defined(TEENSYDUINO)
  #define PRIMARY_SERIAL_CLS usb_serial_class
  #define SECONDARY_SERIAL_CLS usb_serial_class
#elif defined(_BOARD_PIC32_PINGUINO_) // || defined(_BOARD_PIC32_PINGUINO_OTG_)
  #define PRIMARY_SERIAL_CLS USBSerial
  #define SECONDARY_SERIAL_CLS HardwareSerial
#else
  #define PRIMARY_SERIAL_CLS HardwareSerial
  #define SECONDARY_SERIAL_CLS HardwareSerial 
#endif
  
