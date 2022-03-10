#define coolant_width 24
#define coolant_height 24
static unsigned char coolant_bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00,
  0x00, 0x78, 0x00, 0x00, 0x78, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00,
  0x00, 0x78, 0x00, 0x00, 0x78, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00,
  0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x7E, 0x00, 0x88, 0x7E, 0x11,
  0xF8, 0x7E, 0x1F, 0x70, 0x3C, 0x0E, 0x00, 0x00, 0x00, 0xC4, 0x18, 0x23,
  0xFC, 0xFF, 0x3F, 0x78, 0xE7, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

#define engine_width 24
#define engine_height 24
static unsigned char engine_bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x01, 0x00, 0x04, 0x01,
  0x00, 0xDC, 0x03, 0x00, 0x54, 0x00, 0x00, 0xD0, 0x04, 0x00, 0xFF, 0x0F,
  0x80, 0x01, 0x18, 0xC2, 0x40, 0xF0, 0x77, 0x70, 0xA8, 0x15, 0x30, 0xB0,
  0x1D, 0x38, 0xB0, 0x1D, 0x78, 0x80, 0x19, 0x78, 0x90, 0x1D, 0x20, 0xB8,
  0x15, 0x10, 0xA8, 0x77, 0x00, 0xEC, 0xC2, 0x00, 0x06, 0x00, 0x01, 0x02,
  0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

#define obd2_width 24
#define obd2_height 24
static unsigned char obd2_bits[] = {
  0x80, 0xFF, 0x01, 0x40, 0x18, 0x03, 0x40, 0x9B, 0x01, 0xA0, 0x76, 0x05,
  0xE0, 0x00, 0x07, 0xF0, 0x00, 0x0F, 0xF0, 0x00, 0x05, 0xA0, 0x00, 0x0F,
  0xF0, 0x00, 0x0F, 0xB0, 0x00, 0x0D, 0xC0, 0x00, 0x03, 0xA0, 0xFF, 0x05,
  0x40, 0x3C, 0x02, 0x40, 0x7E, 0x02, 0x80, 0x39, 0x01, 0x80, 0xFF, 0x01,
  0x80, 0xDB, 0x01, 0x80, 0xFF, 0x01, 0x80, 0xFF, 0x01, 0x80, 0xFF, 0x01,
  0x80, 0xFF, 0x01, 0x80, 0x00, 0x01, 0x80, 0x38, 0x01, 0x00, 0xFF, 0x00,
};

#define disconnected_width 24
#define disconnected_height 24
static unsigned char disconnected_bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x31, 0x00, 0xF0, 0x3B, 
  0x00, 0xF0, 0x1F, 0x00, 0xFC, 0x0F, 0x00, 0xFC, 0x1F, 0x00, 0xFC, 0x3F, 
  0x00, 0xFC, 0x3F, 0x00, 0xE6, 0x3F, 0x60, 0xC0, 0x3F, 0xE0, 0x80, 0x0F, 
  0xF0, 0x81, 0x0F, 0xF8, 0xC3, 0x06, 0xFC, 0x47, 0x00, 0xFC, 0x0F, 0x00, 
  0xFC, 0x1F, 0x00, 0xF8, 0x3F, 0x00, 0xF0, 0x3F, 0x00, 0xF8, 0x0F, 0x00, 
  0xDC, 0x0F, 0x00, 0x8C, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  };

#define battery_width 24
#define battery_height 24
static unsigned char battery_bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x0F, 0xF8, 0x81, 0x1F, 
  0xF8, 0x00, 0x1D, 0xDA, 0xFF, 0x5F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 
  0xFF, 0xFF, 0xF9, 0x07, 0x7E, 0xE0, 0x9F, 0xFF, 0xF9, 0xFF, 0xFF, 0xF9, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  };

#define fuel_width 24
#define fuel_height 24
static unsigned char fuel_bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x07, 0x00, 0x18, 0x0C, 
  0x60, 0x18, 0x0C, 0xA0, 0x6F, 0x0E, 0xE0, 0xFF, 0x0F, 0xC0, 0xFF, 0x0F, 
  0xE0, 0xFF, 0x0F, 0xC0, 0xFF, 0x0F, 0xC0, 0xFF, 0x0E, 0xE0, 0xFD, 0x0F, 
  0xE0, 0xBB, 0x0F, 0xC0, 0xB7, 0x0F, 0xE0, 0xEF, 0x0F, 0xC0, 0xD7, 0x0F, 
  0xE0, 0xBF, 0x0F, 0xC0, 0x7B, 0x0F, 0xE0, 0xFD, 0x0E, 0xC0, 0xFF, 0x0F, 
  0xC0, 0xFF, 0x0F, 0xC0, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  };
