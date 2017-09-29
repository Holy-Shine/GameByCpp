# cplusplusGame
some little game with c++
## 1、snake game
contain 4 modules.  

- **Setup**    
Initial game. For example, set snake's head into centre position.
- **Draw**  
Every clock(*windows API:Sleep*), draw the map, snake, fruit and so on. 
- **Input**  
Using the program unblocked API(*from header file conio.h*) to handle keyboard input. WASD to change snake's direction.
- **Logic**  
Every clock, judge if game is over.