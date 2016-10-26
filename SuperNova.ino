/// Supreme Robotics 2016 The KDisaster Rescue Robot 
#include <ATX2.h>
#include <compass.h>
#include <ATX2_gp2d120.h>
///// Variable
#define SW_START 18 // Switch 
#define SW_FONT 2 // บนหน้า
#define SW_BACK 3 // บนหลัง
int function;
int angle;
///////////
int Power_Medium = 100; // PowerMedium
int Power_Slow = 60; // PowerSlow
int Power_track_Slow = 0; // PowerSlow
int Power_Slowly = 30; // PowerSlowly
int Power_track = 30; // PowerMedium
int Power_backtrack = 40; // PowerMedium
int Power_ZickZack = 60; // PowerMedium
int Power_ZickZack_Slow = 40; // PowerMedium
///////////
int REF[8] = {
    520, // A0
    520, // A1
    520, // A2
    520, // A3
    350, // A4
    350, // A5
    350, // A6
    350 // A7
   };
int REF_Special = 720; 
int refA6_mag = 509;
int refA7_mag = 512;
int diff = 2;
int font_refDist = 8;
int back_refDist = 7;
///////////
int a=0,b=0,c=0,d=0;
int F=0,B=0;
int Cost;
int Box_Special=0;
int Box_Dead=0;
int BAGS = 0;
///////////
int TIME=180; // TIME แทร็ก
int TIME_ZZ=500; // TIME แท็ก ZickZack
int TIMERE_ZZ=500; // TIME แท็ก ZickZack
int TIME_PAUSE=50; // หยุดแต่ละจุด
int TIME_SLOW=100; // หยุด เข้าออกกล่อง
int TIME_DELAY = 350;
int TIME_SAPAN = 800;
// servo veriable
 int servo1_keep = 130; // 94
 int servo1_kind = 86;
 int servo1_set = 56;
 int servo1_bump = 103;
 int servo2_keep = 40; // 52
 int servo2_kind = 72;
 int servo2_set = 118; 
 int servo2_bump = 46;
 int servo3_floor1 = 139;
 int servo3_floor2 = 60;
 int servo3_floor3 = 23;
 int servo4_floor1 = 173;
 int servo4_floor2 = 94;
 int servo4_floor3 = 28;
 int servo4_floor1_3cm = 173;
 int servo4_floor2_3cm = 118;
 int servo4_floor3_3cm = 28;
#include <ATX2_menu.h>

#define F_trackL 0
#define F_trackR 1
#define crossL 4
#define crossR 5
#define B_trackL 2
#define B_trackR 3
////////
#define font_dist 8 // 8
#define back_dist 9 // 9
///////////////
///// STOP
void pause(unsigned int time)
 {
  motor_stop(ALL);
  delay(time);
 }
void Wait()
 {
  while(in(SW_START)==1){pause(0);}
  while(in(SW_START)==0){pause(0);}
 }
#include <Supreme_function_Slow.h>
#include <Supreme_function.h>
/////////////// Algorithm
void part_start()
 {
  while(analog(crossR)>REF[5]){font_FW(0);}
  font_RRR();
  font_FF_L();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FL();
  font_FL();
  font_FL();
  font_FL();
  font_LLL();
  font_FFF();
  font_FFF();
  font_FF();
  //Wait();
 }
void part2_start()
 {
  while(analog(crossR)>REF[5]){font_FW(0);}
  font_RRR();
  font_FF_L();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_LLL();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_RRR();
  font_FFF();
  //Wait();
 }
/////
void goto_sapan_start()
 {
  while(analog(crossR)>REF[5]){font_FW(0);}
  font_RRR();
  font_FF_L();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_LL();
 }
void goto_sapan()
 {
  font_FF_F();
  font_FFF();
  font_FFF();
  font_FFF();
  font_LLL();
  font_FFF();
  font_LL();
 }
void goto_sapanR()
 {
  back_LLL();
  back_FFF();
  back_FFF();
  back_LL();
  back_FF_F();
 }
/////
void goto_RescueZone1()
 {
  Set();
  font_RRR();
  font_FFF();
  font_FFF();
  font_FF();
 }
void Rescue_Zone1()
 {
  font_FF_F_Slow();
  back_FF_F();
  back_while_F_Slow();
  font_Keep1();
  Check_Magnetic_a_F();
  glcd(3,1,"A:%d",a);beep();
  back_FF();
  font_TL90(); font_FF_F();
  font_RR();
  font_FF_F_Slow();
  back_FF_F();
  back_while_F_Slow(); pause(300);
  font_place2();
  font_Keep1();
  Check_Magnetic_b_F();
  glcd(4,1,"B:%d",b);beep();
 }
void goto_RescueZone2()
 {
  font_FF_F();
  font_FFF();
  font_FF();
  back_TL90(); back_FF_F();
  back_FFF();
  back_FFF_Smooth();
  back_FFF_Smooth();
  back_FFF_Smooth();
 }
void Rescue_Zone2()
 {
  back_FF_Smooth();
  //font_while_cross_Slow();
  back_Keep1();
  Check_Magnetic_c_B();
  glcd(5,1,"C:%d",c);beep();
  font_FF_F();
  font_RRR();
  font_FF();
  back_TL90();
  back_FF_F();
  back_FF_Slow();
  //font_while_cross_Slow();
  back_place2();
  back_Keep1();
  Check_Magnetic_d_B();
  glcd(6,1,"D:%d",d);beep();
 }
void goto_Rescue1()
 {
  while(analog(F_trackL)>REF[0]){font_TL(0);}
  while(analog(F_trackL)<REF[0]){font_TL(0);}
  font_trackLine_R_time(TIME);
  font_FR(); font_FR();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_RRR();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FF();pause(TIME);
 }
void Rescue_Zone3()
 {
  back_FF_F();
  back_FFF_Smooth();
  back_FFF_Smooth();
  back_FFF_Smooth();
  back_FF_Smooth();
  font_while_cross_Slow();
  back_Keep1();
  Check_Magnetic_a_B();
  font_FF_F();
  font_FF();
  back_TL90(); back_FF_F();
  back_RR();
  back_FF_F();
  back_FF();
  font_while_cross_Slow();
  back_place2(); back_Keep1();
  Check_Magnetic_b_B();
 }
void Rescue_Zone4()
 {
  font_FF_F();
  font_FFF();
  font_RRR();
  font_FF();
  font_FF_B();
  back_FF_F();
  back_while_F_Slow();
  font_Keep1();
  Check_Magnetic_c_F();
  back_FF();
  font_TL90(); font_FF_F();
  font_RR();
  font_FF_F_Slow();
  back_FF_F();
  back_while_F_Slow();
  font_place2();
  font_Keep1();
  Check_Magnetic_d_F();
 }
void goto_Rescue2()
 {
  back_FFF_Smooth();
  back_FFF_Smooth();
  back_FF_Smooth();
  font_TL90(); font_FF_F();
  font_FF();pause(TIME);
 }
void Rescue()
 {
  if(a==1 && b==1 && c==1 && d==1)
  {
   BOX_F();
   BOX_B();
  }
  if(a==1 && b==1 && c==1 && d==0)
  {
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_reDeathZone();
   BOX_F();
   BOX_B();
  }
  if(a==1 && b==1 && c==0 && d==1)
  {
   BOX_B();
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_reDeathZone();
   BOX_F();
  }
  if(a==1 && b==1 && c==0 && d==0)
  {
   back_DeathZone();
   Rescue_place1_B();
   back_reDeathZone();
   BOX_F();
  }
  if(a==1 && b==0 && c==1 && d==1)
  {
   font_DeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
   BOX_F();
   BOX_B();
  }
  if(a==1 && b==0 && c==1 && d==0)
  {
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_uturnDeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
   BOX_Special_F(); //
   BOX_B();
  }
  if(a==1 && b==0 && c==0 && d==1)
  {
   BOX_Special_B();
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_uturnDeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
   BOX_F();
  }
  if(a==1 && b==0 && c==0 && d==0)
  {
   font_DeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
   BOX_Special_F();
   back_DeathZone();
   Rescue_place1_B();
   back_reDeathZone();
  }
  if(a==0 && b==1 && c==1 && d==1)
  {
   BOX_Special_F();
   font_DeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
   BOX_B();
  }
  if(a==0 && b==1 && c==1 && d==0)
  {
   BOX_Special_F();
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_uturnDeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
   BOX_B();
  }
  if(a==0 && b==1 && c==0 && d==1)
  {
   BOX_Special_F();
   BOX_B();
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_uturnDeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
  }
  if(a==0 && b==1 && c==0 && d==0)
  {
   BOX_Special_F();
   back_DeathZone();
   Rescue_place1_B();
   back_uturnDeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
  } 
  if(a==0 && b==0 && c==1 && d==1)
  {
   BOX_Special_B();
   BOX_B();
   font_DeathZone();
   Rescue_place1_F();
   font_reDeathZone();
  }
  if(a==0 && b==0 && c==1 && d==0)
  {
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_reDeathZone();
   BOX_Special_B();
   font_DeathZone();
   Rescue_place1_F();
   font_reDeathZone();
  }  
  if(a==0 && b==0 && c==0 && d==1)
  {
   BOX_Special_B();
   font_DeathZone();
   Rescue_place1_F();
   font_uturnDeathZone();
   Rescue_place1_Keep2_B();
   back_reDeathZone();
  }  
  if(a==0 && b==0 && c==0 && d==0)
  {
    beep();beep();beep();beep();
  }
  hand_Set();
 }
void Rescue2()
 {
  if(a==1 && b==1 && c==1 && d==1)
  {
   BOX_F();
   BOX_B();
  }
  if(a==1 && b==1 && c==1 && d==0)
  {
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_reDeathZone();
   BOX_F();
   BOX_B();
  }
  if(a==1 && b==1 && c==0 && d==1)
  {
   BOX_B();
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_reDeathZone();
   BOX_F();
  }
  if(a==1 && b==1 && c==0 && d==0)
  {
   back_DeathZone();
   Rescue_place1_B();
   back_reDeathZone();
   BOX_F();
  }
  if(a==1 && b==0 && c==1 && d==1)
  {
   font_DeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
   BOX_F();
   BOX_B();
  }
  if(a==1 && b==0 && c==1 && d==0)
  {
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_uturnDeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
   BOX_Special_F(); //
   BOX_B();
  }
  if(a==1 && b==0 && c==0 && d==1)
  {
   BOX_Special_B();
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_uturnDeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
   BOX_F();
  }
  if(a==1 && b==0 && c==0 && d==0)
  {
   font_DeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
   BOX_Special_F();
   back_DeathZone();
   Rescue_place1_B();
   back_reDeathZone();
  }
  if(a==0 && b==1 && c==1 && d==1)
  {
   BOX_Special_F();
   font_DeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
   BOX_B();
  }
  if(a==0 && b==1 && c==1 && d==0)
  {
   BOX_Special_F();
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_uturnDeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
   BOX_B();
  }
  if(a==0 && b==1 && c==0 && d==1)
  {
   BOX_Special_F();
   BOX_B();
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_uturnDeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
  }
  if(a==0 && b==1 && c==0 && d==0)
  {
   BOX_Special_F();
   back_DeathZone();
   Rescue_place1_B();
   back_uturnDeathZone();
   Rescue_place1_Keep2_F();
   font_reDeathZone();
  } 
  if(a==0 && b==0 && c==1 && d==1)
  {
   BOX_Special_B();
   BOX_B();
   font_DeathZone();
   Rescue_place1_F();
   font_reDeathZone();
  }
  if(a==0 && b==0 && c==1 && d==0)
  {
   back_DeathZone();
   Rescue_place1_Keep2_B();
   back_reDeathZone();
   BOX_Special_B();
   font_DeathZone();
   Rescue_place1_F();
   font_reDeathZone();
  }  
  if(a==0 && b==0 && c==0 && d==1)
  {
   BOX_Special_B();
   font_DeathZone();
   Rescue_place1_F();
   font_uturnDeathZone();
   Rescue_place1_Keep2_B();
   back_reDeathZone();
  }  
  if(a==0 && b==0 && c==0 && d==0)
  {
    beep();beep();beep();beep();
  }
  Set();
 }
////////// วางทีละกล่อง && เรียง 3
void place_bags1()
 {
  font_FFF();
  font_FF_B_Slow();
  back_while_F_Slow();
  font_place1(); font_Keep2();
  back_while_cross_Slow();
  font_place1(); font_Keep2(); 
  back_while_B_Slow();
  font_place1(); font_Keep2();
 }
void place_bags2()
 {
  back_RRR();
  back_RR();
  back_FF_F();
  back_FF();
  back_FF_B_Slow();
  font_while_F_Slow();
  back_place1(); back_Keep2();
  font_while_cross_Slow();
  back_place1(); back_Keep2(); 
  font_while_B_Slow();
  back_place1(); back_Keep2();
 }
void place2_bags1()
 {
  font_FFF();
  font_FF_Slow_Special();
  back_FW(TIME);pause(TIME_PAUSE);
  font_place1();
  back_while_cross_Slow();
  back_TL90_Special();
  font_TL90();
  font_while_cross_Slow();
  back_place1();
  //back_while_B_Slow();
  //font_place1(); font_Keep2();
 }
void place2_bags2()
 {
  back_RRR();
  back_RR();
  back_FF_F();
  back_FF();
  back_FF_B_Slow();
  font_while_F_Slow();
  back_place1(); back_Keep2();
  font_while_cross_Slow();
  back_place1(); back_Keep2(); 
  font_while_B_Slow();
  back_place1(); back_Keep2();
 }
////////// คีบทีละอัน กับ 3 เรียง
void goto_bags()
 {
  Up_Rescue_Sapan();
  font_RRR();
  Down_Bags_Sapan();
 }
void keep_bags1()
 {
  font_FF_F();
  font_RR_Slow();
  font_FF_F_Slow();
  back_FF_B_Slow();
  font_find();Wait();
  font_Keep1();
  font_find();
  font_place2();
  font_Keep1();
  font_find();
  font_place2();
  font_Keep1();
 }
void keep_bags2()
 {
  back_while_F_Slow();
  back_FF_F();
  back_RRR();
  back_RR();
  back_FF_F_Slow();
  font_FF_B_Slow();
  back_find();
  back_Keep1();
  back_find();
  back_place2();
  back_Keep1();
  back_find();
  back_place2();
  back_Keep1();
 }
void keep2_bags1()
 {
  font_FF_F();
  font_RR();
  font_FF_F_Slow();
  back_FF_B_Slow();
  font_find(); //Wait();
  font_Keep1();
 }
void keep2_bags2()
 {
  back_while_F_Slow();
  back_FF_F();
  back_RRR();
  back_RR();
  back_FF_F_Slow();
  font_FF_B_Slow();
  back_find();
  back_Keep1();
 }
void keep3_bags1()
 {
  font_FF_F();
  font_RR();
  font_FF_F_Slow();
  back_FF_B_Slow();
  font_find(); //Wait();
  font_Keep2();
 }
void keep3_bags2()
 {
  back_while_F_Slow();
  back_FF_F();
  back_RRR();
  back_RR();
  back_FF_F_Slow();
  font_FF_B_Slow();
  back_find();
  back_Keep1();
 }
///// วางถุงยางชีพ

void placebox_bags()
 {
  if(BAGS==0)
  {
   placebox_L_bags1();
   placebox_L_bags2();
  }
  else
  {
   placebox_R_bags1();
   placebox_R_bags2();
  }
 }
void placebox_L_bags1()
 {
  ///////// Start
  font_while_F_Slow();
  font_FF_F();
  font_FFF();
  font_FFF();
  font_LLL();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FF();
  back_TL90();
  ///////// 1
  back_FF_F_Slow();
  back_place1_Special();
  back_Keep2_Special();
  ///////// 2
  font_FF();
  back_TR90();
  back_FF_F();
  back_LL();
  back_FF_F_Slow();
  back_place1_Special();
  back_Keep2_Special();
  ///////// 3
  font_FF();
  back_TR90();
  back_FF_F();
  back_LL();
  back_FF_F_Slow();
  back_place1_Special();
  back_Keep2_Special();
  ///////// Finish
 }
void placebox_L_bags2()
 {
  ////////// 1
  font_LLL();
  font_LL();
  font_FF_F_Slow();
  font_place1_Special();
  font_Keep2_Special();
  ///////// 2
  back_FF();
  font_TR90();
  font_FF_F();
  font_LL();
  font_FF_F_Slow();
  font_place1_Special();
  font_Keep2_Special();
  ///////// FINSH
 }
void placebox_R_bags1()
 {
  ///////// Start
  font_while_F_Slow();
  font_FF_F();
  font_FF();
  back_TL90();
  back_TL90();
  back_FF_F();
  back_FFF();
  back_FF();
  ///////// 1
  back_FF_F();
  back_place1_Special();
  back_Keep2_Special();
  ///////// 2
  font_FF();
  back_TL90();
  back_FF_F();
  back_RR();
  back_FF_F_Slow();
  back_place1_Special();
  back_Keep2_Special();
  ///////// 3
  font_FF();
  back_TL90();
  back_FF_F();
  back_RR();
  back_FF_F_Slow();
  back_place1_Special();
  back_Keep2_Special();
  ///////// Finish
 }
void placebox_R_bags2()
 {
  ////////// 1
  font_RRR();
  font_RR();
  font_FF_F_Slow();
  font_place1_Special();
  font_Keep2_Special();
  ///////// 2
  back_FF();
  font_TL90();
  font_FF_F();
  font_RR();
  font_FF_F_Slow();
  font_place1_Special();
  font_Keep2_Special();
  ///////// FINSH
 }
////////// SAPAN
void goto_Rescue_sapan()
 {
  back_FF_F();
  back_FFF();
  back_FFF();
  back_FFF();
  back_FF();
  font_TR90();
  font_FF_F();
  font_FFF();
  font_FFF();
  font_FFF();
  font_LL();
 }
void Up_Rescue_Sapan()
 {
  font_FF_F();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
 }
void Up_Bags_Sapan()
 {
  font_FFF();
  font_FFF();
 }
void Down_Rescue_Sapan()
 {

 }
void Down_Bags_Sapan()
 {
  font_FFF();
  font_FFF();
  font_FF();
 }
////////////
void goto_sapanL_start() ////
 {
  while(analog(crossR)>REF[5]){font_FW(0);}
  font_RRR();
  font_FF_L();
  font_FFF();
  font_FFF();
  font_FF();
  back_TR90();
  back_FF_B();
  back_FFF();
  back_FFF();
  back_FFF();
  back_FFF();
  back_FF();
  //font_sfloor2_Special();
  font_sapanL();
 }
void sapanL_goto_sapanR()
 {
  font_FF_F();
  font_FFF();
  font_FFF();
  font_FFF();
  font_LLL();
  font_FFF();
  font_FFF();
  font_FFF();
  font_LLL();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_LL();
  font_sapanR();
  font_TL90();
  font_FF_F();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_RRR();
  font_FFF();
  font_RR();
 }
void goto_sapanR_start()
 {
  while(analog(crossR)>REF[5]){font_FW(0);}
  font_RRR();
  font_FF_L();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_LLL();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_LL();
  font_sapanR();
  font_TL90();
  font_FF_F();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_RRR();
  font_FFF();
  font_RR();
 }
 ///////
void push_sapanL()
 { 
  Set();
  font_TR90();
  font_FF_F();
  font_FFF();
  font_FF();
  back_TR90();
  back_FF_B_Slow();
  back_FF();
  font_sapanL();
 }
void font_sapanL()
 {
  font_sfloor2_Special();
  font_TL90();
  font_FF_F();pause(TIME_SLOW);
  font_while_F(); /////////
  font_while_cross();
  font_FF_Sapan();
  //  font_FF_Slow_Sapan(); // FF
  //  font_while_B_Slow();
  //  font_while_cross_Slow(); //<--- font_FF_B();
  back_FF();
  back_FF_B();
  back_while_B_Slow();
  back_while_cross_Slow();
  back_FF_Slow();
  font_TR90();
  font_FF_F();
  font_FF();
 }
void font_sapanR()
 {
  font_sfloor2_Special();
  font_FF_F();
  font_FF_Slow_Sapan(); // FF
  //font_while_cross_Slow(); //<-- font_FF_B
  back_FF();
  back_FF_F();
  back_FF();
 }
void font2_sapanR()
 {
  font_sfloor2_Special();
  font_FF_F();
  font_FFF();
  font_FFF();
  font_FF_Slow_Sapan(); // FF
  //font_while_cross_Slow(); //<--- font_FF_B();
  back_FF();
  
 }
void back_sapanR()
 {
  back_sfloor2_Special();
  back_FF_F();
  back_FF_Slow_Sapan(); // FF
  //back_while_cross_Slow(); //<-- font_FF_B
  font_FF();
  font_FF_F();
  font_FF();
 }
///// ขึ้นวางบิงโก && วางไว้หน้าทางเข้า
void part_island()
 {
  if(BAGS==0)
  {
   part_L_island();
  }
  else
  {
    part_R_island();
  }
 }
void part_L_island()
 {
  back_FFF();
  back_FFF();
  back_FF();
  font_TL90();
  font_FF_F();
  font_FFF();
  font_FFF();
  Up_Bags_Sapan();
  font_RR();
  font_FF_F();
  font_FF_Smooth();
  font_FF_B();
  font_place1();
 }
void part_R_island()
 {
  back_FF();
  font_TR90();
  font_FF_F();
  font_FFF();
  font_FFF();
  font_RRR();
  font_FFF();
  font_RRR();
  font_FFF();
  Up_Bags_Sapan();
  font_RR();
  font_FF_F();
  font_FF_Smooth();
  font_FF_B();
  font_place1();
 }
void goto_Bonus()
 {
  back_while_cross();
  back_FF_F();
  back_FF();
  font_TR90();
  font_FF_F();
  font_FFF();
  Up_Bags_Sapan();
  font_RR();
  font_FF_F();
  font_FF_Smooth();
  font_FF_B();
  font_place1();
 }
///////////////
////
void BOX_F()
 {
  if(Cost==0)
  {
   if(F>0){font_box1(); F-=1; Cost++;}
  }
  if(Cost==1)
  {
   if(F>0){font_box2(); F-=1; Cost++;}
  }
  if(Cost==2)
  {
   if(F>0){font_box3(); F-=1; Cost++;}
  }
  if(Cost==3)
  {
   if(F>0){font_box4(); F-=1; Cost++;}
  }
  if(Box_Special==0)
  {
   if(Cost==4)
   {
    if(F>0){font_box5(); F-=1; Cost++;}
   }
  }
 }
void BOX_B()
 {
  if(Cost==0)
  {
   if(B>0){back_box1(); B-=1; Cost++;}
  }
  if(Cost==1)
  {
   if(B>0){back_box2(); B-=1; Cost++;}
  }
  if(Cost==2)
  {
   if(B>0){back_box3(); B-=1; Cost++;}
  }
  if(Cost==3)
  {
   if(B>0){back_box4(); B-=1; Cost++;}
  }
  if(Box_Special==0)
  {
   if(Cost==4)
   {
    if(B>0){back_box5(); B-=1; Cost++;}
   }
  }
 }
void BOX_Special_F()
 {
  if(Box_Special==0){font_box5(); F-=1; Box_Special=1;}
 }
void BOX_Special_B()
 {
  if(Box_Special==0){back_box5(); B-=1; Box_Special=1;}
 }
void font_box1()
 {
  font_FF_B();
  font_trackLine_ZickZack_time(TIME_ZZ);
  font_FF_F(); 
  font_place1_Special(); 
  font_Keep2_Special();
  back_trackLine_ZickZack_time(TIMERE_ZZ);
  back_FF_F(); back_FF();
 }
void font_box2()
 {
  font_TR90(); font_FF_F();
  font_FFF(); font_LLL(); font_FF();
  font_FF_F();
  font_while_F_Slow();
  while(analog(F_trackR)<REF[1])
  {font_SL_ZickZack(0);}
  font_while_F_Slow();
  while(analog(F_trackL)<REF[0])
  {font_SR_Slow(0);}
  font_FF_F_Slow();
  font_place1_Special();
  font_Keep2_Special();
  back_FF_Smooth();
  back_FF_F();
  back_while_F_Slow();
  while(analog(B_trackR)<REF[3])
  {back_SL_ZickZack(0);}
  back_while_F_Slow();
  back_FF_F();
  back_RRR(); back_FFF(); back_LL(); 
 }
void font_box3()
 {
  font_TR90(); font_FF_F();
  font_LL(); font_FF_B();
  font_trackLine_time(TIME_ZZ);
  font_FF_F(); 
  font_place1_Special(); 
  font_Keep2_Special();
  back_FF_F(); back_trackLine_time(TIMERE_ZZ);
  back_FF_F(); back_RRR(); back_LL();
 }
void font_box4()
 {
  font_TL90(); font_FF_F();
  font_RRR(); font_FF_F();
  font_place1_Special(); 
  font_Keep2_Special();
  back_LLL(); back_RR();
 }
void font_box5()
 {
  font_TL90(); font_FF_F();
  font_FFF(); font_RRR(); font_FF_F();
  font_place1_Special(); 
  font_Keep2_Special();
  back_FF(); 
  font_TR90(); font_FF_F();
  font_FFF(); font_LL();
 }
void back_box1()
 {
  font_TL90(); font_TL90();
  font_FF_F();
  font_FF();
  back_FF_F();
  back_FF(); 
  back_FF_B();
  back_trackLine_ZickZack_time(TIME_ZZ);
  back_FF_F(); 
  back_place1_Special(); 
  back_Keep2_Special();
  font_trackLine_ZickZack_time(TIMERE_ZZ);
  font_FF_F(); font_FF();
  back_TL90(); back_TL90();
  back_FF_F();
  back_FF();
  font_FF_F();
  font_FF();
 }
void back_box2()
 {
  back_TL90(); back_FF_F();
  back_FFF(); back_LLL(); back_FF_Smooth();
  back_FF_F();
  back_while_F_Slow();
  while(analog(B_trackR)<REF[3])
  {back_SL_ZickZack(0);}
  back_while_F_Slow();
  back_FF_F();
  back_place1_Special(); 
  back_Keep2_Special();
  font_FF_Smooth();
  font_FF_F();
  font_while_F_Slow();
  while(analog(F_trackR)<REF[1])
  {font_SL_ZickZack(0);}
  font_while_F_Slow();
  font_FF_F(); font_RRR(); font_FFF(); font_RR(); 
 }
void back_box3()
 {
  back_TL90(); 
  back_FF_F();
  back_FF();
  font_TL90(); 
  font_FF_F();
  font_FF();
  back_FF_F();
  back_FF();
  back_FF_B();
  back_trackLine_time(TIME_ZZ);
  back_FF_F(); 
  back_place1_Special(); 
  back_Keep2_Special();
  font_FF_F(); font_trackLine_time(TIMERE_ZZ);
  font_FF_F(); font_RRR(); font_RR();
 }
void back_box4()
 {
  back_TR90(); back_FF_F();
  back_RRR(); back_FF_F();
  back_place1_Special(); 
  back_Keep2_Special();
  font_LLL();
  font_LL();
 }
void back_box5()
 {
  back_TR90(); back_FF_F();
  back_FFF(); back_RRR(); back_FF_F();
  back_place1_Special(); 
  back_Keep2_Special();
  font_LL(); font_FF_F();
  font_FFF(); font_LL();
 }
void font_DeathZone()
 {
  back_FF_F();
  back_FF();
  font_TL90();
  font_FF_F();
  //font_sfloor1();
  font_FF();
 }
void back_DeathZone()
 {
  back_FF_F();
  back_RRR();
  back_FF();
  //back_sfloor1();
  //back_FF();
 }
void font_reDeathZone()
 {
  //back_FF_F();
  back_FFF();
  back_FF();
  font_TR90();
  font_FF_F();
  font_FF();
 }
void back_reDeathZone()
 {
  //font_trackLine_time(TIME);
  //font_FF_F();
  font_FFF();
  font_LLL();
  font_FF_F();
  font_FF();
 }
void font_uturnDeathZone()
 {
  back_FFF();
  back_FF();
  back_TL90();
  back_TL90();
  back_FF_F();
  back_FF();
 }
void back_uturnDeathZone()
 {
  font_FFF();
  font_FF();
  font_TL90();
  font_TL90();
  font_FF_F();
  font_FF();
 }
////// Start & Goto
void Start_Box1()
 {
  font_sfloor2(); back_sfloor2(); delay(400);
  while(analog(crossR)>REF[5]){font_FW(0);}
  font_FF();pause(TIME);
  back_FF_Slow();
  back_while_cross_Slow(); 
 }
void Start_Box2()
 {
  font_FFF_FF_Slow();
  font_FF_FF_Slow();pause(TIME);
  back_FF_FF_Slow();
  back_while_cross_Slow();
 }
void Start_Box3()
 {
  font_TL90();
  font_FF_F();
  font_FFF();
  font_FFF();
  font_FF();
  back_TL90(); back_FF_F();
  back_FFF();
  back_FF();
  back_FF_F_Slow();
  font_while_F_Slow();
 }
void Start_Box4()
 {
  font_FF();
  back_TL90(); back_FF_F();
  back_RR();
  back_FF_F_Slow();
  font_while_F_Slow();
 }
void Start_Box5()
 {
  font_FF_F();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_LLL();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FF();
  back_while_cross_Slow();
 }
void Start_Box6()
 {
  font_find_FW_Slow();
 }
void Start_Box7()
 {
 back_TL90();
 back_FF_F();
 back_FFF();
 back_RR();
 back_FF_F_Slow();
 font_while_F_Slow();
 }
void Start_Box8()
 {
  font_FF();
  back_TL90();
  back_FF_F();
  back_RR();
  back_FF_F_Slow();
  font_while_F_Slow();
 }
//// ReTRY Box
void goto_Box1()
 {
  while(analog(crossR)>REF[3]){font_FW(0);}
  font_FF();pause(TIME);
  back_FF_Slow();
  back_while_cross_Slow(); 
 }
void goto_Box2()
 {
  while(analog(crossR)>REF[3]){font_FW(0);}
  font_FF();
  font_FF_FF_Slow();
 }
void goto_Box3()
 {
  
 }
void goto_Box4()
 {
  
 }
void goto_Box5()
 {
  while(analog(crossR)>REF[3]){font_FW(0);}
  font_RRR();
  font_FF_L();
  font_FFF();
  font_FFF();
  font_FFF();
  font_RRR();
  font_LLL();
  font_FFF();
  font_FFF();
  font_FF();
  back_while_cross_Slow();
 }
void goto_Box6()
 {
  
 }
void goto_Box7()
 {
  
 }
void goto_Box8()
 {
  
 }
void goto_Rescue_Box1()
 {
  while(analog(crossR)>REF[3]){font_FW(0);}
  font_FF();pause(TIME);
  back_FF_Slow();
  back_while_cross_Slow(); 
 }
void goto_Rescue_Box2()
 {
  while(analog(crossR)>REF[3]){font_FW(0);}
  font_FF();
  font_FF_FF_Slow();
 }
void goto_Rescue_Box3()
 {
  
 }
void goto_Rescue_Box4()
 {
  font_FFF();
  font_FFF();
  font_RRR();
  font_FF();
 }
void goto_Rescue_Box5()
 {
  
 }
void goto_Rescue_Box6()
 {
  
 }
void goto_Rescue_Box7()
 {
  
 }
void goto_Rescue_Box8()
 {
  font_RRR();
  font_FFF();
  font_RRR();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_RRR();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FF();
 }
///// หยิบทีละ 4 ไปทีละกล่อง
void Rescue_KeepBox1()
 {
  font_Keep1_Check1();
  Check_Magnetic_a_F();
  font_Keep1_Check2();
 }
void Rescue_KeepBox2()
 {
  font_place2(); 
  font_Keep1_Check1();
  Check_Magnetic_b_F(); 
  font_Keep1_Check2();
 }
void Rescue_KeepBox3()
 {
  back_Keep1_Check1();
  Check_Magnetic_c_B();
  back_Keep1_Check2();
 }
void Rescue_KeepBox4()
 {
  back_place2(); 
  back_Keep1_Check1();
  Check_Magnetic_d_B();
  back_Keep1_Check2();
 }
void Rescue_KeepBox5()
 {
  font_Keep1_Check1();
  Check_Magnetic_a_F();
  font_Keep1_Check2();
 }
void Rescue_KeepBox6()
 {
  font_place2();
  font_Keep1_Check1();
  Check_Magnetic_b_F();
  font_Keep1_Check2();
 }
void Rescue_KeepBox7()
 {
  back_Keep1_Check1();
  Check_Magnetic_c_B();
  back_Keep1_Check2();
 }
void Rescue_KeepBox8()
 {
  back_place2();
  back_Keep1_Check1();
  Check_Magnetic_d_B();
  back_Keep1_Check2();
 }
void Rescue_Box1()
 {
  Start_Box1();
  Rescue_KeepBox1();
 }
void Rescue_Box2()
 {
  ///////// Start
  Start_Box2();
  Rescue_KeepBox2();
 }
void Rescue_Box3()
 {
  Start_Box3();
  Rescue_KeepBox3();
 }
void Rescue_Box4()
 {
  Start_Box4();
  Rescue_KeepBox4();
  goto_Rescue_Box4();
 }
void Rescue_Box5()
 {
  ///////// Start
  Start_Box5();
  Rescue_KeepBox5();
 }
void Rescue_Box6()
 {
  Start_Box6();
  Rescue_KeepBox6();
 }
void Rescue_Box7()
 {
  Start_Box7();
  Rescue_KeepBox7();
 }
void Rescue_Box8()
 {
  Start_Box8();
  Rescue_KeepBox8();
 }
void Rescue_sapanR()
 {
  back_while_F_Slow();
  back_while_cross_Slow();
  while(analog(B_trackR)>REF[3]){back_TR(0);}
  while(analog(B_trackR)<REF[3]){back_TR(0);}
  back_FL();
  back_while_cross();
  back_FFF();
  back_FFF();
  back_FFF();
  back_FFF();
  back_LL();
  back_sapanR();
 }
///// หยิบทีละ 2
void Rescue2_Zone1()
 {
  Rescue_Box1();
  Rescue_Box2();
  font_TL90();
  font_FF_F();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FFF();
  font_FF();
  Rescue();
  push_sapanL();
 }
void Rescue2_Zone2()
 {
  goto_sapanL_start();
  font_FF_F();
  font_LL();
  font_FF_F_Slow();
  font_Keep1_Check1();
  Check_Magnetic_a_F();
  font_Keep1_Check2();
  back_FF();
  font_TR90();
  font_FF_F();
  font_LL();
  font_FF_F_Slow();
  font_Keep1_Check1();
  Check_Magnetic_b_F();
  font_Keep1_Check2();
  back_FFF();
  back_FFF();
  back_FF();
  font_TL90();
  font_FF_F();
  font_FFF();
  font_FF();
 }
void Rescue2_Zone3()
 {
  goto_Box6();
 }
void Rescue2_Zone4()
 {
  goto_Box7();
 }
//////////////
void Function_Main()
 {
  Rescue_Box1();
  Rescue_Box2();
  Rescue_Box3();
  Rescue_Box4();
  Rescue();
  push_sapanL();
  Rescue_Box5();
  Rescue_Box6();
  Rescue_sapanR();
  Rescue_Box7();
  Rescue_Box8();
  goto_Rescue_Box8();
  Rescue();
  goto_Rescue_sapan();
  goto_bags();
  keep2_bags1();
  keep2_bags2();
  placebox_bags();
  part_island();
 } /// 1
void Function_Main2()
 {
  font_sfloor2();
  back_sfloor2();delay(500);
  hand_Set();
  goto_Box5();
  Rescue_KeepBox5();
  Rescue_Box6();
  Rescue_sapanR();
  Rescue_Box7();
  Rescue_Box8();
  goto_Rescue_Box8();
  Rescue();
  Rescue_Zone3();
  Rescue_Zone4();
  goto_Rescue2();
  Rescue();
  push_sapanL();
  goto_sapan();
  goto_bags();
  keep2_bags1();
  keep2_bags2();
  placebox_bags();
  part_island();
 }
void Function_Placebags2_island()
 {
  part2_start();
  place2_bags1();
  font2_sapanR();
  Wait();
  goto_sapanL_start();
  goto_sapan();
  goto_bags();
  keep2_bags1();
  keep2_bags2();
  placebox_bags();
  part_island();
 }
void Function_Placebags2_sapanR()
 {
  part2_start();
  place2_bags1();
  font2_sapanR();
 }
void Function_Placebags2()
 {
  part2_start();
  place2_bags1();
 }
void Function_SapanL_Placebags2()
 {
  goto_sapanL_start();
  goto_sapan();
  goto_bags();
  keep2_bags1();
  keep2_bags2();
  placebox_bags();
  part_island();
 }
void Function_SapanR_Placebags2()
 {
  goto_sapanR_start();
  goto_bags();
  keep2_bags1();
  keep2_bags2();
  placebox_bags();
  part_island();
 }
void Function_SapanL_SapanR_Placebags2()
 {
  goto_sapanL_start();
  sapanL_goto_sapanR();
  goto_bags();
  keep2_bags1();
  keep2_bags2();
  placebox_bags();
  part_island();
 }
void Function_Placebags3()
 {
  goto_sapan_start();
  goto_bags();
  keep3_bags1();
  keep3_bags2();
  placebox_bags();
  part_island();
 }
void Function_SapanL_Placebags3()
 {
  goto_sapanL_start();
  goto_sapan();
  goto_bags();
  keep3_bags1();
  keep3_bags2();
  placebox_bags();
 }
void Function_SapanR_Placebags3()
 {
  goto_sapanR_start();
  goto_bags();
  keep3_bags1();
  keep3_bags2();
  placebox_bags();
 }
void Function_SapanL_SapanR_Placebags3()
 {
  goto_sapanL_start();
  sapanL_goto_sapanR();
  goto_bags();
  keep3_bags1();
  keep3_bags2();
  placebox_bags();
 }
void Function_Bonus()
 {
  goto_sapan_start();
  goto_bags();
  keep2_bags1();
  goto_Bonus();

 }

//////////////////////////
void Monitor()
 {
  setTextColor(GLCD_GREEN);
  glcdLine(60,0,60,225,GLCD_GREEN);
  setTextColor(GLCD_WHITE);
  setTextSize(2);
  glcd(0,1," F ");
  glcd(0,6," B ");
  beep();
 }
void Monitor_Special()
 {
  while(in(SW_START)==1){
  BAGS=knob(1);
  setTextColor(GLCD_GREEN);
  setTextSize(8);
  glcd(1,1,"%d ",BAGS);
 }
 while(in(SW_START)==0){glcdClear();}
 setTextColor(GLCD_GREEN);
 glcdLine(60,0,60,225,GLCD_GREEN);
 setTextColor(GLCD_WHITE);
 setTextSize(2);
 glcd(0,1," F ");
 glcd(0,6," B ");
 beep();
 }
//////////////////////////

void setup() {
 Set();
 if(in(18)==0){Menu();}

 setTextColor(GLCD_RED);
 setTextSize(2);
 glcd(0,0,"Phuthai-Robot");
 glcdCircle(0,0,220,GLCD_GREEN);
 
 setTextColor(GLCD_SKY);
 setTextSize(8);
 int x=0,y=0;
 while(in(18)==1){
  function=knob(9);
  glcd(1,1,"%d ",function);
  if(in(SW_FONT)==0)
  {
    if(x==0){x=1;beep();while(in(SW_FONT)==0){}}
    else if(x==2){x=0;beep();while(in(SW_FONT)==0){}}
    else{x=2;beep();while(in(SW_FONT)==0){}}
  }
  if(in(SW_BACK)==0)
  {
    if(y==0){y=1;beep();while(in(SW_BACK)==0){}}
    else if(y==2){y=0;beep();while(in(SW_BACK)==0){}}
    else{y=2;beep();while(in(SW_BACK)==0){}}
  }
  if(x==0){font_sKind();font_sfloor1();}
  if(y==0){back_sKind();back_sfloor1();}
  if(x==1){font_sKeep();}
  if(y==1){back_sKeep();}
  if(x==2){font_sfloor2();}
  if(y==2){back_sfloor2();}
 }
 while(in(SW_START)==0){glcdClear();}
}

void loop() {
if(function==0)
 {
  //Function_Placebags2_island();
  //Wait();
  //push_sapanL();
  //Wait();
  //setTextColor(GLCD_WHITE);
  //setTextSize(1);
  /*while(1)
  {
   glcd(3,1,"A6:%d ",analog(6));
   glcd(4,1,"A7:%d ",analog(7));
  }*/
  //goto_sapanL_start();
  //goto_sapan();
  //goto_bags();
 // keep3_bags1();
  //keep3_bags2();
 // placebox_bags();
  //part_island();
  push_sapanL();
 }
if(function==1)
 {
  Monitor_Special();
  Function_Main(); 
  Wait();
 }
if(function==2)
 {
  Monitor_Special();
  Function_Main2();
  Wait();
 }
if(function==3)
 {
  Monitor_Special();
  Function_SapanL_Placebags3();
 }
if(function==4)
 {
  Monitor_Special();
  Function_SapanR_Placebags3();
 }
if(function==5)
 {
  Monitor_Special();
  Function_SapanL_SapanR_Placebags3();
 }
if(function==6)
 {
  Function_Placebags2_sapanR();
 }
if(function==7)
 {
  Function_Placebags2();
 }
if(function==8)
 {
  Monitor_Special();
  Function_Placebags3();
 }
if(function==9)
 {
  Function_Bonus();
 }
if(function==10)
 {
  font_FF_F();
  back_while_cross_Slow();
  Wait();
  back_FW(TIME_DELAY);pause(TIME_PAUSE);
  font_sfloor1_Special_2();delay(300);
  font_FW(TIME_SLOW);pause(TIME_PAUSE);
  Wait();
  font_place1();
  //font_FW_Slow(TIME_SLOW);pause(TIME_PAUSE);
  Wait();
  font_sKeep();delay(300);
  Wait();
  font_FW(TIME);
  Wait();
  font_sKind();
  Wait();
  back_FW(TIME_ZZ);pause(TIME_PAUSE);
  font_sBump();
  font_FW(TIMERE_ZZ-200);pause(TIME_PAUSE);
  Wait();
  beep();
  ////////////////
  back_FF_F();
  font_while_cross_Slow();
  Wait();
  font_FW(TIME_ZZ);pause(TIME_PAUSE);
  back_sfloor1_Special();delay(300);
  back_FW(TIMERE_ZZ);pause(TIME_PAUSE);
  Wait();
  back_place1();
  font_FW(TIME_SLOW);
  Wait();
  back_sKeep();delay(300);
  Wait();
  back_FW(TIME_DELAY);
  Wait();
  back_place1_Special();
  Wait();
  beep();
 }
if(function==11)
 {
  back_sfloor2();
 }
Wait();
}
