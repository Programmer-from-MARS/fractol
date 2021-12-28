# fractol
Goal of this project is to create program which will draw 3 different fractals using MinilibX graphical library.
<img width="1212" alt="Screen Shot 2021-12-28 at 2 45 21 PM" src="https://user-images.githubusercontent.com/96373933/147563936-372ebcb1-aabc-4118-a99f-81fb88ff8020.png">
###### How to run:
```
git clone https://github.com/Programmer-from-MARS/fractol.git
cd fractal
make
./fractol
```
##### Once you run my program you will see a menu where you can choose which fractal you want to see and play with!
<img width="1489" alt="Screen Shot 2021-12-28 at 2 57 22 PM" src="https://user-images.githubusercontent.com/96373933/147564430-558652be-faa1-4b29-a1ee-cdeb5c634c3a.png">
1. When you press "F" you will see a black screen and options on the right side. You can either add RGB of your choice or press "7" and the fern pattern with random color will be generated. You also can control the speed with which new pixels will be added to your screen with "8" and "9".
<img width="1489" alt="Screen Shot 2021-12-28 at 2 58 49 PM" src="https://user-images.githubusercontent.com/96373933/147564450-2ad63e09-a793-4408-a20c-b5710040b403.png">
2. When you press "M" Mandelbrot set will appear as well as a menu with available options. You can zoom in and out as well as increase iteration and change color at any point
<img width="1489" alt="Screen Shot 2021-12-28 at 3 01 28 PM" src="https://user-images.githubusercontent.com/96373933/147564591-d04cbd6c-a247-41e2-b2fa-2cb77eb75ea9.png">
3. When you press "J" you will see Julia fractal. The coolest thing about that fractal is that you can change fractal by moving your mouse and once you click your mouse once again it will freeze in its current state.
<img width="1489" alt="Screen Shot 2021-12-28 at 3 02 13 PM" src="https://user-images.githubusercontent.com/96373933/147564769-94c79192-e9c2-45b7-bec7-d8e992ba6299.png">
About my code:
  Using the MinilibX library my program generates new images pixel by pixel for each fractal you have chosen. Then it pushes that image to the screen as well as the helping menu I have created in advance.
