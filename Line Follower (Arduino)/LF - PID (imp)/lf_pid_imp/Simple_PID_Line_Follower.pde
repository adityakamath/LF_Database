
int motor_right=9;
int motor_left=10;
int right_speed;
int left_speed;
long sensors_average;
int sensors_sum;
int position;
int set_point= 5000;
int integral;
int derivative;
long proportional;
int last_proportional;
int error_value;
int max_speed=255;
float Kp= 1/20;
float Kd= 3/2;
float Ki= 1/1000;
int sensors[7];
void sensors_read()
{
for (int i = 2; i < 9; i++)
{
sensors[i] = digitalRead(i);
sensors_sum += int(sensors[i]);
}}
void pid_calc()
{ position = int(sensors_average / sensors_sum);

 integral = integral + proportional;
 derivative = proportional - last_proportional;
 last_proportional = proportional;
 error_value = int(proportional * Kp + integral * Ki + derivative * Kd)/10;
}
void calc_turn()
{ //Restricting the error value between +256.
if (error_value< -256)
{
error_value = -255;
}
if (error_value> 256)
{
error_value = 255;
}
// If error_value is less than zero calculate right turn speed values
if (error_value< 0)
{
right_speed = max_speed + error_value;
left_speed = max_speed;
}
// Iferror_value is greater than zero calculate left turn values
else
{
right_speed = max_speed;
left_speed = max_speed - error_value;
}
}

void motor_drive(int right_speed, int left_speed)
{ // Drive motors according to the calculated values for a turn
analogWrite(motor_right, right_speed);
analogWrite(motor_left, left_speed);
delay(50); // Optional
}
void setup()
{}
void loop()
{ sensors_read(); //Reads sensor values and computes sensor sum and weighted average
pid_calc(); //Calculates position[set point] and computes Kp,Ki and Kd
calc_turn(); //Computes the error to be corrected
motor_drive(right_speed, left_speed); //Sends PWM signals to the motors
}
