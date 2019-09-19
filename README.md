# Mandelbrot Explorer

The Mandelbrot Set is one of the most well known fractals and I wanted to build a program that allows the user to explore this beautiful fractal. This repository contains the source code to build an application that can display single images or generate series of images to put together into animation sequences. The goal was to build an application that can render images quickly by using various optimizations such as parallel for loops and interior checking.

**Coming Soon: Paper with more detail on optimization techniques and their effectiveness**

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

- OpenCV 3.4.6+:
  - [Ubuntu Install](https://docs.opencv.org/4.1.1/d7/d9f/tutorial_linux_install.html)
  - [Windows Install](https://www.learnopencv.com/install-opencv-4-on-windows/)
- Intel's Threading Building Blocks Library:
  - [Source Code](https://github.com/intel/tbb)
  - [Setup Environment Variables](https://software.intel.com/en-us/node/505529)
- GCC 8.3+
- cmake 3.13+

**NOTE: I have only tested this on Ubuntu 19.04 with the versions of software shown above. I do believe this should work on Windows as well but I haven't checked. Additionally, lower verisons of the software listed above might work, but I havn't checked that either.**

### Installing
```
git clone https://github.com/jackm97/mandelbrot_explorer.git
cd ./mandelbrot_explorer
mkdir build
cd build
cmake .. && make
```
This should create an executable in the build directory called `mandelbrot_explorer`.

## Usage
To run the program call:
```
./mandelbrot_explorer arg1
```
`arg1` can take two values `0` to render a single image and `1` to render many images for an animation sequence.

### Example 1
```
$ ./mandelbrot_explorer 0
Enter resolution, positive integers (e.g. height width): 1080 1920

Enter center point (e.g. x y): -1 0

Supersample? (Y/n): y

Enter zoom level(maximum of 1e12): 1.5

Enter iterations(positive integer): 5000
```
Notice that after the initial program execution, input prompts are displayed in the terminal. These particular inputs would generate a 1080x1920 image centered on the complex coordinate (-1,0) with a zoom of 1.5x. The image would be rendered at double the input resolution(e.g. supersampled) and then resized back to the input resolution using linear interpolation. This is an anti-aliasing method. The maximum number of iterations before a pixel is considered in the set is 5000.

### Example 2
![](./examples/example2.gif)
```
$ ./mandelbrot_explorer 1
Enter resolution, positive integers (e.g. height width): 1080 1920

Enter center point (e.g. x y): -1.5231172841989 -4.5676519363104e-18

Supersample? (Y/n): n

Enter initial and final zoom level, maximum zoom is 1e12 (e.g. start_zoom end_zoom): 1 1e12

Enter number of frames to capture (positive integer): 1900

Enter iterations(positive integer): 5000

Enter file path to save image series: ../images2
```
Like the single image mode, the series image mode has input prompts. In this case the inputs shown above would produce 1900 frames that range from a zoom of 1 to a zoom of 1e12. Each frame is 1080x1920 and is not supersampled. Again the maximum iterations are set to 5000. The file path for the generated frames is `../images2`.

## Authors

* **Jack Myers* - *Initial work* - [jackm97](https://github.com/jackm97)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
