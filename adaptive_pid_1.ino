#include <PID_v1.h>

double Setpoint, Input, Output, Turn_Val;
int RMotor, LMotor, Right_Speed, Left_Speed;
int Base_Speed = 255;

//aggressive tuning parameters --> position far from setpoint
double aggKp = 1;
double aggKi = 1;
double aggKd = 1;

//conservative tuning parameters --> position near the setpoint
double consKp = 1;
double consKi = 1;
double consKd = 1;

PID auroPID(&Input, &Output, &Setpoint, consKp, consKi, consKd, DIRECT);

double PID_compute(double input){
  double gap = abs(Setpoint - input);
  if (gap<20){
    auroPID.SetTunings(consKp, consKi, consKd);
  }
  else{
    auroPID.SetTunings(aggKp, aggKi, aggKd);
  }
  double turn_val = auroPID.Compute()*255/90;
  return turn_val;
}

void Calc_Turn(int turn_val){
  if(turn_val<-256){
    turn_val = -255;
  }
  if(turn_val>256){
    turn_val = 255;
  }
  // if motor_val is less than 0, calculate right turn speeds
  if(turn_val>=0){
    Right_Speed = Base_Speed - turn_val;
    Left_Speed = Base_Speed;
  }
  else{
    Right_Speed = Base_Speed;
    Left_Speed = Base_Speed + turn_val;
  }
}

void Motor_Drive(int right_speed, int left_speed){
  analogWrite(RMotor, right_speed);
  analogWrite(LMotor, left_speed);
  delay(50); //optional
}

int Read_RPi(){
//to be defined according to communication protocol
}

void setup() {
  Input = 0; //read_rpi(); //make function to read RPi
  Setpoint = 0;
  auroPID.SetMode(AUTOMATIC);
}

void loop() {
  Input = 0; //read_rpi();
  Turn_Val = PID_compute(Input);
  Calc_Turn(Turn_Val);
  Motor_Drive(Right_Speed, Left_Speed);
}
