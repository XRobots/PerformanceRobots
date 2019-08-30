void mouth(int level) {

  if (level == 0) {
          for(int blackLed = 120; blackLed < 132; blackLed = blackLed + 1) {
            leds[blackLed] = CRGB::Black;
          }        
  }

  else if (level == 1) {
    leds[125] = CRGB::White;
    leds[126] = CRGB::White;
  }

  else if (level == 2) {
    leds[124] = CRGB::White;
    leds[126] = CRGB::White;
    leds[125] = CRGB::White;
    leds[127] = CRGB::White;
  }

  else if (level == 3) {
    leds[124] = CRGB::White;
    leds[126] = CRGB::White;
    leds[125] = CRGB::White;
    leds[127] = CRGB::White;
    leds[123] = CRGB::White;
    leds[128] = CRGB::White;
  }

  else if (level == 4) {
    leds[124] = CRGB::White;
    leds[126] = CRGB::White;
    leds[125] = CRGB::White;
    leds[127] = CRGB::White;
    leds[123] = CRGB::White;
    leds[128] = CRGB::White;
    leds[122] = CRGB::White;
    leds[129] = CRGB::White;    
  }

  else if (level == 5) {
    leds[124] = CRGB::White;
    leds[126] = CRGB::White;
    leds[125] = CRGB::White;
    leds[127] = CRGB::White;
    leds[123] = CRGB::White;
    leds[128] = CRGB::White;
    leds[122] = CRGB::White;
    leds[129] = CRGB::White;    
    leds[121] = CRGB::White;
    leds[130] = CRGB::White;   
  }

  else if (level == 6) {
    leds[124] = CRGB::White;
    leds[126] = CRGB::White;
    leds[125] = CRGB::White;
    leds[127] = CRGB::White;
    leds[123] = CRGB::White;
    leds[128] = CRGB::White;
    leds[122] = CRGB::White;
    leds[129] = CRGB::White;    
    leds[121] = CRGB::White;
    leds[130] = CRGB::White;   
    leds[120] = CRGB::White;
    leds[131] = CRGB::White; 
  }



  FastLED.show();

  
}

