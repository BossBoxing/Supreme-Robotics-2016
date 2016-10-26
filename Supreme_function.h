/// Supreme Function

void font_FW(unsigned int time)
 {
  motor(1,Power_Medium);
  motor(2,Power_Medium);
  motor(3,Power_Medium);
  motor(4,Power_Medium);
  delay(time);
 }
void font_BW(unsigned int time)
 {
  motor(1,-Power_Medium);
  motor(2,-Power_Medium);
  motor(3,-Power_Medium);
  motor(4,-Power_Medium);
  delay(time);
 }
 ///////
void back_FW(unsigned int time)
 {
  motor(1,-Power_Medium);
  motor(2,-Power_Medium);
  motor(3,-Power_Medium);
  motor(4,-Power_Medium);
  delay(time);
 }
void back_BW(unsigned int time)
 {
  motor(1,Power_Medium);
  motor(2,Power_Medium);
  motor(3,Power_Medium);
  motor(4,Power_Medium);
  delay(time);
 }
 ///////
///////////
void font_TL(unsigned int time)
 {
  motor(1,-Power_Medium);
  motor(2,Power_Slow);
  motor(3,-Power_Medium);
  motor(4,Power_Slow);
  delay(time);
 }
void font_TR(unsigned int time)
 {
  motor(1,Power_Slow);
  motor(2,-Power_Medium);
  motor(3,Power_Slow);
  motor(4,-Power_Medium);
  delay(time);
 }
 ///////
void back_TL(unsigned int time)
 {
  motor(1,-Power_Slow);
  motor(2,Power_Medium);
  motor(3,-Power_Slow);
  motor(4,Power_Medium);
  delay(time);
 }
void back_TR(unsigned int time)
 {
  motor(1,Power_Medium);
  motor(2,-Power_Slow);
  motor(3,Power_Medium);
  motor(4,-Power_Slow);
  delay(time);
 }
 ///////
///////////
void font_SL(unsigned int time)
 {
  motor(1,Power_track);
  motor(2,Power_Medium);
  motor(3,Power_track);
  motor(4,Power_Medium);
  delay(time);
 }
void font_SR(unsigned int time)
 {
  motor(1,Power_Medium);
  motor(2,Power_track);
  motor(3,Power_Medium);
  motor(4,Power_track);
  delay(time);
 }
 ///////
void back_SL(unsigned int time)
 {
  motor(1,-Power_Medium);
  motor(2,-Power_track);
  motor(3,-Power_Medium);
  motor(4,-Power_track);
  delay(time);
 }
void back_SR(unsigned int time)
 {
  motor(1,-Power_track);
  motor(2,-Power_Medium);
  motor(3,-Power_track);
  motor(4,-Power_Medium);
  delay(time);
 }
///////////
void back_SL_Smooth(unsigned int time)
 {
  motor(1,-Power_Medium);
  motor(2,-Power_backtrack);
  motor(3,-Power_Medium);
  motor(4,-Power_backtrack);
  delay(time);
 }
void back_SR_Smooth(unsigned int time)
 {
  motor(1,-Power_backtrack);
  motor(2,-Power_Medium);
  motor(3,-Power_backtrack);
  motor(4,-Power_Medium);
  delay(time);
 }
 ///////
///////////
void font_SL_ZickZack(unsigned int time)
 {
  motor(1,Power_ZickZack);
  motor(2,Power_Medium);
  motor(3,Power_ZickZack);
  motor(4,Power_Medium);
  delay(time);
 }
void font_SR_ZickZack(unsigned int time)
 {
  motor(1,Power_Medium);
  motor(2,Power_ZickZack);
  motor(3,Power_Medium);
  motor(4,Power_ZickZack);
  delay(time);
 }
 ///////
void back_SL_ZickZack(unsigned int time)
 {
  motor(1,-Power_Medium);
  motor(2,-Power_ZickZack);
  motor(3,-Power_Medium);
  motor(4,-Power_ZickZack);
  delay(time);
 }
void back_SR_ZickZack(unsigned int time)
 {
  motor(1,-Power_ZickZack);
  motor(2,-Power_Medium);
  motor(3,-Power_ZickZack);
  motor(4,-Power_Medium);
  delay(time);
 }
 ///////
///////////
void font_TL90()
 {
  font_TL(TIME);
  while(analog(F_trackL)>REF[0]){font_TL(0);}
  while(analog(F_trackL)<REF[0]){font_TL(0);}
  while(analog(F_trackL)>REF[0]){font_TL(0);}
  pause(TIME_PAUSE);
 }
void font_TR90()
 {
  font_TR(TIME);
  while(analog(F_trackR)>REF[1]){font_TR(0);}
  while(analog(F_trackR)<REF[1]){font_TR(0);}
  while(analog(F_trackR)>REF[1]){font_TR(0);}
  pause(TIME_PAUSE);
 }
 ///////
void back_TL90()
 {
  back_TL(TIME);
  while(analog(B_trackL)>REF[2]){back_TL(0);}
  while(analog(B_trackL)<REF[2]){back_TL(0);}
  while(analog(B_trackL)>REF[2]){back_TL(0);}
  pause(TIME_PAUSE);
 }
void back_TR90()
 {
  back_TR(TIME);
  while(analog(B_trackR)>REF[3]){back_TR(0);}
  while(analog(B_trackR)<REF[3]){back_TR(0);}
  while(analog(B_trackR)>REF[3]){back_TR(0);}
  pause(TIME_PAUSE);
 }
///////////
void font_TL_Caribate()
 {
  while(analog(B_trackL)<REF[3]){font_SL_Slow(0);}
  while(analog(B_trackL)>REF[3]){font_SL_Slow(0);}
  pause(TIME_SLOW);
 }
void font_TR_Caribate()
 {
  while(analog(B_trackL)<REF[3]){back_SR_Slow(0);}
  while(analog(B_trackL)>REF[3]){back_SR_Slow(0);}
  pause(TIME);
 }
 ///////
void back_TL_Caribate()
 {
  while(analog(F_trackL)<REF[1]){back_SL_Slow(0);}
  while(analog(F_trackL)>REF[1]){back_SL_Slow(0);}
  pause(TIME_SLOW);
 }
void back_TR_Caribate()
 {
  while(analog(F_trackL)<REF[1]){font_SR_Slow(0);}
  while(analog(F_trackL)>REF[1]){font_SR_Slow(0);}
  pause(TIME);
 }
///////////
void font_trackLine()
 {
  if(analog(F_trackL)<REF[0] && analog(F_trackR)<REF[1])
   {font_FW(0);}
  if(analog(F_trackL)>REF[0] && analog(F_trackR)>REF[1])
   {font_FW(0);}
  if(analog(F_trackL)>REF[0] && analog(F_trackR)<REF[1])
   {font_SL(0);}
  if(analog(F_trackL)<REF[0] && analog(F_trackR)>REF[1])
   {font_SR(0);}
 }
void back_trackLine()
 {
  if(analog(B_trackL)<REF[2] && analog(B_trackR)<REF[3])
   {back_FW(0);}
  if(analog(B_trackL)>REF[2] && analog(B_trackR)>REF[3])
   {back_FW(0);}
  if(analog(B_trackL)>REF[2] && analog(B_trackR)<REF[3])
   {back_SL(0);}
  if(analog(B_trackL)<REF[2] && analog(B_trackR)>REF[3])
   {back_SR(0);}
 }
void font_trackLine_Smooth()
 {
  if(analog(F_trackL)<REF[0] && analog(F_trackR)<REF[1])
   {font_FW(0);}
  if(analog(F_trackL)>REF[0] && analog(F_trackR)>REF[1])
   {font_FW(0);}
  if(analog(F_trackL)>REF[0] && analog(F_trackR)<REF[1])
   {font_SL_ZickZack(0);}
  if(analog(F_trackL)<REF[0] && analog(F_trackR)>REF[1])
   {font_SR_ZickZack(0);}
 }
void back_trackLine_Smooth()
 {
  if(analog(B_trackL)<REF[2] && analog(B_trackR)<REF[3])
   {back_FW(0);}
  if(analog(B_trackL)>REF[2] && analog(B_trackR)>REF[3])
   {back_FW(0);}
  if(analog(B_trackL)>REF[2] && analog(B_trackR)<REF[3])
   {back_SL_Smooth(0);}
  if(analog(B_trackL)<REF[2] && analog(B_trackR)>REF[3])
   {back_SR_Smooth(0);}
 }
void font_trackLine_ZickZack()
 {
  if(analog(F_trackL)<REF[0] && analog(F_trackR)<REF[1])
   {font_FW(0);}
  if(analog(F_trackL)>REF[0] && analog(F_trackR)>REF[1])
   {font_FW(0);}
  if(analog(F_trackL)>REF[0] && analog(F_trackR)<REF[1])
   {font_SL_ZickZack(0);}
  if(analog(F_trackL)<REF[0] && analog(F_trackR)>REF[1])
   {font_SR_ZickZack(0);}
 }
void back_trackLine_ZickZack()
 {
  if(analog(B_trackL)<REF[2] && analog(B_trackR)<REF[3])
   {back_FW(0);}
  if(analog(B_trackL)>REF[2] && analog(B_trackR)>REF[3])
   {back_FW(0);}
  if(analog(B_trackL)>REF[2] && analog(B_trackR)<REF[3])
   {back_SL_ZickZack(0);}
  if(analog(B_trackL)<REF[2] && analog(B_trackR)>REF[3])
   {back_SR_ZickZack(0);}
 }
//// ONE
void font_trackLine_R()
 {
  if(analog(F_trackR)<REF[1])
   {font_SL_ZickZack(0);}
  if(analog(F_trackR)>REF[1])
   {font_SR(0);}
 }
void back_trackLine_R()
 {
  if(analog(B_trackR)<REF[3])
   {back_SL_ZickZack(0);}
  if(analog(B_trackR)>REF[3])
   {back_SR(0);}
 }
void font_trackLine_L()
 {
  if(analog(F_trackL)<REF[0])
   {font_SR_ZickZack(0);}
  if(analog(F_trackL)>REF[0])
   {font_SL(0);}
 }
void back_trackLine_L()
 {
  if(analog(B_trackL)<REF[2])
   {back_SR_ZickZack(0);}
  if(analog(B_trackL)>REF[2])
   {back_SL(0);}
 }
/////// time
void font_trackLine_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   font_trackLine();
   delay(1);
   loopTime++;
  }
 }
void back_trackLine_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   back_trackLine();
   delay(1);
   loopTime++;
  }
 }
void font_trackLine_ZickZack_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   font_trackLine_ZickZack();
   delay(1);
   loopTime++;
  }
 }
void back_trackLine_ZickZack_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   back_trackLine_ZickZack();
   delay(1);
   loopTime++;
  }
 }
void font_trackLine_R_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   font_trackLine_R();
   delay(1);
   loopTime++;
  }
 }
void back_trackLine_R_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   back_trackLine_R();
   delay(1);
   loopTime++;
  }
 }
void font_trackLine_L_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   font_trackLine_L();
   delay(1);
   loopTime++;
  }
 }
void back_trackLine_L_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   back_trackLine_L();
   delay(1);
   loopTime++;
  }
 }
void back_trackLine_Smooth_time(unsigned int time)
 {
  int loopTime=0;
  while(loopTime<time)
  {   
   back_trackLine_Smooth();
   delay(1);
   loopTime++;
  }
 }
/////////
void font_FFF()
 {
  while(1)
  {
   if(analog(crossL)>REF[4] || analog(crossR)>REF[5])
   {
    beep();
    font_trackLine_time(TIME);
    break;
   }
   font_trackLine();
  }
 }
void font_FF_F()
 {
  while(1)
  {
   if(analog(F_trackL)>REF[0] && analog(F_trackR)>REF[1])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   font_trackLine();
  }
 }
void font_FF_B()
 {
  while(1)
  {
   if(analog(B_trackL)>REF[2] && analog(B_trackR)>REF[3])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   font_trackLine();
  }
 }
void font_FF_L()
 {
  while(1)
  {
   if(analog(crossL)>REF[4])
   {
    beep();
    font_trackLine_time(TIME);
    break;
   }
   font_trackLine();
  }
 }
void font_FF_R()
 {
  while(1)
  {
   if(analog(crossR)>REF[5])
   {
    beep();
    font_trackLine_time(TIME);
    break;
   }
   font_trackLine();
  }
 }
void font_LLL()
 {
  while(1)
  {
   if(analog(crossL)>REF[4])
   {
    pause(TIME_PAUSE); beep();
    font_TL90();
    font_trackLine_time(TIME);
    break;
   }
   font_trackLine();
  }
 }
void font_RRR()
 {
  while(1)
  {
   if(analog(crossR)>REF[5])
   {
    pause(TIME_PAUSE); beep();
    font_TR90();
    font_trackLine_time(TIME);
    break;
   }
   font_trackLine();
  }
 }
// font_Stop
void font_FF()
 {
  while(1)
  {
   if(analog(crossL)>REF[4] || analog(crossR)>REF[5])
   {
    pause(TIME_PAUSE);
    beep();
    break;
   }
   font_trackLine();
  }
 }
void font_F_L()
 {
  while(1)
  {
   if(analog(crossL)>REF[4])
   {
    beep();
    break;
   }
   font_trackLine();
  }
 }
void font_F_R()
 {
  while(1)
  {
   if(analog(crossR)>REF[5])
   {
    beep();
    break;
   }
   font_trackLine();
  }
 }
void font_LL()
 {
  while(1)
  {
   if(analog(crossL)>REF[4])
   {
    pause(TIME_PAUSE); beep();
    font_TL90();
    break;
   }
   font_trackLine();
  }
 }
void font_RR()
 {
  while(1)
  {
   if(analog(crossR)>REF[5])
   {
    pause(TIME_PAUSE); beep();
    font_TR90();
    break;
   }
   font_trackLine();
  }
 }
//
void font_while_cross()
 {
  while(1)
  {
   if(analog(crossL)<REF[2] && analog(crossR)<REF[3])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   font_trackLine();
  }
 }
void font_while_F()
 {
  while(analog(F_trackL)>REF[0] && analog(F_trackR)>REF[1])
  {
   font_FW(0);
  }
  pause(TIME_PAUSE);
 }
// back
void back_FFF()
 {
  while(1)
  {
   if(analog(crossL)>REF[4] || analog(crossR)>REF[5])
   {
    beep();
    back_trackLine_time(TIME);
    break;
   }
   back_trackLine();
  }
 }
void back_FF_F()
 {
  while(1)
  {
   if(analog(B_trackL)>REF[2] && analog(B_trackR)>REF[3])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   back_trackLine();
  }
 }
void back_FF_B()
 {
  while(1)
  {
   if(analog(F_trackL)>REF[0] && analog(F_trackR)>REF[1])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   back_trackLine();
  }
 }
void back_FF_L()
 {
  while(1)
  {
   if(analog(crossR)>REF[3])
   {
    beep();
    back_trackLine_time(TIME);
    break;
   }
   back_trackLine();
  }
 }
void back_FF_R()
 {
  while(1)
  {
   if(analog(crossL)>REF[2])
   {
    beep();
    back_trackLine_time(TIME);
    break;
   }
   back_trackLine();
  }
 }
void back_LLL()
 {
  while(1)
  {
   if(analog(crossR)>REF[3])
   {
    pause(TIME_PAUSE); beep();
    back_TL90();
    back_trackLine_time(TIME);
    break;
   }
   back_trackLine();
  }
 }
void back_RRR()
 {
  while(1)
  {
   if(analog(crossL)>REF[2])
   {
    pause(TIME_PAUSE); beep();
    back_TR90();
    back_trackLine_time(TIME);
    break;
   }
   back_trackLine();
  }
 }
// back_Stop
void back_FF()
 {
  while(1)
  {
   if(analog(crossL)>REF[2] || analog(crossR)>REF[3])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   back_trackLine();
  }
 }
void back_F_L()
 {
  while(1)
  {
   if(analog(crossR)>REF[3])
   {
    beep();
    break;
   }
   back_trackLine();
  }
 }
void back_F_R()
 {
  while(1)
  {
   if(analog(crossL)>REF[2])
   {
    beep();
    break;
   }
   back_trackLine();
  }
 }
void back_LL()
 {
  while(1)
  {
   if(analog(crossR)>REF[3])
   {
    pause(TIME_PAUSE); beep();
    back_TL90();
    break;
   }
   back_trackLine();
  }
 }
void back_RR()
 {
  while(1)
  {
   if(analog(crossL)>REF[2])
   {
    pause(TIME_PAUSE); beep();
    back_TR90();
    break;
   }
   back_trackLine();
  }
 }
//
void back_while_cross()
 {
  while(1)
  {
   if(analog(crossL)<REF[2] && analog(crossR)<REF[3])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   back_trackLine();
  }
 }
void back_while_cross_Smooth()
 {
  while(1)
  {
   if(analog(crossL)<REF[2] || analog(crossR)<REF[3])
   {
    beep();
    pause(TIME_SLOW);
    break;
   }
   back_trackLine_Smooth();
  }
 }
//
//// ONE
void font_FR()
 {
  while(1)
  {
   if(analog(crossR)>REF[5])
   {
    beep();
    font_trackLine_R_time(TIME);
    while(analog(F_trackR)<REF[1])
    {
      font_SL(0);
    }
    break;
   }
   font_trackLine_R();
  }
 }
void font_FL()
 {
  while(1)
  {
   if(analog(crossL)>REF[4])
   {
    beep();
    font_trackLine_L_time(TIME);
    while(analog(F_trackL)<REF[0])
    {
      font_SR(0);
    }
    break;
   }
   font_trackLine_L();
  }
 }
void back_FR()
 {
  while(1)
  {
   if(analog(crossL)>REF[4])
   {
    beep();
    back_trackLine_R_time(TIME);
    while(analog(B_trackR)<REF[3])
    {
      back_SL(0);
    }
    break;
   }
   back_trackLine_L();
  }
 }
void back_FL()
 {
  while(1)
  {
   if(analog(crossR)>REF[5])
   {
    beep();
    back_trackLine_L_time(TIME);
    while(analog(B_trackL)<REF[2])
    {
      back_SR(0);
    }
    break;
   }
   back_trackLine_L();
  }
 }
//////////
void font_FF_Smooth()
 {
  while(1)
  {
   if(analog(crossL)>REF[4] || analog(crossR)>REF[5])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   font_trackLine_Smooth();
  }
 }
void back_FF_Smooth()
 {
  while(1)
  {
   if(analog(crossL)>REF[2] || analog(crossR)>REF[3])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   back_trackLine_Smooth();
  }
 }
void back_FFF_Smooth()
 {
  while(1)
  {
   if(analog(crossL)>REF[2] || analog(crossR)>REF[3])
   {
    beep();
    back_trackLine_Smooth_time(TIME);
    break;
   }
   back_trackLine_Smooth();
  }
 }
////// Special
void font_FFF_Slow_Special()
 {
  while(1)
  {
   if(analog(crossL)>REF_Special || analog(crossR)>REF_Special)
   {
    beep();
    font_trackLine_Slow_time(TIME_SLOW);
    break;
   }
   font_trackLine_Slow();
  }
 }
void font_FF_Slow_Special()
 {
  while(1)
  {
   if(analog(crossL)>REF_Special || analog(crossR)>REF_Special)
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   font_trackLine_Slow();
  }
 }
void back_FF_Slow_Special()
 {
  while(1)
  {
   if(analog(crossL)>REF_Special || analog(crossR)>REF_Special)
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   back_trackLine_Slow();
  }
 }
void back_while_cross_Special()
 {
  while(1)
  {
   if(analog(crossL)<REF_Special || analog(crossR)<REF_Special)
   {
    beep();
    pause(TIME);
    break;
   }
   back_FW(0);
  }
 }
void back_TL90_Special()
 {
  back_TL(TIME);
  while(analog(B_trackL)>REF[2]){back_TL(0);}
  while(analog(B_trackL)<REF[2]){back_TL(0);}
  pause(TIME_PAUSE);
 }
///
void font_F_Slow_Special()
 {
  while(1)
  {
   if(analog(crossL)>REF_Special || analog(crossR)>REF_Special)
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   font_FW_Slow(0);
  }
 }
void back_FF_FF_Slow_Special()
 {
  while(1)
  {
   if(analog(B_trackL)<REF_Special || analog(B_trackR)<REF_Special)
   {
    back_FW_Slow(0);
   }
   if(analog(crossL)>REF_Special || analog(crossR)>REF_Special)
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   back_trackLine_Slow();
  }
 }
void font_FFF_FF_Slow_Special()
 {
  while(1)
  {
   if(analog(F_trackL)<REF_Special || analog(F_trackR)<REF_Special)
   {
    font_FW_Slow(0);
   }
   if(analog(crossL)>REF_Special || analog(crossR)>REF_Special)
   {
    beep();
    font_trackLine_Slow_time(TIME_SLOW);
    break;
   }
   font_trackLine_Slow();
  }
 }
void back_FFF_FF_Slow_Special()
 {
  while(1)
  {
   if(analog(B_trackL)<REF_Special || analog(B_trackR)<REF_Special)
   {
    back_FW_Slow(0);
   }
   if(analog(crossL)>REF_Special || analog(crossR)>REF_Special)
   {
    beep();
    back_trackLine_Slow_time(TIME_SLOW);
    break;
   }
   back_trackLine_Slow();
  }
 }
///// Sapan
void font_FF_Sapan()
 {
  while(1)
  {
   if(analog(crossL)>REF[4] || analog(crossR)>REF[5])
   {
    beep();
    font_trackLine_time(TIME_SLOW);
    pause(TIME_PAUSE);
    break;
   }
   font_trackLine();
  }
 }
void back_FF_Sapan()
 {
  while(1)
  {
   if(analog(crossL)>REF[2] || analog(crossR)>REF[3])
   {
    beep();
    back_trackLine_Slow_time(TIME_SLOW);
    pause(TIME_PAUSE);
    break;
   }
   back_trackLine();
  }
 }
void font_FF_Slow_Sapan()
 {
  while(1)
  {
   if(analog(crossL)>REF[4] || analog(crossR)>REF[5])
   {
    beep();
    font_trackLine_Slow_time(TIME);
    pause(TIME_PAUSE);
    break;
   }
   font_trackLine_Slow();
  }
 }
void back_FF_Slow_Sapan()
 {
  while(1)
  {
   if(analog(crossL)>REF[2] || analog(crossR)>REF[3])
   {
    beep();
    back_trackLine_Slow_time(TIME);
    pause(TIME_PAUSE);
    break;
   }
   back_trackLine_Slow();
  }
 }
/////
/// Servo Function
void font_sKeep()
 {
  servo(1,servo1_keep);
 }
void back_sKeep()
 {
  servo(2,servo2_keep);
 }
void font_sKind()
 {
  servo(1,servo1_set);
 }
void back_sKind()
 {
  servo(2,servo2_set);
 }
void font_sCaribate()
 {
  servo(1,servo1_kind);
 }
void back_sCaribate()
 {
  servo(2,servo2_kind);
 }
void font_sBump()
 {
  servo(1,servo1_bump);delay(100);
 }
void back_sBump()
 {
  servo(2,servo2_bump);delay(100);
 }
void font_sfloor1()
 {
  servo(4,servo4_floor1);
 }
void back_sfloor1()
 {
  servo(3,servo3_floor1);
 }
void font_sfloor1_Special()
 {
  servo(4,(servo4_floor1-20));delay(500);
 }
void back_sfloor1_Special()
 {
  servo(3,(servo3_floor1-20));delay(500);
 }
void font_sfloor1_Special_2()
 {
  servo(4,(servo4_floor1-45));delay(500);
 }
void back_sfloor1_Special_2()
 {
  servo(3,(servo3_floor1-35));delay(500);
 }
void font_sfloor2()
 {
  servo(4,servo4_floor2);
 }
void back_sfloor2()
 {
  servo(3,servo3_floor2);
 }
void font_sfloor2_Special()
 {
  servo(4,(servo4_floor2-35));
 }
void back_sfloor2_Special()
 {
  servo(3,(servo3_floor2-35));
 }
void font_sfloor2_Special_2()
 {
  servo(4,(servo4_floor2-45));
 }
void back_sfloor2_Special_2()
 {
  servo(3,(servo3_floor2-45));
 }
void font_sfloor3()
 {
  servo(4,servo4_floor3);
 }
void back_sfloor3()
 {
  servo(3,servo3_floor3);
 }
void Set()
 {
  font_sfloor1();
  back_sfloor1();
  font_sKind();
  back_sKind();
  delay(500);
 }
void hand_Set()
 {
  font_sKind();
  back_sKind();
  delay(100);
 }

void font_Keep1_Check1()
 {
  font_sfloor1();delay(300);
  font_sKeep();delay(500);
 }
void back_Keep1_Check1()
 {
  back_sfloor1();delay(300);
  back_sKeep();delay(500);
 }
void font_Keep1_Check2()
 {
  font_sfloor2_Special();delay(500); 
 }
void back_Keep1_Check2()
 {
  back_sfloor2_Special();delay(500);
 }
void font_Keep1()
 {
  font_sfloor1();delay(300);
  font_sKeep();delay(500);
  font_sfloor2_Special();delay(500);
 }
void back_Keep1()
 {
  back_sfloor1();delay(300);
  back_sKeep();delay(500);
  back_sfloor2_Special();delay(500);
 }
void font_Keep2()
 {
  font_sfloor2();delay(300);
  font_sKeep(); delay(300);
  font_sfloor2_Special(); delay(500);
 }
void back_Keep2()
 {
  back_sfloor2();delay(300);
  back_sKeep(); delay(300);
  back_sfloor2_Special();delay(500);
 }
void font_place1_Special()
 {
  font_sfloor1_Special();delay(200);
  font_sCaribate();delay(200);
  font_sKind();delay(100);
  font_sfloor2();delay(200);
 } 
void back_place1_Special()
 {
  back_sfloor1_Special();delay(200);
  back_sCaribate();delay(200);
  back_sKind();delay(100);
  back_sfloor2();delay(200);
 } 
void font_Keep2_Special()
 {
  font_sfloor2_Special();delay(200);
  font_sKeep(); delay(200);
  font_sfloor2_Special_2(); delay(500);
 }
void back_Keep2_Special()
 {
  back_sfloor2_Special();delay(200);
  back_sKeep(); delay(200);
  back_sfloor2_Special_2();delay(500);
 }
void font_place1()
 {
  font_sfloor1();delay(400);
  font_sCaribate();delay(300);
  font_sKind();delay(100);
  font_sfloor2();delay(200);
 } 
void back_place1()
 {
  back_sfloor1();delay(400);
  back_sCaribate();delay(300);
  back_sKind();delay(100);
  back_sfloor2();delay(200);
 } 
void font_place2()
 {
  pause(TIME);
  font_sfloor2();delay(200);
  font_sCaribate();delay(300);
  font_sKind();delay(100);
 }
void back_place2()
 {
  pause(TIME);
  back_sfloor2();delay(200);
  back_sCaribate();delay(300);
  back_sKind();delay(100);
 }
void font_place1_Special_2()
 {
  back_while_cross_Slow();
  back_FW(TIME_DELAY);pause(TIME_PAUSE);
  font_sfloor1_Special_2();delay(300);
  font_FW(TIME_SLOW);pause(TIME_PAUSE);
  font_place1();
  //font_FW_Slow(TIME_SLOW);pause(TIME_PAUSE);
  font_sKeep();delay(300);
  font_FW(TIME);
  font_sKind();
  back_FW(TIME_ZZ);pause(TIME_PAUSE);
  font_sBump();
  font_FW(TIMERE_ZZ-200);pause(TIME_PAUSE);
  beep();
 }
void font_place2_Caribate()
 {
  pause(TIME);
  font_sfloor2();delay(200);
  font_sCaribate();delay(400);
  font_sKind();delay(300);
 }
void back_place2_Caribate()
 {
  pause(TIME);
  back_sfloor2();delay(200);
  back_sCaribate();delay(400);
  back_sKind();delay(300);
 }

void Rescue_place1_F()
 {
  while(1)
  {
   if(Box_Dead==0)
   {
    font_FF_F_Slow();
    font_while_F_Slow();
    font_place1(); 
    font_Keep2();
    back_FF_Slow();
    font_sfloor1_Special();
    font_while_cross_Slow();
    font_place1();
    Box_Dead+=2;
    break;
   }
   if(Box_Dead==1)
   {
    font_sfloor1_Special();
    font_FF_F_Slow();
    //back_FF_Slow();
    //font_sfloor1_Special();
    //font_while_cross_Slow();
    font_place1();
    font_Keep2();
    back_while_F_Slow();
    font_TR_Caribate();
    font_place2_Caribate();
    font_TL_Caribate();
    Box_Dead+=2;
    break;
   }
   if(Box_Dead>=3)
   {
    font_FF_F_Slow();
    back_while_F_Slow();
    font_TR_Caribate();
    font_place2_Caribate();
    font_TL_Caribate();
    Box_Dead+=2;
    break;
   }
  }
 }
void Rescue_place1_Keep2_F()
 {
  while(1)
  {
   if(Box_Dead==0)
   {
    font_FF_F_Slow();
    font_while_F_Slow();
    font_place1(); 
    font_Keep2();
    Box_Dead++;
    break;
   }
   if(Box_Dead==1)
   {
    font_sfloor1_Special();
    font_FF_F_Slow();
    //back_FF_Slow();
    //font_sfloor1_Special();
    //font_while_cross_Slow();
    font_place1();
    font_Keep2();
    Box_Dead++;
    break;
   }
   if(Box_Dead==2)
   {
    font_FF_F_Slow();
    back_while_F_Slow();
    font_TR_Caribate();
    font_place2_Caribate();
    font_TL_Caribate();
    Box_Dead++;
    break;
   }
   if(Box_Dead>=3)
   {
    font_FF_F_Slow();
    back_while_F_Slow();
    font_TR_Caribate();
    font_place2_Caribate();
    font_TL_Caribate();
    Box_Dead++;
    break;
   }
  }
 }
void Rescue_place1_B()
 {
  while(1)
  {
   if(Box_Dead==0)
   {
    back_FF_F_Slow();
    back_while_F_Slow();
    back_place1(); 
    back_Keep2();
    font_FF_Slow();
    back_sfloor1_Special();
    back_while_cross_Slow();
    back_place1();
    Box_Dead+=2;
    break;
   }
   if(Box_Dead==1)
   {
    back_sfloor1_Special();
    back_FF_F_Slow();
    //font_FF_Slow();
    //back_sfloor1_Special();
    //back_while_cross_Slow();
    back_place1();
    back_Keep2();
    font_while_F_Slow();
    back_TR_Caribate();
    back_place2_Caribate();
    back_TL_Caribate();
    Box_Dead+=2;
    break;
   }
   if(Box_Dead>=3)
   {
    back_FF_F_Slow();
    font_while_F_Slow();
    back_TR_Caribate();
    back_place2_Caribate();
    back_TL_Caribate();
    Box_Dead+=2;
    break;
   }
  }
 }
void Rescue_place1_Keep2_B()
 {
  while(1)
  {
   if(Box_Dead==0)
   {
    back_FF_F_Slow();
    back_while_F_Slow();
    back_place1(); 
    back_Keep2();
    Box_Dead++;
    break;
   }
   if(Box_Dead==1)
   {
    back_sfloor1_Special();
    back_FF_F_Slow();
    //font_FF_Slow();
    //back_sfloor1_Special();
    //back_while_cross_Slow();
    back_place1();
    back_Keep2();
    Box_Dead++;
    break;
   }
   if(Box_Dead==2)
   {
    back_FF_F_Slow();
    font_while_F_Slow();
    back_TR_Caribate();
    back_place2_Caribate();
    back_TL_Caribate();
    Box_Dead++;
    break;
   }
   if(Box_Dead>=3)
   {
    back_FF_F_Slow();
    font_while_F_Slow();
    back_TR_Caribate();
    back_place2_Caribate();
    back_TL_Caribate();
    Box_Dead++;
    break;
   }
  }
 }

////// Distance
void font_find()
 {
  while(getdist(font_dist)>font_refDist)
  {
   font_trackLine_Slow();
  }
  pause(TIME_PAUSE);
 }
void back_find()
 {
  while(getdist(back_dist)>back_refDist)
  {
   back_trackLine_Slow();
  }
  pause(TIME_PAUSE);
 }
void font_find_FW_Slow()
 {
  while(getdist(font_dist)>font_refDist)
  {
   font_FW_Slow(0);
  }
  pause(TIME_PAUSE);
 }

/// Supreme Compass
/////// Varible Compass
 #define kp 0
 #define ki 0
 #define kd 0
 int pre_error=0;
 int error;

int calPID(int setpoint)
 {
  //int setpoint;
  //int curent = cmps11_read();
  //int curent = compass_read(); compass_read_heading()
  int curent = compass_read();
      error = setpoint - curent;
  //int error = setpoint - curent;
  int p = kp*error;
  int i = i + error;
  int d = error - pre_error;
  int pid = p+i+d;
      pre_error = error;
  return(pid); //return(error);
 }
void cmp_motor(int setpoint,int powMAX)
 {
  int pwLeft = powMAX+calPID(setpoint);
  int pwRight = powMAX-calPID(setpoint);
  if(pwLeft > powMAX){pwLeft = powMAX;}
  if(pwLeft < -powMAX){pwLeft = -powMAX;}
  if(pwRight > powMAX){pwRight = powMAX;}
  if(pwRight < -powMAX){pwRight = -powMAX;}
  motor(1,pwLeft);
  motor(2,pwRight);
 }
void Go_SET()
 {
  angle=compass_read();
  glcd(4,1,"set:%d  ",angle);
  beep();
 }
void Go_Compass_B()
 {
  while(1)
  {
   if(analog(B_trackL)>REF[2] && analog(B_trackR)>REF[3])
   {
    beep();
    pause(TIME_PAUSE);
    break;
   }
   while(1){cmp_motor(angle,Power_Medium);} 
  }
 }

/////// Check_Magnetic
void Check_Magnetic_a_F()
 {
  while(1)
  {
   if(analog(6)<refA6_mag-diff || analog(6)>refA6_mag+diff){F++; a=1;break;}
   if(analog(6)>refA6_mag-diff && analog(6)<refA6_mag+diff){a=0;break;}
  }
  glcd(3,1," %d ",a);
  pause(200);
 }
void Check_Magnetic_b_F()
 {
  while(1)
  {
   if(analog(6)<refA6_mag-diff || analog(6)>refA6_mag+diff){F++; b=1;break;}
   if(analog(6)>refA6_mag-diff && analog(6)<refA6_mag+diff){b=0;break;}
  }
  glcd(4,1," %d ",b);
  pause(200);
 }
void Check_Magnetic_c_F()
 {
  while(1)
  {
   if(analog(6)<refA6_mag-diff || analog(6)>refA6_mag+diff){F++; c=1;break;}
   if(analog(6)>refA6_mag-diff && analog(6)<refA6_mag+diff){c=0;break;}
  }
  glcd(3,6," %d ",c);
  pause(200);
 }
void Check_Magnetic_d_F()
 {
  while(1)
  {
   if(analog(6)<refA6_mag-diff || analog(6)>refA6_mag+diff){F++; d=1;break;}
   if(analog(6)>refA6_mag-diff && analog(6)<refA6_mag+diff){d=0;break;}
  }
  glcd(4,6," %d ",d);
  pause(200);
 }
///////
void Check_Magnetic_a_B()
 {
  while(1)
  {
   if(analog(7)<refA7_mag-diff || analog(7)>refA7_mag+diff){B++; a=1;break;}
   if(analog(7)>refA7_mag-diff && analog(7)<refA7_mag+diff){a=0;break;}
  }
  glcd(3,1," %d ",a);
  pause(200);
 }
void Check_Magnetic_b_B()
 {
  while(1)
  {
   if(analog(7)<refA7_mag-diff || analog(7)>refA7_mag+diff){B++; b=1;break;}
   if(analog(7)>refA7_mag-diff && analog(7)<refA7_mag+diff){b=0;break;}
  }
  glcd(4,1," %d ",b);
  pause(200);
 }
void Check_Magnetic_c_B()
 {
  while(1)
  {
   if(analog(7)<refA7_mag-diff || analog(7)>refA7_mag+diff){B++; c=1;break;}
   if(analog(7)>refA7_mag-diff && analog(7)<refA7_mag+diff){c=0;break;}
  }
  glcd(3,6," %d ",c);
  pause(200);
 }
void Check_Magnetic_d_B()
 {
  while(1)
  {
   if(analog(7)<refA7_mag-diff || analog(7)>refA7_mag+diff){B++; d=1;break;}
   if(analog(7)>refA7_mag-diff && analog(7)<refA7_mag+diff){d=0;break;}
  }
  glcd(4,6," %d ",d);
  pause(200);
 }

