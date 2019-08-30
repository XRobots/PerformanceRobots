void ODriveGo1() {
  
        odrive3.SetPosition(0, 18192);        // E small arm motors                     
        odrive3.SetPosition(1, -18192);
}
void ODriveGo2() {

        
        odrive3.SetPosition(0, 0);        // F small arm motors                     
        odrive3.SetPosition(1, 0);
}

void ODriveGo3() {
        odrive1.SetPosition(0, -240000);     // G arms outwards                         
        odrive1.SetPosition(1, -240000);
}
void ODriveGo4() {
        odrive1.SetPosition(0, 0);          // H  arms down                        
        odrive1.SetPosition(1, 0);
}

void ODriveGo5() {
        odrive2.SetPosition(0, -120000);    // I ribs                          
        odrive2.SetPosition(1, -120000);
}
void ODriveGo6() {
        odrive2.SetPosition(0, 0);          // J  middle                     
        odrive2.SetPosition(1, 0);
}
void ODriveGo7() {
        odrive2.SetPosition(0, 100000);     // K  lean forwards                    
        odrive2.SetPosition(1, 100000);
}
void ODriveGo8() {
        odrive2.SetPosition(0, 80000);      // L  lean right                      
        odrive2.SetPosition(1, -80000);
}
void ODriveGo9() {
        odrive2.SetPosition(0, -80000);     // M   lean left                      
        odrive2.SetPosition(1, 80000);
}



