/// Supreme Function Slow

void font_FW_Slow(unsigned int time)
 {
  motor(1,Power_Slow);
  motor(2,Power_Slow);
  motor(3,Power_Slow);
  motor(4,Power_Slow);
  delay(time);
 }
void font_BW_Slow(unsigned int time)
 {
  motor(1,-Power_Slow);
  motor(2,-Power_Slow);
  motor(3,-Power_Slow);
  motor(4,-Power_Slow);
  delay(time);
 }
 ///////
void back_FW_Slow(unsigned int time)
 {
  motor(1,-Power_Slow);
  motor(2,-Power_Slow);
  motor(3,-Power_Slow);
  motor(4,-Power_Slow);
  delay(time);
 }
void back_BW_Slow(unsigned int time)
 {
  motor(1,Power_Slow);
  motor(2,Power_Slow);
  motor(3,Power_Slow);
  motor(4,Power_Slow);
  delay(time);
 }
///////////
void font_TL_Slow(unsigned int time)
 {
  motor(1,-Power_Slow);
  motor(2,Power_Slowly);
  motor(3,-Power_Slow);
  motor(4,Power_Slowly);
  delay(time);
 }
void font_TR_Slow(unsigned int time)
 {
  motor(1,Power_Slowly);
  motor(2,-Power_Slow);
  motor(3,Power_Slowly);
  motor(4,-Power_Slow);
  delay(time);
 }
 ///////
void back_TL_Slow(unsigned int time)
 {
  motor(1,-Power_Slowly);
  motor(2,Power_Slow);
  motor(3,-Power_Slowly);
  motor(4,Power_Slow);
  delay(time);
 }
void back_TR_Slow(unsigned int time)
 {
  motor(1,Power_Slow);
  motor(2,-Power_Slowly);
  motor(3,Power_Slow);
  motor(4,-Power_Slowly);
  delay(time);
 }
 ///////
///////////
void font_SL_Slow(unsigned int time)
 {
  motor(1,Power_track_Slow);
  motor(2,Power_Slow);
  motor(3,Power_track_Slow);
  motor(4,Power_Slow);
  delay(time);
 }
void font_SR_Slow(unsigned int time)
 {
  motor(1,Power_Slow);
  motor(2,Power_track_Slow);
  motor(3,Power_Slow);
  motor(4,Power_track_Slow);
  delay(time);
 }
 ///////
void back_SL_Slow(unsigned int time)
 {
  motor(1,-Power_Slow);
  motor(2,-Power_track_Slow);
  motor(3,-Power_Slow);
  motor(4,-Power_track_Slow);
  delay(time);
 }
void back_SR_Slow(unsigned int time)
 {
  motor(1,-Power_track_Slow);
  motor(2,-Power_Slow);
  motor(3,-Power_track_Slow);
  motor(4,-Power_Slow);
  delay(time);
 }
//
void font_SL_Stop(unsigned int time)
 {
  motor(1,0);
  motor(2,Power_Slow);
  motor(3,0);
  motor(4,Power_Slow);
  delay(time);
 }
void font_SR_Stop(unsigned int time)
 {
  motor(1,Power_Slow);
  motor(2,0);
  motor(3,Power_Slow);
  motor(4,0);
  delay(time);
 }
 ///////
void back_SL_Stop(unsigned int time)
 {
  motor(1,-Power_Slow);
  motor(2,0);
  motor(3,-Power_Slow);
  motor(4,0);
  delay(time);
 }
void back_SR_Stop(unsigned int time)
 {
  motor(1,0);
  motor(2,-Power_Slow);
  motor(3,0);
  motor(4,-Power_Slow);
  delay(time);
 }

///////////
void font_SL_ZickZack_Slow(unsigned int time)
 {
  motor(1,Power_ZickZack_Slow);
  motor(2,Power_Slow);
  motor(3,Power_ZickZack_Slow);
  motor(4,Power_Slow);
  delay(time);
 }
void font_SR_ZickZack_Slow(unsigned int time)
 {
  motor(1,Power_Slow);
  motor(2,Power_ZickZack_Slow);
  motor(3,Power_Slow);
  motor(4,Power_ZickZack_Slow);
  delay(time);
 }
 ///////
void back_SL_ZickZack_Slow(unsigned int time)
 {
  motor(1,-Power_Slow);
  motor(2,-Power_ZickZack_Slow);
  motor(3,-Power_Slow);
  motor(4,-Power_ZickZack_Slow);
  delay(time);
 }
void back_SR_ZickZack_Slow(unsigned int time)
 {
  motor(1,-Power_ZickZack_Slow);
  motor(2,-Power_Slow);
  motor(3,-Power_ZickZack_Slow);
  motor(4,-Power_Slow);
  delay(time);
 }
 ///////
///////////
void font_TL90_Slow()
 {
  font_TL_Slow(TIME);
  while(analog(F_trackL)>REF[0]){font_TL_Slow(0);}
  while(analog(F_trackL)<REF[0]){font_TL_Slow(0);}
  while(analog(F_trackL)>REF[0]){font_TL_Slow(0);}
  pause(TIME_PAUSE);
 }
void font_TR90_Slow()
 {
  font_TR_Slow(TIME);
  while(analog(F_trackR)>REF[1]){font_TR_Slow(0);}
  while(analog(F_trackR)<REF[1]){font_TR_Slow(0);}
  while(analog(F_trackR)>REF[1]){font_TR_Slow(0);}
  pause(TIME_PAUSE);
 }
 ///////
void back_TL90_Slow()
 {
  back_TL_Slow(TIME);
  while(analog(B_trackL)>REF[2]){back_TL_Slow(0);}
  while(analog(B_trackL)<REF[2]){back_TL_Slow(0);}
  while(analog(B_trackL)>REF[2]){back_TL_Slow(0);}
  pause(TIME_PAUSE);
 }
void back_TR90_Slow()
 {
  back_TR_Slow(TIME);
  while(analog(B_trackR)>REF[3]){back_TR_Slow(0);}
  while(analog(B_trackR)<REF[3]){back_TR_Slow(0);}
  while(analog(B_trackR)>REF[3]){back_TR_Slow(0);}
  pause(TIME_PAUSE);
 }
///////////
void font_trackLine_Slow()
 {
  if(analog(F_trackL)<REF[0] && analog(F_trackR)<REF[1])
   {font_FW_Slow(0);}
  if(analog(F_trackL)>REF[0] && analog(F_trackR)>REF[1])
   {font_FW_Slow(0);}
  if(analog(F_trackL)>REF[0] && analog(F_trackR)<REF[1])
   {font_SL_Slow(0);}
  if(analog(F_trackL)<REF[0] && analog(F_trackR)>REF[1])
   {font_SR_Slow(0);}
 }
void back_trackLine_Slow()
 {
  if(analog(B_trackL)<REF[2] && analog(B_trackR)<REF[3])
   {back_FW_Slow(0);}
  if(analog(B_trackL)>REF[2] && analog(B_trackR)>REF[3])
   {back_FW_Slow(0);}
  if(analog(B_trackL)>REF[2] && analog(B_trackR)<REF[3])
   {back_SL_Slow(0);}
  if(analog(B_trackL)<REF[2] && analog(B_trackR)>REF[3])
   {back_SR_Slow(0);}
 }
//// ONE
void font_trackLine_R_Slow()
 {
  if(analog(F_trackR)<REF[1])
   {font_SL_ZickZack_Slow(0);}
  if(analog(F_trackR)>REF[1])
   {font_SR_Slow(0);}
 }
void back_trackLine_R_Slow()
 {
  if(analog(B_trackR)<REF[3])
   {back_SL_ZickZack_Slow(0);}
  if(analog(B_trackR)>REF[3])
   {back_SR_Slow(0);}
 }
void font_trackLine_L_Slow()
 {
  if(analog(F_trackL)<REF[0])
   {font_SR_ZickZack_Slow(0);}
  if(analog(F_trackL)>REF[0])
   {font_SL_Slow(0);}
 }
void back_trackLine_L_Slow()
 {
  if(analog(B_trackL)<REF[2])
   {font_SR_ZickZack_Slow(0);}
  if(analog(B_trackL)>REF[2])
   {font_SL_Slow(0);}
 }
/////
void font_trackLine_Slow_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   font_trackLine_Slow();
   delay(1);
   loopTime++;
  }
 }
void back_trackLine_Slow_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   back_trackLine_Slow();
   delay(1);
   loopTime++;
  }
 }
void font_trackLine_R_Slow_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   font_trackLine_R_Slow();
   delay(1);
   loopTime++;
  }
 }
void back_trackLine_R_Slow_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   back_trackLine_R_Slow();
   delay(1);
   loopTime++;
  }
 }
void font_trackLine_L_Slow_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   font_trackLine_L_Slow();
   delay(1);
   loopTime++;
  }
 }
void back_trackLine_L_Slow_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   back_trackLine_L_Slow();
   delay(1);
   loopTime++;
  }
 }
///////////
void font_FFF_Slow()
 {
  while(1)
  {
   if(analog(crossL)>REF[4] || analog(crossR)>REF[5])
   {
    beep();
    font_trackLine_Slow_time(TIME_SLOW);
    break;
   }
   font_trackLine_Slow();
  }
 }
void back_FFF_Slow()
 {
  while(1)
  {
   if(analog(crossL)>REF[4] || analog(crossR)>REF[5])
   {
    beep();
    back_trackLine_Slow_time(TIME_SLOW);
    break;
   }
   back_trackLine_Slow();
  }
 }
void font_LLL_Slow()
 {
  while(1)
  {
   if(analog(crossL)>REF[4])
   {
    pause(TIME_PAUSE); beep();
    font_TL90_Slow();
    font_trackLine_Slow_time(TIME_SLOW);
    break;
   }
   font_trackLine_Slow();
  }
 }
void font_RRR_Slow()
 {
  while(1)
  {
   if(analog(crossR)>REF[5])
   {
    pause(TIME_PAUSE); beep();
    font_TR90_Slow();
    font_trackLine_Slow_time(TIME_SLOW);
    break;
   }
   font_trackLine_Slow();
  }
 }
void back_LLL_Slow()
 {
  while(1)
  {
   if(analog(crossR)>REF[3])
   {
    pause(TIME_PAUSE); beep();
    back_TL90_Slow();
    back_trackLine_Slow_time(TIME_SLOW);
    break;
   }
   back_trackLine_Slow();
  }
 }
void back_RRR_Slow()
 {
  while(1)
  {
   if(analog(crossL)>REF[2])
   {
    pause(TIME_PAUSE); beep();
    back_TR90_Slow();
    back_trackLine_Slow_time(TIME_SLOW);
    break;
   }
   back_trackLine_Slow();
  }
 }
 ///
/////
void font_FF_L_Slow()
 {
  while(1)
  {
   if(analog(crossL)>REF[4])
   {
    beep();
    font_trackLine_Slow_time(TIME_SLOW);
    break;
   }
   font_trackLine_Slow();
  }
 }
void font_FF_R_Slow()
 {
  while(1)
  {
   if(analog(crossR)>REF[5])
   {
    beep();
    font_trackLine_Slow_time(TIME_SLOW);
    break;
   }
   font_trackLine_Slow();
  }
 }
void font_F_L_Slow()
 {
  while(1)
  {
   if(analog(crossL)>REF[4])
   {
    beep();
    break;
   }
   font_trackLine_Slow();
  }
 }
void font_F_R_Slow()
 {
  while(1)
  {
   if(analog(crossR)>REF[5])
   {
    beep();
    break;
   }
   font_trackLine_Slow();
  }
 }
void font_LL_Slow()
 {
  while(1)
  {
   if(analog(crossL)>REF[4])
   {
    pause(TIME_PAUSE); beep();
    font_TL90_Slow();
    break;
   }
   font_trackLine_Slow();
  }
 }
void font_RR_Slow()
 {
  while(1)
  {
   if(analog(crossR)>REF[5])
   {
    pause(TIME_PAUSE); beep();
    font_TR90_Slow();
    break;
   }
   font_trackLine_Slow();
  }
 }
////////
void back_FF_L_Slow()
 {
  while(1)
  {
   if(analog(crossR)>REF[3])
   {
    beep();
    back_trackLine_Slow_time(TIME);
    break;
   }
   back_trackLine_Slow();
  }
 }
void back_FF_R_Slow()
 {
  while(1)
  {
   if(analog(crossL)>REF[2])
   {
    beep();
    back_trackLine_Slow_time(TIME);
    break;
   }
   back_trackLine_Slow();
  }
 }
void back_F_L_Slow()
 {
  while(1)
  {
   if(analog(crossR)>REF[3])
   {
    beep();
    break;
   }
   back_trackLine_Slow();
  }
 }
void back_F_R_Slow()
 {
  while(1)
  {
   if(analog(crossL)>REF[2])
   {
    beep();
    break;
   }
   back_trackLine_Slow();
  }
 }
void back_LL_Slow()
 {
  while(1)
  {
   if(analog(crossR)>REF[3])
   {
    pause(TIME_PAUSE); beep();
    back_TL90_Slow();
    break;
   }
   back_trackLine_Slow();
  }
 }
void back_RR_Slow()
 {
  while(1)
  {
   if(analog(crossL)>REF[2])
   {
    pause(TIME_PAUSE); beep();
    back_TR90_Slow();
    break;
   }
   back_trackLine_Slow();
  }
 }
//
void font_FF_Slow()
 {
  while(1)
  {
   if(analog(crossL)>REF[4] || analog(crossR)>REF[5])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   font_trackLine_Slow();
  }
 }
void back_FF_Slow()
 {
  while(1)
  {
   if(analog(crossL)>REF[2] || analog(crossR)>REF[3])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   back_trackLine_Slow();
  }
 }
void font_FF_F_Slow()
 {
  while(1)
  {
   if(analog(F_trackL)>REF[0] && analog(F_trackR)>REF[1])
   {
    //beep();
    pause(TIME_SLOW);
    break;
   }
   font_trackLine_Slow();
  }
 }
void font_FF_B_Slow()
 {
  while(1)
  {
   if(analog(B_trackL)>REF[2] && analog(B_trackR)>REF[3])
   {
    beep();
    pause(TIME_SLOW);
    break;
   }
   font_trackLine_Slow();
  }
 }
void back_FF_F_Slow()
 {
  while(1)
  {
   if(analog(B_trackL)>REF[2] && analog(B_trackR)>REF[3])
   {
    beep();
    pause(TIME_SLOW);
    break;
   }
   back_trackLine_Slow();
  }
 }
void back_FF_B_Slow()
 {
  while(1)
  {
   if(analog(F_trackL)>REF[0] && analog(F_trackR)>REF[1])
   {
    beep();
    pause(TIME_SLOW);
    break;
   }
   back_trackLine_Slow();
  }
 }
//////
void font_while_cross_Slow()
 {
  while(1)
  {
   if(analog(crossL)<REF[4] || analog(crossR)<REF[5])
   {
    beep();
    pause(TIME_SLOW);
    break;
   }
   font_FW_Slow(0);
  }
 }
void back_while_cross_Slow()
 {
  while(1)
  {
   if(analog(crossL)<REF[4] || analog(crossR)<REF[5])
   {
    beep();
    pause(TIME_SLOW);
    break;
   }
   back_FW_Slow(0);
  }
 }
void back_while_F_Slow()
 {
  while(analog(B_trackL)>REF[2] && analog(B_trackR)>REF[3])
  {
   back_FW_Slow(0);
  }
  pause(TIME_PAUSE);
 }
void font_while_F_Slow()
 {
  while(analog(F_trackL)>REF[0] && analog(F_trackR)>REF[1])
  {
   font_FW_Slow(0);
  }
  pause(TIME_PAUSE);
 }
void back_while_B_Slow()
 {
  while(analog(F_trackL)>REF[0] && analog(F_trackR)>REF[1])
  {
   back_FW_Slow(0);
  }
  pause(TIME_PAUSE);
 }
void font_while_B_Slow()
 {
  while(analog(B_trackL)>REF[2] && analog(B_trackR)>REF[3])
  {
   font_FW_Slow(0);
  }
  pause(TIME_PAUSE);
 }
//////
void font_FR_Slow()
 {
  while(1)
  {
   if(analog(crossR)>REF[5])
   {
    beep();
    font_trackLine_R_Slow_time(TIME_SLOW+TIME_SLOW);
    break;
   }
   font_trackLine_R_Slow();
  }
 }
//////
void font_FF_FF_Slow()
 {
  while(1)
  {
   if(analog(F_trackL)<REF[0] || analog(F_trackR)<REF[1])
   {
    font_FW_Slow(0);
   }
   if(analog(crossL)>REF[4] || analog(crossR)>REF[5])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   font_trackLine_Slow();
  }
 }
void back_FF_FF_Slow()
 {
  while(1)
  {
   if(analog(B_trackL)<REF[2] || analog(B_trackR)<REF[3])
   {
    back_FW_Slow(0);
   }
   if(analog(crossL)>REF[4] || analog(crossR)>REF[5])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   back_trackLine_Slow();
  }
 }
void font_FFF_FF_Slow()
 {
  while(1)
  {
   if(analog(F_trackL)<REF[0] || analog(F_trackR)<REF[1])
   {
    font_FW_Slow(0);
   }
   if(analog(crossL)>REF[4] || analog(crossR)>REF[5])
   {
    beep();
    font_trackLine_Slow_time(TIME_SLOW);
    break;
   }
   font_trackLine_Slow();
  }
 }
void back_FFF_FF_Slow()
 {
  while(1)
  {
   if(analog(B_trackL)<REF[2] || analog(B_trackR)<REF[3])
   {
    back_FW_Slow(0);
   }
   if(analog(crossL)>REF[4] || analog(crossR)>REF[5])
   {
    beep();
    back_trackLine_Slow_time(TIME_SLOW);
    break;
   }
   back_trackLine_Slow();
  }
 }














