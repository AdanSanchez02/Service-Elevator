#include "FSM.h"
#include "AlternMotor.h"
#include "CallButton.h"
#include "SensorPosition.h"
#include "UtilAsycon.h"

AlternMotor Motor(0);
CallButton ButtonCall(0);
SensorPosition Sensor(0);
FSM fm(0);
UtilAsycon BreakOn(0);
int TimeFrenoFinal = 300;


FSM::FSM(byte pin){
    Init();
}

void FSM::Init(){
    Motor.InitMotor();
    //
    Sensor.Init();
    BreakOn.Init();
    BreakOn.stp();
}

void FSM::Elevator(){
 ///*
  int SensorS = BreakOn.SensorSeguro();
  if(SensorS == 1){
    BreakOn.Lampara(6);
    fm.Send_Position();
  }
 // */
 // Motor.Forward();
  //Motor.Backward();
 //Motor.Backward();
  //BreakOn.ReadSensor();
}

void FSM::Send_Position(){

    int CallButtonState = ButtonCall.Check_SP();
    int GoButtonState = ButtonCall.CheckPress();
    bool btt_stop = false;
    bool control = false; // cambio del true

    if(CallButtonState == 4 || GoButtonState == 4){
        int slc = fm.Ver_Pos(4);
        int mov = fm.SelectionMove(slc);
        if(mov == 0){control = false;}
        if(mov == 1){///////////////////////////////////////////////////////////////////////////////////////////////
          control = true;
          //}
                
        BreakOn.UnBreak();
        BreakOn.Lampara(4);
        while(control){
            int step = Sensor.Position_P4();
            if(step == 1){
                control =false;
            }
            //
            if(step == 2){
                control = false;
                btt_stop = true;
            }
            //
        }
        
        Motor.InitMotor();
        BreakOn.Break(800);
        BreakOn.Seguro_Pisos(2);
        BreakOn.Lampara(0);
        }///////////////////////////////////////////////////////////////////////////////////////////////
        
        if(btt_stop == true){
            fm.Stop_Emergency();
        }
    }

    if(CallButtonState == 3 || GoButtonState == 3){
        int slc = fm.Ver_Pos(3);
        int mov = fm.SelectionMove(slc);
        if(mov == 0){control = false;}
        if(mov == 1){///////////////////////////////////////////////////////////////////////////////////////////////
          control = true;
          //}
        
        BreakOn.UnBreak();
        BreakOn.Lampara(3);
        while(control){
            int step = Sensor.Position_P3();
            if(step == 1){
                control =false;
            }
            //
            if(step == 2){
                control = false;
                btt_stop = true;
            }
            //
        }
        
        Motor.InitMotor();
        BreakOn.Break(TimeFrenoFinal);
        BreakOn.Seguro_Pisos(2);
        BreakOn.Lampara(0);
        }///////////////////////////////////////////////////////////////////////////////////////////////
        
        if(btt_stop == true){
            fm.Stop_Emergency();
        }
    }
    
    if(CallButtonState == 2 || GoButtonState == 2){
        int slc = fm.Ver_Pos(2);
        int mov = fm.SelectionMove(slc);
        if(mov == 0){control = false;}
        if(mov == 1){///////////////////////////////////////////////////////////////////////////////////////////////
          control = true;
          //}
                
        BreakOn.UnBreak();
        BreakOn.Lampara(2);
        while(control){
            int step = Sensor.Position_P2();
            if(step == 1){
                control =false;
            }
            //
            if(step == 2){
                control = false;
                btt_stop = true;
            }
            //
        }
        
        Motor.InitMotor();
        BreakOn.Break(TimeFrenoFinal);
        BreakOn.Seguro_Pisos(2);
        BreakOn.Lampara(0);
        }///////////////////////////////////////////////////////////////////////////////////////////////
        
        if(btt_stop == true){
            fm.Stop_Emergency();
        }
    }

    if(CallButtonState == 1 || GoButtonState == 1){
        int slc = fm.Ver_Pos(1);
        int mov = fm.SelectionMove(slc);
        if(mov == 0){control = false;}
        if(mov == 1){///////////////////////////////////////////////////////////////////////////////////////////////
          control = true;
          //}
        
        BreakOn.UnBreak();
        BreakOn.Lampara(1);
        while(control){
            int step = Sensor.Position_P1();
            if(step == 1){
                control =false;
            }
            //
            if(step == 2){
                control = false;
                btt_stop = true;
            }
            //
        }
        
        Motor.InitMotor();
        BreakOn.Break(TimeFrenoFinal);
        BreakOn.Seguro_Pisos(2);
        BreakOn.Lampara(0);
        }/////////////////////////////////////////////////////////////////////////////////////////////////
        
        if(btt_stop == true){
            fm.Stop_Emergency();
        }
    }

    if(CallButtonState == 5 || GoButtonState == 5){
            fm.Stop_Emergency();
        }
}

int FSM::SelectionMove(int x){ 
    if(x == 1 || x == 0){
        return 0;  // esta en el mismo lugar
    }else{
        if(x == 2 ){    
            BreakOn.Seguro_Pisos(1);         
            Motor.Backward();
            return 1;
        }else{
            if(x == 3 ){ 
            BreakOn.Seguro_Pisos(1);
            Motor.Forward();
            return 1;

            }else{
                return 0;
            }
        }
    }
}

int FSM::Ver_Pos(int a){
    int posn = Sensor.ReadPosition();
    
    if(posn > 0){
      
        if(a == posn){ // mismo lugar
            return 1;
        }else{
            if(a < posn ){ // para bajar
                return 2;
            }else{
                if(a > posn){ // para subir
                    return 3;
                }
            }
        }
        
    }else{//
      return 0;       
    }//    
}

void FSM::Stop_Emergency(){
    Motor.InitMotor();
    fm.Return_Emergency();
}

void FSM::Return_Emergency(){
    BreakOn.Break(400);

    while(true){

      if(ButtonCall.Check_Emergency() == true){
        int posn = Sensor.ReadPosition();
        if(posn == 4){
          Motor.InitMotor();
          BreakOn.Break(700);
          break;
        }
        else{
          //BreakOn.UnBreak();
          Motor.Forward();
          BreakOn.UnBreak();
          while(true){
            if(Sensor.Position_P4() == 1){
            break;
            }
          }
          Motor.InitMotor();
          BreakOn.Break(700);
          break;
        }
      }
    }
    
   
//    while(true){
//     
//        if(ButtonCall.Check_Emergency() == true){
//            BreakOn.UnBreak();
//            Motor.Forward();
//            while(true){
//                if(Sensor.Position_P4() == 1){
//                    break;
//                }
//            }
//            
//        Motor.InitMotor();
//        BreakOn.Break(700);
//        break;
//        }  
//    }
}
