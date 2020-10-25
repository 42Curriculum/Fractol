# Fractol

This project is about recreating different types of fractals using Minilibx (42's graphic library, which is based on OpenGl)

The colors and color set are semi random. The first few are hardcoded, but as one changes the colors more and more, the color values become values in an unitialized array (allocated but unitialized array) , so restarting the program usually gives a different output...
<br> <img align="right" width="250" src="https://github.com/42Curriculum/Fractol/blob/master/resources/fractol.PNG"/><br>
**Usage :** ./fractol [fractal_name]

**Available fractals :** Julia, Mandelbrot, Owo, Phoenix, Burningship, Tom

*All the above except Mandelbrot and Burningship change depending on mouse position, however this function is disabled on startup , Press Space to enable it again.*

Bonuses : 

- **Scrollwheel** : Zoom in and out

- **Space** : Freeze /unfreeze fractal 

- **Right/Left arrows** : Change color set

- **Up/Down arrows** : Change LOD

- **Enter** : Saves image. Enter image name in terminal. Image will be saved in images/[image_names] I recommend to freeze the image before saving it.

## Julia fractal

![](images/Julia2.jpg)

## Owo fractal | A fractal I came up with

![](images/Owo.jpg)

## Mandelbrot

![](images/Mandelbrot.jpg)
