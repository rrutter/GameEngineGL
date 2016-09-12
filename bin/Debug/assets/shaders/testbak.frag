#version 400

in vec4 fragmentColor;
out vec4 color;


void main() {
    //Just hardcode the color to red
    color = fragmentColor;
//	color = vec4(1.0, 0.0, 1.0, 1.0);
}