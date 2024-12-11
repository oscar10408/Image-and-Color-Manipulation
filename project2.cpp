#include <iostream>
using namespace std;

// Author: Hao-Chun, Shih
// Date: 10/03/2024
// Purpose: To implement Object Oriented Paradigm for handling images and color
//          Implementing the color value class, and RowColumn class, and 
//          combining them into a image (RGB value in 2D array) 

// Row Default value is -99999 by specs
const int ROW_COL_DEFAULT_VALUE = -99999;
// Color Default value is 1000 (white) by specs 
const int INIT_COLOR_VALUE = 1000;

// Max color value is set to 1000
const int MAX_COLOR = 1000;
// Min color value is set to 1000
const int MIN_COLOR = 0;

// Max row number is 10
const int MAX_ROW = 10;
// Max column number is 18
const int MAX_COL = 18;

// Check if input color value is valid, return true if valid
bool doColorInRange(int colorValue);
// Clipping color value if it is outside the valid range
int setColorValue(int colorValue);

class ColorClass
{
  private:
    int redAmt;
    int greenAmt;
    int blueAmt;

  public:
    // Default constructor
    ColorClass();
    // Constructor with input color value
    ColorClass(int inRed, int inGreen, int inBlue);
    
    // Setting color to Black
    void setToBlack();
    // Setting color to Red
    void setToRed();
    // Setting color to Green
    void setToGreen();
    // Setting color to Blue
    void setToBlue();
    // Setting color to White
    void setToWhite();
    // Overload setTo function. For dealing with individual color value
    // instead of using ColorClass object
    bool setTo(int inRed, int inGreen, int inBlue);
    // Overload setTo function. For dealing with ColorClass object
    // instead of using individual color value
    bool setTo(ColorClass &inColor);
    // Adding input object rhs's color value respectively to
    // the object who call it
    bool addColor(ColorClass &rhs);
    // Substracting input object rhs's color value respectively to
    // the object who call it
    bool subtractColor(ColorClass &rhs);
    // Adjusting the color value of ColorClass object, if the adjFactor > 1
    // then the color get brighter. Otherwise, get dimmer.
    bool adjustBrightness(double adjFactor);
    // Print out the Componenet color value in form of
    // ""R: <red> G: <green> B: <blue>"
    void printComponentValues();
};

class RowColumnClass
{
  private:
    int rowIndex;
    int colIndex;

  public: 
    // Default Constructor, setting color to black
    RowColumnClass();
    // Constructor with input row, column value
    RowColumnClass(int inRow, int inCol);
    
    // Setting Row and Column
    void setRowCol(int inRow, int inCol);
    // Setting Row
    void setRow(int inRow);
    // Setting Column
    void setCol(int inCol);
    // Getting Row
    int getRow();
    // Getting Col
    int getCol();
    // Adding the values in the input parameter into the object the function
    // is called on.
    void addRowColTo(RowColumnClass &inRowCol);
    // Print out the row, and column.
    void printRowCol();
};

class ColorImageClass
{
  private:
    ColorClass ColorImageObject[MAX_ROW][MAX_COL];

  public:
    // Default Constructor setting all pixel to black
    ColorImageClass();
  
    // Setting all pixel to same color value provided bt input ColorClass object
    void initializeTo(ColorClass &inColor);
    // Adding color value to the object who call this function
    // correspodingly to the pixel location
    bool addImageTo(ColorImageClass &rhsImg);
    // Tunring the pixel of the object who call this function into
    // the sum of the pixel of the obbjects in imagesToAdd
    bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd[]);
    // Setting color of inColor to the location inRowCol
    bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);
    // Changing Outcolor's color value at location inRowCol respectingly to
    // the object who call this function (if location is valid)
    bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);
    // Print out the whole image(ColorImageClass object) by row
    void printImage();
};


#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main()
{
  ColorClass testColor;
  RowColumnClass testRowCol;
  RowColumnClass testRowColOther(111, 222);
  ColorImageClass testImage;
  ColorImageClass testImages[3];

  //Test some basic ColorClass operations...
  cout << "Initial: ";
  testColor.printComponentValues();
  cout << endl;

  testColor.setToBlack();
  cout << "Black: ";
  testColor.printComponentValues();
  cout << endl;

  testColor.setToGreen();
  cout << "Green: ";
  testColor.printComponentValues();
  cout << endl;

  testColor.adjustBrightness(0.5);
  cout << "Dimmer Green: ";
  testColor.printComponentValues();
  cout << endl;

  //Test some basic RowColumnClass operations...
  cout << "Want defaults: ";
  testRowCol.printRowCol();
  cout << endl;

  testRowCol.setRowCol(2, 8);
  cout << "Want 2,8: ";
  testRowCol.printRowCol();
  cout << endl;

  cout << "Want 111, 222: ";
  testRowColOther.printRowCol();
  cout << endl;

  testRowColOther.setRowCol(4, 2);
  testRowCol.addRowColTo(testRowColOther);
  cout << "Want 6,10: ";
  testRowCol.printRowCol();
  cout << endl;

  //Test some basic ColorImageClass operations...
  testColor.setToRed();
  testImage.initializeTo(testColor);

  testRowCol.setRowCol(555, 5);
  cout << "Want: Color at [555,5]: Invalid Index!" << endl;
  cout << "Color at ";
  testRowCol.printRowCol();
  cout << ": ";
  if (testImage.getColorAtLocation(testRowCol, testColor))
  {
    testColor.printComponentValues();
  }
  else
  {
    cout << "Invalid Index!";
  }
  cout << endl;

  testRowCol.setRow(4);
  cout << "Want: Color at [4,5]: R: 1000 G: 0 B: 0" << endl;
  cout << "Color at ";
  testRowCol.printRowCol();
  cout << ": ";
  if (testImage.getColorAtLocation(testRowCol, testColor))
  {
    testColor.printComponentValues();
  }
  else
  {
    cout << "Invalid Index!";
  }
  cout << endl;

  //Set up an array of images of different colors
  testColor.setToRed();
  testColor.adjustBrightness(0.25);
  testImages[0].initializeTo(testColor);
  testColor.setToBlue();
  testColor.adjustBrightness(0.75);
  testImages[1].initializeTo(testColor);
  testColor.setToGreen();
  testImages[2].initializeTo(testColor);

  //Modify a few individual pixel colors
  testRowCol.setRowCol(4, 2);
  testColor.setToWhite();
  testImages[1].setColorAtLocation(testRowCol, testColor);

  testRowCol.setRowCol(2, 4);
  testColor.setToBlack();
  testImages[2].setColorAtLocation(testRowCol, testColor);

  //Add up all images in testImages array and assign result
  //to the testImage image
  testImage.addImages(3, testImages);
  
  //Check some certain values
  cout << "Added values:" << endl;
  for (int colInd = 0; colInd < 8; colInd += 2)
  {
    testRowCol.setRowCol(4, colInd);
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
      testColor.printComponentValues();
    }
    else
    {
      cout << "Invalid Index!";
    }
    cout << endl;
  }
  
  for (int rowInd = 0; rowInd < 8; rowInd += 2)
  {
    testRowCol.setRowCol(rowInd, 4);
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
      testColor.printComponentValues();
    }
    else
    {
      cout << "Invalid Index!";
    }
    cout << endl;
  }
  
  cout << "Printing entire test image:" << endl;
  testImage.printImage();

  return 0;
}
#endif


// Global functions
bool doColorInRange(int colorValue)
{
  if(colorValue < MIN_COLOR || colorValue > MAX_COLOR)
  {
    return false;
  }
  else
  {
    return true;
  }
};


int setColorValue(int colorValue)
{
  if (colorValue > MAX_COLOR)
  {
    return MAX_COLOR;
  }
  else if(colorValue < MIN_COLOR)
  {
    return MIN_COLOR;
  }
  else
  {
    return colorValue;
  }
};

// ColorClass member function definition
ColorClass::ColorClass()
{
  redAmt = INIT_COLOR_VALUE;
  greenAmt = INIT_COLOR_VALUE;
  blueAmt = INIT_COLOR_VALUE;
};

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
  redAmt = inRed;
  greenAmt = inGreen;
  blueAmt = inBlue;
};

void ColorClass::setToBlack()
{
  redAmt = MIN_COLOR;
  greenAmt = MIN_COLOR;
  blueAmt = MIN_COLOR;
};

void ColorClass::setToRed()
{
  redAmt = MAX_COLOR;
  greenAmt = MIN_COLOR;
  blueAmt = MIN_COLOR;
};

void ColorClass::setToGreen()
{
  redAmt = MIN_COLOR;
  greenAmt = MAX_COLOR;
  blueAmt = MIN_COLOR;
};

void ColorClass::setToBlue()
{
  redAmt = MIN_COLOR;
  greenAmt = MIN_COLOR;
  blueAmt = MAX_COLOR;
};

void ColorClass::setToWhite()
{
  redAmt = MAX_COLOR;
  greenAmt = MAX_COLOR;
  blueAmt = MAX_COLOR;
};

bool ColorClass::setTo(int inRed, int inGreen, int inBlue)
{
  if (doColorInRange(inRed) && 
      doColorInRange(inGreen) && 
      doColorInRange(inBlue))
  {
    redAmt = inRed;
    greenAmt = inGreen;
    blueAmt = inBlue;
    return false;
  }
  else
  {
    redAmt = setColorValue(inRed);
    greenAmt = setColorValue(inGreen);
    blueAmt = setColorValue(inBlue);
    return true;
  }
};

bool ColorClass::setTo(ColorClass &inColor){
  redAmt = inColor.redAmt;
  greenAmt = inColor.greenAmt;
  blueAmt = inColor.blueAmt;
  return false;
};

bool ColorClass::addColor(ColorClass &rhs)
{
  bool clipOrNot;

  redAmt += rhs.redAmt;
  greenAmt += rhs.greenAmt;
  blueAmt += rhs.blueAmt;

  clipOrNot = setTo(redAmt, greenAmt, blueAmt);
  return clipOrNot;
};

bool ColorClass::subtractColor(ColorClass &rhs)
{
  bool clipOrNot;

  redAmt -= rhs.redAmt;
  greenAmt -= rhs.greenAmt;
  blueAmt -= rhs.blueAmt;

  clipOrNot = setTo(redAmt, greenAmt, blueAmt);
  return clipOrNot;
};

bool ColorClass::adjustBrightness(double adjFactor)
{
  bool clipOrNot;

  redAmt = static_cast<int>(redAmt * adjFactor);
  greenAmt = static_cast<int>(greenAmt * adjFactor);
  blueAmt = static_cast<int>(blueAmt * adjFactor);

  clipOrNot = setTo(redAmt, greenAmt, blueAmt);
  return clipOrNot;
};

void ColorClass::printComponentValues()
{
  cout << "R: " << redAmt << " G: " << greenAmt << " B: " << blueAmt;
};



// RowColumnClass member function definition
RowColumnClass::RowColumnClass()
{
  rowIndex = ROW_COL_DEFAULT_VALUE;
  colIndex = ROW_COL_DEFAULT_VALUE;
};

RowColumnClass::RowColumnClass(int inRow, int inCol)
{
  rowIndex = inRow;
  colIndex = inCol;
};

void RowColumnClass::setRowCol(int inRow, int inCol)
{
  rowIndex = inRow;
  colIndex = inCol;
};

void RowColumnClass::setRow(int inRow)
{
  rowIndex = inRow;
};

void RowColumnClass::setCol(int inCol)
{
  colIndex = inCol;
};

int RowColumnClass::getRow()
{
  return rowIndex;
};

int RowColumnClass::getCol()
{
  return colIndex;
};

void RowColumnClass::addRowColTo(RowColumnClass &inRowCol)
{
  rowIndex += inRowCol.rowIndex;
  colIndex += inRowCol.colIndex; 
};

void RowColumnClass::printRowCol()
{
  cout << "[" << rowIndex << "," << colIndex << "]";
};

// ColorImageClass member function definition
ColorImageClass::ColorImageClass()
{
  int row;
  int col;

  for(row = 0; row < MAX_ROW; row++)
  {
    for(col = 0; col < MAX_COL; col++)
    {
      ColorImageObject[row][col].setToBlack();
    }
  }
};

void ColorImageClass::initializeTo(ColorClass &inColor)
{
  int row;
  int col;

  for(row = 0; row < MAX_ROW; row++)
  {
    for(col = 0; col < MAX_COL; col++)
    {
      ColorImageObject[row][col].setTo(inColor);
    }
  }
};

bool ColorImageClass::addImageTo(ColorImageClass &rhsImg)
{
  int row;
  int col;
  bool clipOrNot = false;

  for(row = 0; row < MAX_ROW; row++)
  {
    for(col = 0; col < MAX_COL; col++)
    {
      if(ColorImageObject[row][col].
         addColor(rhsImg.ColorImageObject[row][col]))
      {
        clipOrNot = true;
      }
    }
  }
  return clipOrNot;
};

bool ColorImageClass::addImages(int numImgsToAdd,
                                ColorImageClass imagesToAdd[])
{  
  int row;
  int col;
  bool clipOrNot = false;

  for(row = 0; row < MAX_ROW; row++)
  {
    for(col = 0; col < MAX_COL; col++)
    {
      ColorImageObject[row][col].setToBlack();
    }
  }

  int currentNumber;
  for(currentNumber = 0; currentNumber < numImgsToAdd; currentNumber++)
  {
    if(addImageTo(imagesToAdd[currentNumber]))
    {
      clipOrNot = true;
    }
  }
  return clipOrNot;
};

bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol,
                                         ColorClass &inColor)
{
  int row = inRowCol.getRow();
  int col = inRowCol.getCol();

  if(row >= 0 && row < MAX_ROW && col >= 0 && col < MAX_COL)
  {
    ColorImageObject[row][col].setTo(inColor);
    return true;
  }
  return false;
};

bool ColorImageClass::getColorAtLocation(RowColumnClass &inRowCol,
                                         ColorClass &outColor)
{
  int row = inRowCol.getRow();
  int col = inRowCol.getCol();

  if(row >= 0 && row < MAX_ROW && col >= 0 && col < MAX_COL)
  {
    outColor.setTo(ColorImageObject[row][col]);
    return true;
  }
  return false;
};

void ColorImageClass::printImage()
{
  int row;
  int col;
  const int NUMBER_COL_FOR_PRINT = MAX_COL - 1;

  for(row = 0; row < MAX_ROW; row++)
  {
    for(col = 0; col < MAX_COL; col++)
    {
      ColorImageObject[row][col].printComponentValues();
      if(col < NUMBER_COL_FOR_PRINT)
      {
        cout << "--";
      }
    }
    cout << endl;
  }
};
