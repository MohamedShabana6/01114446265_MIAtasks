# MIA phase 1 Tasks
---

*This repository includes branches such that **each** branch contains one task  :smile::smile:*

# 1. **task 1** :- 
   Writing a programming code using C/C++ :

 * <ins>task 1.1 *Hello Gru* </ins>:wave:
    &ensp;&ensp;&ensp;Just write a C program that prints the string ‘GRU’ in the output terminal (console) (Hello World problem). 

output:
   ```GRU```

*  <ins>task 1.2  *Counting Down*</ins> :watch:
   &ensp;&ensp;&ensp;Write a C program that takes the number to start the
countdown from as input and prints the countdown text starting
from that number.

**Input Example:**
5
**Output:**
```
5
4
3
2
1
Blast off to the moon!
```

* <ins> task 1.3 *Task Manager* </ins> :books:
  &ensp;&ensp;&ensp;Create a C program that allows users to add, view, and
remove tasks, each task has an id/index and a description. The id
is a positive unique integer.

**Runtime example:**
 ```
 Minions Task Manager
1. Add Task
2. View Tasks
3. Remove Task
4. Exit
Select an option: 1

Enter task description: Prepare moon launch materials
Task added successfully!

  ```

* <ins>task 1.4 *Kalman missile* </ins> :rocket: 
   &ensp;&ensp;&ensp;Write a C program that takes two sensor measurements (just
two arrays) and generates only one new array measurement with
any averaging method, such as Kalman Filter.

• The two sensors have two different accuracies one has 79% and
another one has 92%.

 **Sensor readings:**
 ```C
 float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
float bno55[10] = {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
 ```

 **Output:**
Generate one single array from the input arrays with the same
number of elements (this one array should be a better description
of the missile projectile).

----
# 2. **task 2** :-
* <ins>task2.1 *Lightning the Dark*</ins> :bulb:
   &ensp;&ensp;&ensp;Design a circuit that takes 220V AC as input and the output is 5V DC and connects LED to the output (Hint: firstly, you need to step down the AC, then you need to convert AC to DC, and lastly connect the
load).

   &ensp;&ensp;&ensp;If the input power budget of your power supply is 1440W, and you use a current limiting resistor with each LED 330 ohm. Estimate how many LEDs could be put in parallel that is suitable for this power budget.

__

 * <ins> task2.2 *Air Extractor to Fan*</ins> :cyclone:
 &ensp;&ensp;&ensp;The absence of windows in the home of the girls can contribute to creating a hot and stifling atmosphere within the house.

&ensp;&ensp;&ensp;Fortunately, the Home of Girls Air extractor is a DC motor you
could easily create an H-bridge driver to control the motor. So ,Design a simple H-bridge driver to control the direction of the DC
motor using transistors.

 __
 * <ins> task2.3 *Box of Shame*</ins> :package:
  &ensp;&ensp;&ensp;If you have a simple circuit that drive high power 12V LED
with current limiting resistor 3.3ohm and need to drive
them with 80C liPo (lithium Polymer) batteries that have
5200mAh charge, assume that girls stay inside the box of
shame for about 5 hours. How many batteries are
connected in parallel to light up the LED for more than 5
hours

---

# 3. **task 3** :-
* <ins> task3.1 *Signal to Engage*</ins> :running:
  &ensp;&ensp;&ensp;Gru hatches a clever plan to use the three orphaned girls from Miss Hattie's Home for Girls to distract Vector, the cunning and
tech-savvy villain who possesses the Shrink Ray Gru.

  &ensp;&ensp;&ensp;Write 2 Arduino codes, one that interface with two push buttons, and the other one communicates with the first one by receiving data about buttons state, using I2C communication protocol.

  &ensp;&ensp;&ensp;In the receiving side we need to interface with indicator LED and write a message on the Serial Monitor.

  | push Buttons | LED | Serial monitor |
  |:---          |:---:|            ---:|
  |B1=0, B2=0 |0% of Maximum| No message|
  |B1=1, B2=0 |50% of Maximum |Vector focused|
  |B1=0, B2=1 |75% of Maximum |Vector distracted|
  |B1=1, B2=1 |100% of Maximum |Glitch|

  __
* <ins> task3.2 *Cookiebot*</ins> :cookie:
&ensp;&ensp;&ensp;You have the cookie bot with four ultrasnoic that measure the distance each up to 8m positioned as
shown. Specifically, positioned at (0°, 90°, 180°, 270°) from the Cookie headings.

 &ensp;&ensp;&ensp;The Shrink ray champer is (5m x 6m), and we need to localize the position of the cookie bot on that champer (localization in this problem means to get (x,y) of the robot with respect to the room).
 __

# 4. **task 4** :-
* <ins> task4.1 *Sky Clash*</ins> :airplane:
&ensp;&ensp;&ensp;Implement a Python program that simulates this air battlefield using OOP Methods:
 Game has multiple rounds and it ends when one of the villains
reaches 0 Health.
During one round each villain could use a weapon to damage
the other or use a shield to protect himself from the other’s
weapons
Try to exploit OOP features as possible (Abstraction,
Inheritance, Polymorphism, Encapsulation) .
__

* <ins> task4.2 *Shrinkage Model*</ins> :gun:
&ensp;&ensp;&ensp;1-Create Linear Regression Model, and train this model on the give dataset:
The knob of the Gun has a range from [0
MW, 300MW]
Assume that shrinkage does not depend
on the volume of the target object
  Use Jupyter Notebook for your process
flow
   
   ---




 


