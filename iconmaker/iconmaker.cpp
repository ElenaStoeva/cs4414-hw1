#include <iostream>
#include <string>
#include "pngwriter.hpp"
#include <cstring>
using namespace std;

int max_rgb = 0xFFFFFF;
int min_rgb = 0x000000;

int main()
{
  string pathBase = "./files/";
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
      int r1 = max_rgb;
      int g1 = max_rgb;
      if (lineColor1 == "r")
      {
        g1 = min_rgb;
      }
      if (lineColor1 == "g")
      {
        r1 = min_rgb;
      }
      png.line(1, 30, 64, 30, r1, g1, 0);
      png.line(1, 31, 64, 31, r1, g1, 0);
      png.line(1, 32, 64, 32, r1, g1, 0);
      png.line(1, 33, 64, 33, r1, g1, 0);
      png.line(1, 34, 64, 34, r1, g1, 0);
      png.line(1, 35, 64, 35, r1, g1, 0);

      int r2 = max_rgb;
      int g2 = max_rgb;
      if (lineColor2 == "r")
      {
        g2 = min_rgb;
      }
      if (lineColor2 == "g")
      {
        r2 = min_rgb;
      }
      png.line(30, 1, 30, 64, r2, g2, 0);
      png.line(31, 1, 31, 64, r2, g2, 0);
      png.line(32, 1, 32, 64, r2, g2, 0);
      png.line(33, 1, 33, 64, r2, g2, 0);
      png.line(34, 1, 34, 64, r2, g2, 0);
      png.line(35, 1, 35, 64, r2, g2, 0);
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
        int r1 = max_rgb;
        int g1 = max_rgb;
        if (lineColor1 == "r")
        {
          g1 = min_rgb;
        }
        if (lineColor1 == "g")
        {
          r1 = min_rgb;
        }
        png.line(1, 30, 64, 30, r1, g1, 0);
        png.line(1, 31, 64, 31, r1, g1, 0);
        png.line(1, 32, 64, 32, r1, g1, 0);
        png.line(1, 33, 64, 33, r1, g1, 0);
        png.line(1, 34, 64, 34, r1, g1, 0);
        png.line(1, 35, 64, 35, r1, g1, 0);

        int r2 = max_rgb;
        int g2 = max_rgb;
        if (lineColor2 == "r")
        {
          g2 = min_rgb;
        }
        if (lineColor2 == "g")
        {
          r2 = min_rgb;
        }
        png.line(4, 64, 64, 4, r2, g2, 0);
        png.line(3, 64, 64, 3, r2, g2, 0);
        png.line(2, 64, 64, 2, r2, g2, 0);
        png.line(1, 64, 64, 1, r2, g2, 0);
        png.line(1, 63, 63, 1, r2, g2, 0);
        png.line(1, 62, 62, 1, r2, g2, 0);
        png.line(1, 61, 61, 1, r2, g2, 0);

        int r3 = max_rgb;
        int g3 = max_rgb;
        if (lineColor3 == "r")
        {
          g3 = min_rgb;
        }
        if (lineColor3 == "g")
        {
          r3 = min_rgb;
        }
        png.line(1, 4, 61, 64, r3, g3, 0);
        png.line(1, 3, 62, 64, r3, g3, 0);
        png.line(1, 2, 63, 64, r3, g3, 0);
        png.line(1, 1, 64, 64, r3, g3, 0);
        png.line(2, 1, 64, 63, r3, g3, 0);
        png.line(3, 1, 64, 62, r3, g3, 0);
        png.line(4, 1, 64, 61, r3, g3, 0);

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
          int r1 = max_rgb;
          int g1 = max_rgb;
          if (lineColor1 == "r")
          {
            g1 = min_rgb;
          }
          if (lineColor1 == "g")
          {
            r1 = min_rgb;
          }
          png.line(1, 30, 64, 30, r1, g1, 0);
          png.line(1, 31, 64, 31, r1, g1, 0);
          png.line(1, 32, 64, 32, r1, g1, 0);
          png.line(1, 33, 64, 33, r1, g1, 0);
          png.line(1, 34, 64, 34, r1, g1, 0);
          png.line(1, 35, 64, 35, r1, g1, 0);

          int r2 = max_rgb;
          int g2 = max_rgb;
          if (lineColor2 == "r")
          {
            g2 = min_rgb;
          }
          if (lineColor2 == "g")
          {
            r2 = min_rgb;
          }
          png.line(4, 64, 64, 4, r2, g2, 0);
          png.line(3, 64, 64, 3, r2, g2, 0);
          png.line(2, 64, 64, 2, r2, g2, 0);
          png.line(1, 64, 64, 1, r2, g2, 0);
          png.line(1, 63, 63, 1, r2, g2, 0);
          png.line(1, 62, 62, 1, r2, g2, 0);
          png.line(1, 61, 61, 1, r2, g2, 0);

          int r3 = max_rgb;
          int g3 = max_rgb;
          if (lineColor3 == "r")
          {
            g3 = min_rgb;
          }
          if (lineColor3 == "g")
          {
            r3 = min_rgb;
          }
          png.line(30, 1, 30, 64, r3, g3, 0);
          png.line(31, 1, 31, 64, r3, g3, 0);
          png.line(32, 1, 32, 64, r3, g3, 0);
          png.line(33, 1, 33, 64, r3, g3, 0);
          png.line(34, 1, 34, 64, r3, g3, 0);
          png.line(35, 1, 35, 64, r3, g3, 0);

          int r4 = max_rgb;
          int g4 = max_rgb;
          if (lineColor4 == "r")
          {
            g4 = min_rgb;
          }
          if (lineColor4 == "g")
          {
            r4 = min_rgb;
          }
          png.line(1, 4, 61, 64, r4, g4, 0);
          png.line(1, 3, 62, 64, r4, g4, 0);
          png.line(1, 2, 63, 64, r4, g4, 0);
          png.line(1, 1, 64, 64, r4, g4, 0);
          png.line(2, 1, 64, 63, r4, g4, 0);
          png.line(3, 1, 64, 62, r4, g4, 0);
          png.line(4, 1, 64, 61, r4, g4, 0);

          png.close();
        }
      }
    }
  }
  return 0;
}