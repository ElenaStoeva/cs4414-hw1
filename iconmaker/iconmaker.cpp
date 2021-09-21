#include <iostream>
#include <string>
#include "pngwriter.hpp"
#include <cstring>
using namespace std;

int main()
{
  string pathBase = "/home/ess243/CS4414/hw1/iconmaker/files/";
  string colors[3] = {"r", "g", "y"};

  // Create files for 2-street intersections
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      string lineColor1 = colors[i];
      string lineColor2 = colors[j];
      string fileName = "i2" + lineColor1 + lineColor2 + ".png";
      string path = pathBase + fileName;
      int n = path.length();
      char char_array[n + 1];
      strcpy(char_array, path.c_str());
      char *ptr = char_array;
      pngwriter png(64, 64, 1.0, ptr);
      int r1 = 65535;
      int g1 = 65535;
      if (lineColor1 == "r")
      {
        g1 = 0;
      }
      if (lineColor1 == "g")
      {
        r1 = 0;
      }
      png.line(0, 32, 64, 32, r1, g1, 0);

      int r2 = 65535;
      int g2 = 65535;
      if (lineColor2 == "r")
      {
        g2 = 0;
      }
      if (lineColor2 == "g")
      {
        r2 = 0;
      }
      png.line(32, 0, 32, 64, r2, g2, 0);
      png.close();
    }
  }

  // Create files for 3-street intersections
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        string lineColor1 = colors[i];
        string lineColor2 = colors[j];
        string lineColor3 = colors[k];
        string fileName = "i3" + lineColor1 + lineColor2 + lineColor3 + ".png";
        string path = pathBase + fileName;
        int n = path.length();
        char char_array[n + 1];
        strcpy(char_array, path.c_str());
        char *ptr = char_array;
        pngwriter png(64, 64, 1.0, ptr);
        int r1 = 65535;
        int g1 = 65535;
        if (lineColor1 == "r")
        {
          g1 = 0;
        }
        if (lineColor1 == "g")
        {
          r1 = 0;
        }
        png.line(0, 32, 64, 32, r1, g1, 0);

        int r2 = 65535;
        int g2 = 65535;
        if (lineColor2 == "r")
        {
          g2 = 0;
        }
        if (lineColor2 == "g")
        {
          r2 = 0;
        }
        png.line(0, 64, 64, 0, r2, g2, 0);

        int r3 = 65535;
        int g3 = 65535;
        if (lineColor3 == "r")
        {
          g3 = 0;
        }
        if (lineColor3 == "g")
        {
          r3 = 0;
        }
        png.line(0, 0, 64, 64, r3, g3, 0);

        png.close();
      }
    }
  }

  // Create files for 4-street intersections
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        for (int l = 0; l < 3; l++)
        {
          string lineColor1 = colors[i];
          string lineColor2 = colors[j];
          string lineColor3 = colors[k];
          string lineColor4 = colors[l];
          string fileName = "i4" + lineColor1 + lineColor2 + lineColor3 + lineColor4 + ".png";
          string path = pathBase + fileName;
          int n = path.length();
          char char_array[n + 1];
          strcpy(char_array, path.c_str());
          char *ptr = char_array;
          pngwriter png(64, 64, 1.0, ptr);
          int r1 = 65535;
          int g1 = 65535;
          if (lineColor1 == "r")
          {
            g1 = 0;
          }
          if (lineColor1 == "g")
          {
            r1 = 0;
          }
          png.line(0, 32, 64, 32, r1, g1, 0);

          int r2 = 65535;
          int g2 = 65535;
          if (lineColor2 == "r")
          {
            g2 = 0;
          }
          if (lineColor2 == "g")
          {
            r2 = 0;
          }
          png.line(0, 64, 64, 0, r2, g2, 0);

          int r3 = 65535;
          int g3 = 65535;
          if (lineColor3 == "r")
          {
            g3 = 0;
          }
          if (lineColor3 == "g")
          {
            r3 = 0;
          }
          png.line(32, 0, 32, 64, r3, g3, 0);

          int r4 = 65535;
          int g4 = 65535;
          if (lineColor4 == "r")
          {
            g4 = 0;
          }
          if (lineColor4 == "g")
          {
            r4 = 0;
          }
          png.line(0, 0, 64, 64, r4, g4, 0);

          png.close();
        }
      }
    }
  }
  return 0;
}