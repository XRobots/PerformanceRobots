// ************** encoder 0 *********************

void doEncoderA(){  

  // look for a low-to-high on channel A
  if (digitalRead(encoder0PinA) == HIGH) { 
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinB) == LOW) {  
      encoder0Pos = encoder0Pos + 1;         // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
  }
  else   // must be a high-to-low edge on channel A                                       
  { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(encoder0PinB) == HIGH) {   
      encoder0Pos = encoder0Pos + 1;          // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }
  }
 
}


void doEncoderB(){  

  // look for a low-to-high on channel B
  if (digitalRead(encoder0PinB) == HIGH) {   
   // check channel A to see which way encoder is turning
    if (digitalRead(encoder0PinA) == HIGH) {  
      encoder0Pos = encoder0Pos + 1;         // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
  }
  // Look for a high-to-low on channel B
  else { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(encoder0PinA) == LOW) {   
      encoder0Pos = encoder0Pos + 1;          // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }
  }

}

// ************** encoder 1 *********************

void doEncoderC(){  

  // look for a low-to-high on channel A
  if (digitalRead(encoder1PinA) == HIGH) { 
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder1PinB) == LOW) {  
      encoder1Pos = encoder1Pos + 1;         // CW
    } 
    else {
      encoder1Pos = encoder1Pos - 1;         // CCW
    }
  }
  else   // must be a high-to-low edge on channel A                                       
  { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(encoder1PinB) == HIGH) {   
      encoder1Pos = encoder1Pos + 1;          // CW
    } 
    else {
      encoder1Pos = encoder1Pos - 1;          // CCW
    }
  }
 
}

void doEncoderD(){  

  // look for a low-to-high on channel B
  if (digitalRead(encoder1PinB) == HIGH) {   
   // check channel A to see which way encoder is turning
    if (digitalRead(encoder1PinA) == HIGH) {  
      encoder1Pos = encoder1Pos + 1;         // CW
    } 
    else {
      encoder1Pos = encoder1Pos - 1;         // CCW
    }
  }
  // Look for a high-to-low on channel B
  else { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(encoder1PinA) == LOW) {   
      encoder1Pos = encoder1Pos + 1;          // CW
    } 
    else {
      encoder1Pos = encoder1Pos - 1;          // CCW
    }
  }
  

}

// ************** encoder 2 *********************

void doEncoderE(){  

  // look for a low-to-high on channel A
  if (digitalRead(encoder2PinA) == HIGH) { 
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder2PinB) == LOW) {  
      encoder2Pos = encoder2Pos + 1;         // EW
    } 
    else {
      encoder2Pos = encoder2Pos - 1;         // EEW
    }
  }
  else   // must be a high-to-low edge on channel A                                       
  { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(encoder2PinB) == HIGH) {   
      encoder2Pos = encoder2Pos + 1;          // EW
    } 
    else {
      encoder2Pos = encoder2Pos - 1;          // EEW
    }
  }
 
}

void doEncoderF(){  

  // look for a low-to-high on channel B
  if (digitalRead(encoder2PinB) == HIGH) {   
   // check channel A to see which way encoder is turning
    if (digitalRead(encoder2PinA) == HIGH) {  
      encoder2Pos = encoder2Pos + 1;         // EW
    } 
    else {
      encoder2Pos = encoder2Pos - 1;         // EEW
    }
  }
  // Look for a high-to-low on channel B
  else { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(encoder2PinA) == LOW) {   
      encoder2Pos = encoder2Pos + 1;          // EW
    } 
    else {
      encoder2Pos = encoder2Pos - 1;          // EEW
    }
  }
  

}

// ************** encoder 3 *********************

void doEncoderG(){  

  // look for a low-to-high on channel A
  if (digitalRead(encoder3PinA) == HIGH) { 
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder3PinB) == LOW) {  
      encoder3Pos = encoder3Pos + 1;         // EW
    } 
    else {
      encoder3Pos = encoder3Pos - 1;         // EEW
    }
  }
  else   // must be a high-to-low edge on channel A                                       
  { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(encoder3PinB) == HIGH) {   
      encoder3Pos = encoder3Pos + 1;          // EW
    } 
    else {
      encoder3Pos = encoder3Pos - 1;          // EEW
    }
  }
 
}

void doEncoderH(){  

  // look for a low-to-high on channel B
  if (digitalRead(encoder3PinB) == HIGH) {   
   // check channel A to see which way encoder is turning
    if (digitalRead(encoder3PinA) == HIGH) {  
      encoder3Pos = encoder3Pos + 1;         // EW
    } 
    else {
      encoder3Pos = encoder3Pos - 1;         // EEW
    }
  }
  // Look for a high-to-low on channel B
  else { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(encoder3PinA) == LOW) {   
      encoder3Pos = encoder3Pos + 1;          // EW
    } 
    else {
      encoder3Pos = encoder3Pos - 1;          // EEW
    }
  }


}



