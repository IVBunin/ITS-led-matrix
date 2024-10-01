#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 256
#define DATA_PIN 5

int pos_i,pos_j,pos_map;
int pos=0;
int i,j;
int ledmap[16][16];
CRGB leds[NUM_LEDS];

void print_its(int i, int j){
    int bukavi[][2] = {{i,j},{i,j+3},{i,j+5},{i,j+6},{i,j+7},{i,j+10},{i,j+11},
                    {i+1,j},{i+1,j+3},{i+1,j+6},{i+1,j+9},{i+1,j+12},
                    {i+2,j},{i+2,j+2},{i+2,j+3},{i+2,j+6},{i+2,j+9},
                    {i+3,j},{i+3,j+1},{i+3,j+3},{i+3,j+6},{i+3,j+9},{i+3,j+12},
                    {i+4,j},{i+4,j+3},{i+4,j+6},{i+4,j+10},{i+4,j+11}};
        for(int y = 0; y <28; y++){
            pos_i = bukavi[y][0];
            pos_j= bukavi[y][1];
            if(pos_j  >= 0){
              if(pos_j <= 15){
                pos_map=ledmap[pos_i][pos_j];
                leds[pos_map]= CRGB::Blue;
              }
            }
        }
        FastLED.show();   
      };

void led_clear(){
  for(int f = 0; f < 256; f++){
    leds[f]= CRGB::Black;
  }
  FastLED.show();
}

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  for (int i = 0; i < 16; i++) {
        if (i % 2 != 0) {
            for (int j = 0; j < 16; j++) {
                ledmap[i][j] = i * 16 + j;
            }
        } else {
            for (int j = 15; j >= 0; j--) {
                ledmap[i][j] = i * 16 + 15 - j;
            }
        }
    }
}

void loop(){ 
  for(int cord_y = -16; cord_y < 16; cord_y++)
    {print_its(4,cord_y);
    delay(100);
    led_clear();
    }

}