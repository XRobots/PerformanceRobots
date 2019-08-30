void black() {
   
   for(int blackLed = 0; blackLed < NUM_LEDS; blackLed = blackLed + 1) {

      leds[blackLed] = CRGB::Black;
      FastLED.show();


   }

}
