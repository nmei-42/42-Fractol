# 42-Fractol
Exploring the wonderful world of fractals with the 42 mlx library.

This program will generate a number of escape time fractals with the ability to zoom, cool color animations, and in some cases, mouse interactivity!

### Installation
To generate an executable for this project run `make` in the root of the project directory after you've downloaded or cloned it.

This project will only work on MacOS El Capitan/Sierra/HighSierra and even then, no promises! 

### Usage
After running `make` to generate the fractol executable you can run the program with `./fractol [fractol option]`

Here is a list of possible fractals that this program can display:
```
Fractol options (use number, not name!):
0) Julia
1) Mandelbrot
2) Burning Ship
3) Trijulia
4) Tribrot
5) Excalibur
6) Quadjulia
7) Quadrobrot
8) Ghosts
Example: './fractol 0' - Displays Julia set
```
### Output
The program will render a fractal in a new graphical window!

![Example:](https://github.com/nmei-42/42-Fractol/blob/master/fractol_example_images/Excalibur.png)

![Another:](https://github.com/nmei-42/42-Fractol/blob/master/fractol_example_images/Quadrobrot.png)

The user can interact with the fractals with the following commands:

```
Mouse scroll up/down: Zoom in/out @ mouse position
Arrow keys: Translate real/imaginary axes
'+/-': Increase/decrease iteration limit
f: Freeze mouse cursor tracking (only works for Julia type fractals!)
p: Psychedelic mode! (will prevent other commands except for 's' and 'd' until toggled off)
l: linear continous color mode
c: Toggle color palettes
s: Color surprise!
d: Psychedelic surprise!
r: Reset active fractal!
esc: Quit :(
 ```
### Acknowledgements
Special thanks to fellow 42 USA cadet [ikarishe](https://github.com/RedPlacebo) for the inspiration to create Psychedelic mode!!
