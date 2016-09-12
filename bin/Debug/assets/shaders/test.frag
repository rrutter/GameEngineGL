#version 130
//The fragment shader operates on each pixel in a given polygon

in vec4 fragmentColor;

//This is the 3 component float vector that gets outputted to the screen
//for each pixel.
out vec4 color;

void main() {
    //Just hardcode the color to red
    color = fragmentColor;
}