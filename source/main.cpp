﻿#include "flappy/MainFlappy.h"

extern "C"{
#include "spaceinvader/MainSpaceinvader.h"
#include "image/Draw.h"
#include "image/StartScreen.h"
#include "LCD_1in44.h"
#include "screen/Screen.h"
#include <stdint.h>
}

int main(void)
{
  initDisplay();

  MainFlappy flappy;

  uint8_t pos = 0;
  while (1)
  {
    Paint_Clear(WHITE);

    DrawImage(startscreen);

    DrawSelect(pos);

    LCD_1IN44_Display(BlackImage);

    if (DEV_Digital_Read(key1) == 0)
    {
      switch (pos)
      {
      case 0:
        flappy.executeFlappy();
        break;

      case 1:
        mainSpaceinvader();
        break;
      default:
        break;
      }
    }
    else if (DEV_Digital_Read(key2) == 0)
    {
      if (pos == 16)
      {
        pos = 0;
      }
      else
      {
        ++pos;
      }
    }
    DEV_Delay_ms(10);
  }

  return 0;
}