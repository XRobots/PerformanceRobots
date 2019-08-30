void OdriveInit() {

      Serial.println("Odrive 3");   // arms - smaller motors

      for (int axis = 0; axis < 2; ++axis) {
          Serial4 << "w axis" << axis << ".controller.config.vel_limit " << 80000.0f << '\n';
          Serial4 << "w axis" << axis << ".motor.config.current_lim " << 40.0f << '\n';
          Serial4 << "w axis" << axis << ".motor.config.calibration_current " << 30.0f << '\n';

          requested_state = ODriveArduino::AXIS_STATE_MOTOR_CALIBRATION;
          Serial << "Axis" << axis << ": Requesting state " << requested_state << '\n';
          odrive3.run_state(axis, requested_state, true);
    
          requested_state = ODriveArduino::AXIS_STATE_ENCODER_OFFSET_CALIBRATION;
          Serial << "Axis" << axis << ": Requesting state " << requested_state << '\n';
          odrive3.run_state(axis, requested_state, true);
    
          requested_state = ODriveArduino::AXIS_STATE_CLOSED_LOOP_CONTROL;
          Serial << "Axis" << axis << ": Requesting state " << requested_state << '\n';
          odrive3.run_state(axis, requested_state, false); // don't wait 
      }



      Serial.println("Odrive 1");   // arms - outwards

      for (int axis = 0; axis < 2; ++axis) {
          Serial2 << "w axis" << axis << ".controller.config.vel_limit " << 360000.0f << '\n';
          Serial2 << "w axis" << axis << ".motor.config.current_lim " << 5.0f << '\n';

          requested_state = ODriveArduino::AXIS_STATE_MOTOR_CALIBRATION;
          Serial << "Axis" << axis << ": Requesting state " << requested_state << '\n';
          odrive1.run_state(axis, requested_state, true);
    
          requested_state = ODriveArduino::AXIS_STATE_ENCODER_OFFSET_CALIBRATION;
          Serial << "Axis" << axis << ": Requesting state " << requested_state << '\n';
          odrive1.run_state(axis, requested_state, true);
    
          requested_state = ODriveArduino::AXIS_STATE_CLOSED_LOOP_CONTROL;
          Serial << "Axis" << axis << ": Requesting state " << requested_state << '\n';
          odrive1.run_state(axis, requested_state, false); // don't wait 
      }



      Serial.println("Odrive 2");   // ribs

      for (int axis = 0; axis < 2; ++axis) {
          Serial3 << "w axis" << axis << ".controller.config.vel_limit " << 360000.0f << '\n';
          Serial3 << "w axis" << axis << ".motor.config.current_lim " << 5.0f << '\n';

          requested_state = ODriveArduino::AXIS_STATE_MOTOR_CALIBRATION;
          Serial << "Axis" << axis << ": Requesting state " << requested_state << '\n';
          odrive2.run_state(axis, requested_state, true);
    
          requested_state = ODriveArduino::AXIS_STATE_ENCODER_OFFSET_CALIBRATION;
          Serial << "Axis" << axis << ": Requesting state " << requested_state << '\n';
          odrive2.run_state(axis, requested_state, true);
    
          requested_state = ODriveArduino::AXIS_STATE_CLOSED_LOOP_CONTROL;
          Serial << "Axis" << axis << ": Requesting state " << requested_state << '\n';
          odrive2.run_state(axis, requested_state, false); // don't wait 
      }

           
         
  
}






