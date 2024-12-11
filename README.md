# Image-and-Color-Manipulation in C++

## Description
This project introduces object-oriented programming concepts through the development of simple classes for working with colors, images, and pixel locations. The project focuses on encapsulation, enabling the creation and manipulation of color and image data while adhering to C++ class principles. This foundational implementation can be extended to include more advanced image operations, such as file writing and editing.

## Overview
The project includes three primary classes:
1. **ColorClass** - Represents RGB colors with features for color adjustment and validation.
2. **RowColumnClass** - Identifies pixel locations within an image.
3. **ColorImageClass** - Manages a collection of colors arranged in a grid, simulating an image.

The code adheres to strict class responsibility principles, ensuring modular and reusable components. All RGB color values are constrained within a range of 0 to 1000, and pixel locations are treated independently of specific image dimensions.

---

## Classes and Functions

### **ColorClass**
Represents RGB colors, enabling manipulation and validation of color components.

- **Constructors**:
  - `ColorClass()`  
    Initializes the color to white (RGB: 1000, 1000, 1000).
  - `ColorClass(int inRed, int inGreen, int inBlue)`  
    Initializes the color with specified RGB values, clipping values outside the range [0, 1000].

- **Setters**:
  - `void setToBlack()`  
    Sets the color to black (RGB: 0, 0, 0).
  - `void setToRed()`  
    Sets the color to full red (RGB: 1000, 0, 0).
  - `void setToGreen()`  
    Sets the color to full green (RGB: 0, 1000, 0).
  - `void setToBlue()`  
    Sets the color to full blue (RGB: 0, 0, 1000).
  - `void setToWhite()`  
    Sets the color to white (RGB: 1000, 1000, 1000).

- **Operations**:
  - `bool setTo(int inRed, int inGreen, int inBlue)`  
    Sets RGB values, clipping out-of-range values. Returns `true` if clipping occurs.
  - `bool setTo(ColorClass &inColor)`  
    Copies RGB values from another `ColorClass` object.
  - `bool addColor(ColorClass &rhs)`  
    Adds RGB values from another color, clipping if necessary.
  - `bool subtractColor(ColorClass &rhs)`  
    Subtracts RGB values from another color, clipping if necessary.
  - `bool adjustBrightness(double adjFactor)`  
    Adjusts brightness by scaling RGB values with a factor. Clipping is applied if necessary.

- **Output**:
  - `void printComponentValues()`  
    Prints RGB values in the format `R: <red> G: <green> B: <blue>`.

---

### **RowColumnClass**
Encapsulates the row and column indices of a pixel location in an image.

- **Constructors**:
  - `RowColumnClass()`  
    Initializes row and column indices to -99999 (default values).
  - `RowColumnClass(int inRow, int inCol)`  
    Initializes with specified row and column indices.

- **Setters**:
  - `void setRowCol(int inRow, int inCol)`  
    Sets both row and column indices.
  - `void setRow(int inRow)`  
    Sets the row index.
  - `void setCol(int inCol)`  
    Sets the column index.

- **Output**:
  - `void printRowCol()`  
    Prints row and column values in the format `Row: <row>, Col: <col>`.

---

### **ColorImageClass**
Manages a two-dimensional array of `ColorClass` objects representing an image.

- **Initialization**:
  - `ColorImageClass()`  
    Constructs an image with default dimensions and initializes all pixels to black.

- **Operations**:
  - `bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor)`  
    Sets the color of a specific pixel. Returns `false` if the location is out of bounds.
  - `bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor)`  
    Retrieves the color of a specific pixel. Returns `false` if the location is out of bounds.

- **Output**:
  - `void printImage()`  
    Prints the image as a grid of RGB values.

---


## Example Usage

### Compilation
Compile the program using a C++ compiler:
```bash
g++ -std=c++98 -g -Wall project2.cpp -o project2.exe
./project2.exe
