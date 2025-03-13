#include "bipedX_v1.h"

bipedX_v1 hashv3;
int degree[20];
int index = 0;
String content = "";
char character;
int eyeLED = 46;

void setup() {      
  Serial.begin(115200);
  Serial.println("GPIO test!");
  pinMode(eyeLED, OUTPUT);

  bipedX_v1.init_hash();
  eye_led();
  bipedX_v1.initial_position();
  delay(5000);
  bipedX_v1.say_hi(2, 1000);
  bipedX_v1.hands_up(1, 3000);
  bipedX_v1.forward(20, 500);
  bipedX_v1.turn_right(5, 500);
  bipedX_v1.turn_left(5, 500);
  bipedX_v1.move_right(5, 800);
  bipedX_v1.move_left(5, 800);
  bipedX_v1.ball_kick_right(1, 1000);
  bipedX_v1.ball_kick_left(1, 1000);
  bipedX_v1.max_sit(1, 2000);
  bipedX_v1.bow(1, 2000);
  bipedX_v1.right_bow(1, 2000);
  bipedX_v1.left_bow(1, 2000);
  bipedX_v1.ape_move(3, 2000);
  bipedX_v1.clap(3, 2000);
  bipedX_v1.right_leg_up(3, 2000);
  bipedX_v1.left_leg_up(3, 2000);
  bipedX_v1.hip_pose(1, 2000);
  bipedX_v1.right_leg_balance(1, 3000);
  bipedX_v1.left_leg_balance(1, 3000);
  bipedX_v1.flying_action(3, 2000);
  bipedX_v1.hand_sit_zigzak(3, 2000);
  bipedX_v1.side_shake(3, 1200);
  bipedX_v1.hip_shake(3, 1200);
  bipedX_v1.bend_up(1, 2000);
  bipedX_v1.push_up(3, 3000);
}

void loop() {
  bipedX_v1.say_hi(2, 1000);
  bipedX_v1.hands_up(1, 3000);
}

void eye_led() {
  digitalWrite(eyeLED, HIGH);
}

void blink_eye() {
  digitalWrite(eyeLED, LOW);
  delay(250);
  digitalWrite(eyeLED, HIGH);
  delay(5000);
}

void serialEvent() {
  String degree;
  degree = Serial.readString();
  executeAngle(degree);
}

void executeAngle(String degree) {
  int angle_array[20], r = 0, t = 0;
  for (int i = 0; i < degree.length(); i++)
  {
    if (degree.charAt(i) == ',')
    {
      angle_array[t] = degree.substring(r, i).toInt();
      r = (i + 1);
      t++;
    }
  }
  for (int i = 0; i < 20; i++) {
    Serial.print(angle_array[i]);
    Serial.print("|");
  }
  Serial.println("");
  bipedX_v1.move_servo(2000, angle_array);
}
