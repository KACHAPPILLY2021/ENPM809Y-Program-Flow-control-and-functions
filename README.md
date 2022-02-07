# ENPM809Y-Program-Flow-control-and-functions
In this project, the program takes input from the user and this inputs are passed to different functions.
Scenario: An industrial robot is tasked to fill up boxes with parts.
          – All parts are of the same type.
          – Boxes come in four different sizes: Small (S), medium (M), large (L), and extra large (XL).
          – The maximum number of parts for each box type is different. 
The maximum number of parts in smaller boxes should always be lower than the maximum number of parts in bigger boxes.

Rules:
1. The robot must fill up bigger boxes before filling up smaller ones. In this case,
the robot has to fill up XL boxes first, then L boxes, then M boxes, and finally S
boxes.
2. Boxes can not be partially filled. They either have to be full or empty. If a box
can contain 10 parts then you can only have 10 parts or 0 part in this box.
