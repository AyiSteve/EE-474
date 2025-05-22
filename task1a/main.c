#include "../SSD2119/SSD2119_Display.h"
#include "../SSD2119/tm4c1294ncpdt.h"
#include <stdint.h>
#include <stdarg.h>

int main(void) {
  LCD_Init();
  double n = 0;
  LCD_ColorFill(Color4[2]);
  while(1)
  {
    LCD_SetCursor(0,0);

      LCD_Printf("Printf: %f\n", n);
      LCD_PrintFloat(n);
      n = n+(1.01);
     
  }
  
  return 0;
  
}