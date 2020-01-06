//**** Documenation Section **********
//This is the program for line_follower_bot
//Author : Ajeet kumar  
//Branch : ECE,IET LUCKNOW
// Date : 22nd feb 2019

/* pin on Arduino generates signal which goes to Motor_Driver to 
 *  change the direction of rotation of motor of the robot. 
 */
#define rigthWheel_Front 3
#define rigthWheel_Back 5
#define leftWheel_Front 6
#define leftWheel_Back 9


/* pin on Arduino to read the value of IR_sensor_modules 
 *  on the Line_follower robot reading Will be integer value
 *  lie in range of 0 ~ 1023.
 */
 
#define irSensor_1 10
#define irSensor_2 8
#define irSensor_3 7
#define irSensor_4 4
#define irSensor_5 2


// variable to store the values genetated by IR_SENSOR_MODULES attached to the robot
 int val_1;
 int val_2;
 int val_3;
 int val_4;
 int val_5;


//  subroutine section

void setup() {
  // put your setup code here, to run once:
  // By default the pin are off so we have to set value on control register to switch it on
  
  pinMode(rigthWheel_Front ,OUTPUT); // sets the value on register so that GPIO acts as output pin
  pinMode(rigthWheel_Back ,OUTPUT);  
  pinMode(leftWheel_Front ,OUTPUT);  
  pinMode(leftWheel_Back ,OUTPUT);

  pinMode(irSensor_1 , INPUT);// set the value of the register so that the GPIO acts as input pin
  pinMode(irSensor_2 , INPUT);
  pinMode(irSensor_3, INPUT);
  pinMode(irSensor_4 , INPUT);
  pinMode(irSensor_5, INPUT);
      
      
 val_1 = digitalRead(irSensor_1); // reads the value and stores in volatile int Variable 
 val_2 = digitalRead(irSensor_2);
 val_3 = digitalRead(irSensor_3);
 val_4 = digitalRead(irSensor_4);
 val_5 = digitalRead(irSensor_5);
 
}

void loop() {
  // put your main code here, to run repeatedly:
 if (( val_1==1 && val_2==1 && val_3==0 && val_4==1 && val_5==1  )
 ||(val_2==1 && val_3==0 && val_4==1))
 {
    // vehical is aligned with the black line 
    // robot has to move forward
    digitalWrite(rigthWheel_Front , HIGH );
    digitalWrite(rigthWheel_Back , LOW );
    digitalWrite(leftWheel_Front ,HIGH);
    digitalWrite(leftWheel_Back , LOW);

      delay(100);
  }

  else if (( val_1==0 && val_2==0 && val_3==0 && val_4==1 && val_5==1 )
          ||( val_1==1 && val_2==0 && val_3==1 && val_4==1 && val_5==1)
           ||( val_1==0 && val_2==1 && val_3==1 && val_4==1 && val_5==1))
          
  {
    // vehical is deviated rightwards from the line
    // robot needs to move leftwards to align itself with line
    digitalWrite(rigthWheel_Front , HIGH );
    digitalWrite(rigthWheel_Back , LOW );
    digitalWrite(leftWheel_Front ,LOW);
    digitalWrite(leftWheel_Back , HIGH);

    delay(100);
    
    }

  else if (( val_1==1 && val_2==1 && val_3==0 && val_4==0 && val_5==0 )
           ||( val_1==1 && val_2==1 && val_3==1 && val_4==0 && val_5==1)
           ||( val_1==1 && val_2==1 && val_3==1 && val_4==1 && val_5==0)
           ||( val_1==0 && val_2==0 && val_3==0 && val_4==0 && val_5==0))
  {
    // vehical is deviated leftwards from the line
    // robot needs to move rightwards to align itself with the line
    
    digitalWrite(rigthWheel_Front , LOW );
    digitalWrite(rigthWheel_Back , HIGH );
    digitalWrite(leftWheel_Front ,HIGH);
    digitalWrite(leftWheel_Back , LOW);

    delay(100);
    }
    
    else if (  val_1==1 && val_2==1 && val_3==1 && val_4==1 && val_5==1  )
     {
    digitalWrite(rigthWheel_Front , HIGH );
    digitalWrite(rigthWheel_Back , LOW );
    digitalWrite(leftWheel_Front ,LOW);
    digitalWrite(leftWheel_Back , HIGH);

     }
}
     
   

 
