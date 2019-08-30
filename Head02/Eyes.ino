void eyes(int level) {

  if (level == 0) {
          for(int blackLed = 0; blackLed < 120; blackLed = blackLed + 1) {
            leds[blackLed] = CRGB::Black;
          }        
  }

  if (level == 1) {
          leds[48] = CRGB::Blue;
          leds[49] = CRGB::Blue;
          leds[50] = CRGB::Blue;
          leds[51] = CRGB::Blue;
          leds[52] = CRGB::Blue;
          leds[53] = CRGB::Blue;
          leds[54] = CRGB::Blue;
          leds[55] = CRGB::Blue;
          leds[64] = CRGB::Blue;
          leds[65] = CRGB::Blue;
          leds[66] = CRGB::Blue;
          leds[67] = CRGB::Blue;
          leds[68] = CRGB::Blue;
          leds[69] = CRGB::Blue;
          leds[70] = CRGB::Blue;
          leds[71] = CRGB::Blue;
  }

  else if (level == 2) {
          leds[47] = CRGB::Blue;
          leds[46] = CRGB::Blue;
          leds[45] = CRGB::Blue;
          leds[44] = CRGB::Blue;
          leds[43] = CRGB::Blue;
          leds[42] = CRGB::Blue;
          leds[41] = CRGB::Blue;
          leds[40] = CRGB::Blue;
          leds[31] = CRGB::Blue;
          leds[30] = CRGB::Blue;
          leds[29] = CRGB::Blue;
          leds[28] = CRGB::Blue;
          leds[27] = CRGB::Blue;
          leds[26] = CRGB::Blue;
          leds[25] = CRGB::Blue;
          leds[24] = CRGB::Blue;

          leds[48] = CRGB::Blue;
          leds[51] = CRGB::White;
          leds[52] = CRGB::White;
          leds[55] = CRGB::Blue;
          leds[64] = CRGB::Blue;
          leds[67] = CRGB::White;
          leds[68] = CRGB::White;
          leds[71] = CRGB::Blue;

          leds[95] = CRGB::Blue;
          leds[94] = CRGB::Blue;
          leds[93] = CRGB::Blue;
          leds[92] = CRGB::Blue;
          leds[91] = CRGB::Blue;
          leds[90] = CRGB::Blue;
          leds[89] = CRGB::Blue;
          leds[88] = CRGB::Blue;
          leds[79] = CRGB::Blue;
          leds[78] = CRGB::Blue;
          leds[77] = CRGB::Blue;
          leds[76] = CRGB::Blue;
          leds[75] = CRGB::Blue;
          leds[74] = CRGB::Blue;
          leds[73] = CRGB::Blue;
          leds[72] = CRGB::Blue;              
  }

  else if (level == 3) {
          leds[0] = CRGB::Blue;
          leds[1] = CRGB::Blue;
          leds[2] = CRGB::Blue;
          leds[3] = CRGB::Blue;
          leds[4] = CRGB::Blue;
          leds[5] = CRGB::Blue;
          leds[6] = CRGB::Blue;
          leds[7] = CRGB::Blue;
          leds[16] = CRGB::Blue;
          leds[17] = CRGB::Blue;
          leds[18] = CRGB::Blue;
          leds[19] = CRGB::Blue;
          leds[20] = CRGB::Blue;
          leds[21] = CRGB::Blue;
          leds[22] = CRGB::Blue;
          leds[23] = CRGB::Blue;

          leds[47] = CRGB::Blue;
          leds[40] = CRGB::Blue;
          leds[31] = CRGB::Blue;
          leds[24] = CRGB::Blue;

          leds[48] = CRGB::Blue;
          leds[51] = CRGB::White;
          leds[52] = CRGB::White;
          leds[55] = CRGB::Blue;
          leds[64] = CRGB::Blue;
          leds[67] = CRGB::White;
          leds[68] = CRGB::White;
          leds[71] = CRGB::Blue;

          leds[95] = CRGB::Blue;
          leds[88] = CRGB::Blue;
          leds[79] = CRGB::Blue;
          leds[72] = CRGB::Blue;

          leds[96] = CRGB::Blue;
          leds[97] = CRGB::Blue;
          leds[98] = CRGB::Blue;
          leds[99] = CRGB::Blue;
          leds[100] = CRGB::Blue;
          leds[101] = CRGB::Blue;
          leds[102] = CRGB::Blue;
          leds[103] = CRGB::Blue;
          leds[112] = CRGB::Blue;
          leds[113] = CRGB::Blue;
          leds[114] = CRGB::Blue;
          leds[115] = CRGB::Blue;
          leds[116] = CRGB::Blue;
          leds[117] = CRGB::Blue;
          leds[118] = CRGB::Blue;
          leds[119] = CRGB::Blue;              
  }

    else if (level == 4) {
          leds[47] = CRGB::Blue;
          leds[46] = CRGB::Blue;
          leds[45] = CRGB::Blue;
          leds[44] = CRGB::Blue;
          leds[43] = CRGB::Blue;
          leds[42] = CRGB::Blue;
          leds[41] = CRGB::Blue;
          leds[40] = CRGB::Blue;
          leds[31] = CRGB::Blue;
          leds[30] = CRGB::Blue;
          leds[29] = CRGB::Blue;
          leds[28] = CRGB::Blue;
          leds[27] = CRGB::Blue;
          leds[26] = CRGB::Blue;
          leds[25] = CRGB::Blue;
          leds[24] = CRGB::Blue;

          leds[48] = CRGB::Blue;
          leds[51] = CRGB::White;
          leds[52] = CRGB::White;
          leds[55] = CRGB::Blue;
          leds[64] = CRGB::Blue;
          leds[67] = CRGB::White;
          leds[68] = CRGB::White;
          leds[71] = CRGB::Blue;

          leds[95] = CRGB::Blue;
          leds[94] = CRGB::Blue;
          leds[93] = CRGB::Blue;
          leds[92] = CRGB::Blue;
          leds[91] = CRGB::Blue;
          leds[90] = CRGB::Blue;
          leds[89] = CRGB::Blue;
          leds[88] = CRGB::Blue;
          leds[79] = CRGB::Blue;
          leds[78] = CRGB::Blue;
          leds[77] = CRGB::Blue;
          leds[76] = CRGB::Blue;
          leds[75] = CRGB::Blue;
          leds[74] = CRGB::Blue;
          leds[73] = CRGB::Blue;
          leds[72] = CRGB::Blue;              
  }

  // *************** larson scanner**********************

  else if (level == 20) {
          leds[0] = CRGB::Red;
          leds[47] = CRGB::Red;
          leds[48] = CRGB::Red;
          leds[95] = CRGB::Red;
          leds[96] = CRGB::Red;
  }

  else if (level == 21) {
          leds[1] = CRGB::Red;
          leds[46] = CRGB::Red;
          leds[49] = CRGB::Red;
          leds[94] = CRGB::Red;
          leds[97] = CRGB::Red;
  }

  else if (level == 22) {
          leds[2] = CRGB::Red;
          leds[45] = CRGB::Red;
          leds[50] = CRGB::Red;
          leds[93] = CRGB::Red;
          leds[98] = CRGB::Red;
  }

  else if (level == 23) {
          leds[3] = CRGB::Red;
          leds[44] = CRGB::Red;
          leds[51] = CRGB::Red;
          leds[92] = CRGB::Red;
          leds[99] = CRGB::Red;
  }
  
  else if (level == 24) {
          leds[4] = CRGB::Red;
          leds[43] = CRGB::Red;
          leds[52] = CRGB::Red;
          leds[91] = CRGB::Red;
          leds[100] = CRGB::Red;
  }

  else if (level == 25) {
          leds[5] = CRGB::Red;
          leds[42] = CRGB::Red;
          leds[53] = CRGB::Red;
          leds[90] = CRGB::Red;
          leds[101] = CRGB::Red;
  }

  else if (level == 26) {
          leds[6] = CRGB::Red;
          leds[41] = CRGB::Red;
          leds[54] = CRGB::Red;
          leds[89] = CRGB::Red;
          leds[102] = CRGB::Red;
  }

  else if (level == 27) {
          leds[7] = CRGB::Red;
          leds[40] = CRGB::Red;
          leds[55] = CRGB::Red;
          leds[88] = CRGB::Red;
          leds[103] = CRGB::Red;
  }

  else if (level == 28) {
          leds[8] = CRGB::Red;
          leds[39] = CRGB::Red;
          leds[56] = CRGB::Red;
          leds[87] = CRGB::Red;
          leds[104] = CRGB::Red;
  }

  else if (level == 29) {
          leds[9] = CRGB::Red;
          leds[38] = CRGB::Red;
          leds[57] = CRGB::Red;
          leds[86] = CRGB::Red;
          leds[105] = CRGB::Red;
  }

  else if (level == 30) {
          leds[10] = CRGB::Red;
          leds[37] = CRGB::Red;
          leds[58] = CRGB::Red;
          leds[85] = CRGB::Red;
          leds[106] = CRGB::Red;
  }

  else if (level == 31) {
          leds[11] = CRGB::Red;
          leds[36] = CRGB::Red;
          leds[59] = CRGB::Red;
          leds[84] = CRGB::Red;
          leds[107] = CRGB::Red;
  }

  else if (level == 32) {
          leds[12] = CRGB::Red;
          leds[35] = CRGB::Red;
          leds[60] = CRGB::Red;
          leds[83] = CRGB::Red;
          leds[108] = CRGB::Red;
  }

  else if (level == 33) {
          leds[13] = CRGB::Red;
          leds[34] = CRGB::Red;
          leds[61] = CRGB::Red;
          leds[82] = CRGB::Red;
          leds[109] = CRGB::Red;
  }

  else if (level == 34) {
          leds[14] = CRGB::Red;
          leds[33] = CRGB::Red;
          leds[62] = CRGB::Red;
          leds[81] = CRGB::Red;
          leds[110] = CRGB::Red;
  }

  else if (level == 35) {
          leds[15] = CRGB::Red;
          leds[32] = CRGB::Red;
          leds[63] = CRGB::Red;
          leds[80] = CRGB::Red;
          leds[111] = CRGB::Red;
  }

  else if (level == 36) {
          leds[16] = CRGB::Red;
          leds[31] = CRGB::Red;
          leds[64] = CRGB::Red;
          leds[79] = CRGB::Red;
          leds[112] = CRGB::Red;
  }

  else if (level == 37) {
          leds[17] = CRGB::Red;
          leds[30] = CRGB::Red;
          leds[65] = CRGB::Red;
          leds[78] = CRGB::Red;
          leds[113] = CRGB::Red;
  }

  else if (level == 38) {
          leds[18] = CRGB::Red;
          leds[29] = CRGB::Red;
          leds[66] = CRGB::Red;
          leds[77] = CRGB::Red;
          leds[114] = CRGB::Red;
  }

  else if (level == 39) {
          leds[19] = CRGB::Red;
          leds[28] = CRGB::Red;
          leds[67] = CRGB::Red;
          leds[76] = CRGB::Red;
          leds[115] = CRGB::Red;
  }

  else if (level == 40) {
          leds[20] = CRGB::Red;
          leds[27] = CRGB::Red;
          leds[68] = CRGB::Red;
          leds[75] = CRGB::Red;
          leds[116] = CRGB::Red;
  }

  else if (level == 41) {
          leds[21] = CRGB::Red;
          leds[26] = CRGB::Red;
          leds[69] = CRGB::Red;
          leds[74] = CRGB::Red;
          leds[117] = CRGB::Red;
  }

  else if (level == 42) {
          leds[22] = CRGB::Red;
          leds[25] = CRGB::Red;
          leds[70] = CRGB::Red;
          leds[73] = CRGB::Red;
          leds[118] = CRGB::Red;
  }

  else if (level == 43) {
          leds[23] = CRGB::Red;
          leds[24] = CRGB::Red;
          leds[71] = CRGB::Red;
          leds[72] = CRGB::Red;
          leds[119] = CRGB::Red;
  }

  FastLED.show();
}

  
