# Prog2-ImageProcessing
Image processing for programming 2 class project. My implementation reads binary data from 11 TGA image files, stores header data in a header object, and stores color values in multiple pixel objects. Subsequently, the pixel data is modified to conform with photo editing features such as layering, blending, and saturating. Please see below for a detailed description of each editing type. Finally, the modified color values are written to a new image file and produced as output. 

Editing types:

1. Uses the Multiply blending mode to combine “layer1.tga” (top layer) with “pattern1.tga”
(bottom layer).

2. Uses the Subtract blending mode to combine “layer2.tga” (top layer) with “car.tga” (bottom
layer). This mode subtracts the top layer from the bottom layer.

3. Uses the Multiply blending mode to combine “layer1.tga” with “pattern2.tga”, and store the
results temporarily. Loads the image “text.tga” and, using that as the top layer, combines it with
the previous results of layer1/pattern2 using the Screen blending mode.

4. Multiplies “layer2.tga” with “circles.tga” and stores it. Loads “pattern2.tga” and, using that as the
top layer, combines it with the previous result using the Subtract blending mode.

5. Combines “layer1.tga” (as the top layer) with “pattern1.tga” using the Overlay blending mode.
   
6. Loads “car.tga” and adds 200 to the green channel.
   
7. Loads “car.tga” and scales (multiply) the red channel by 4, and the blue channel by 0. This increases
the intensity of any red in the image, while negating any blue it may have.

8. Loads “car.tga” and writes each channel to a separate file: the red channel should be
“part8_r.tga”, the green channel should be “part8_g.tga”, and the blue channel should be
“part8_b.tga.”

9. Loads “layer_red.tga”, “layer_green.tga” and “layer_blue.tga”, and combines the three files into
one file. The data from “layer_red.tga” is the red channel of the new image, layer_green is
green, and layer_blue is blue.

10. Loads “text2.tga”, and rotates it 180 degrees, flipping it upside down.

