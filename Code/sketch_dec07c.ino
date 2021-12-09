#include "config.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define joyX 34
#define joyY 35
#define PushButton 2
//#define UP_BUTTON 2
//#define DOWN_BUTTON 3

const unsigned long PADDLE_RATE = 33;
const unsigned long BALL_RATE = 26;
const uint8_t PADDLE_HEIGHT = 10;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
//#define RESET_BUTTON 3
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void drawCourt();

unsigned long previousTime = 0;

uint8_t ball_x = 64, ball_y = 5;
uint8_t ball_dir_x = 1, ball_dir_y = 1;
unsigned long ball_update;

unsigned long paddle_update;
const uint8_t CPU_X = 12;
uint8_t cpu_y = 5;

const uint8_t PLAYER_X = 115;
uint8_t player_y = 16;

uint8_t playerscore = 0;
uint8_t aiscore = 0;

AdafruitIO_Feed *digital = io.feed("scoreboard");

void setup() {
    // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();
  //digital->onMessage(handleMessage);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
      Serial.println();
  Serial.println(io.statusText());
  digital->get();
    display.begin(SSD1306_SWITCHCAPVCC);

    // Display the splash screen (we're legally required to do so)
    display.display();
    unsigned long start = millis();

    //pinMode(UP_BUTTON, INPUT);
    //pinMode(DOWN_BUTTON, INPUT);
    pinMode(PushButton, INPUT_PULLUP);

    display.clearDisplay();
    drawCourt();

    while(millis() - start < 2000);

    display.display();

    ball_update = millis();
    paddle_update = ball_update;
}

void loop() {
  
  if(digitalRead(2) == LOW){
    display.clearDisplay();
    drawCourt();
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);        // Draw white text
    display.setCursor(10,5);
    display.print(F("Game over"));
    display.setCursor(10,16);
    display.print(F("Sending highscore..."));
    display.display();
    io.run();
    digital->save(playerscore);
    aiscore = 0;
    playerscore = 0;
    delay(2000);
    }
    bool update = false;
    unsigned long time = millis();

    static bool up_state = false;
    static bool down_state = false;
    
    //up_state |= (analogRead(joyY));
    //down_state |= (digitalRead(DOWN_BUTTON) == LOW);
    display.clearDisplay();
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);        // Draw white text
    display.setCursor(50,0);             // Start at top-left corner
    display.print(aiscore);
    display.print(F("\t"));
    display.print(playerscore);
    display.display();
    if(time > ball_update) {
        uint8_t new_x = ball_x + ball_dir_x;
        uint8_t new_y = ball_y + ball_dir_y;

        // Check if we hit the vertical walls
        if(new_x == 0 || new_x == 127) {
          if(new_x == 0){
              playerscore += 1;
              new_x = 64;
              new_y = 16;
            }
            else{
              aiscore += 1;
              new_x = 64;
              new_y = 16;
            }
            ball_dir_x = -ball_dir_x;
            new_x += ball_dir_x + ball_dir_x;
        }

        // Check if we hit the horizontal walls.
        if(new_y == 0 || new_y == 31) {
            ball_dir_y = -ball_dir_y;
            new_y += ball_dir_y + ball_dir_y;
        }

        // Check if we hit the CPU paddle
        if(new_x == CPU_X && new_y >= cpu_y && new_y <= cpu_y + PADDLE_HEIGHT) {
            ball_dir_x = -ball_dir_x;
            new_x += ball_dir_x + ball_dir_x;
        }

        // Check if we hit the player paddle
        if(new_x == PLAYER_X
           && new_y >= player_y
           && new_y <= player_y + PADDLE_HEIGHT)
        {
            ball_dir_x = -ball_dir_x;
            new_x += ball_dir_x + ball_dir_x;
        }

        display.drawPixel(ball_x, ball_y, BLACK);
        display.drawPixel(new_x, new_y, WHITE);
        ball_x = new_x;
        ball_y = new_y;

        ball_update += BALL_RATE;

        update = true;
    }

    if(time > paddle_update) {
        paddle_update += PADDLE_RATE;

        // CPU paddle
        display.drawFastVLine(CPU_X, cpu_y, PADDLE_HEIGHT, BLACK);
        const uint8_t half_paddle = PADDLE_HEIGHT >> 1;
        if(cpu_y + half_paddle + 20 > ball_x) {
            cpu_y -= 1;
        }
        if(cpu_y + half_paddle + 20< ball_x) {
            cpu_y += 1;
        }
        if(cpu_y < 1) cpu_y = 1;
        if(cpu_y + PADDLE_HEIGHT > 31) cpu_y = 31 - PADDLE_HEIGHT;
        display.drawFastVLine(CPU_X, cpu_y, PADDLE_HEIGHT, WHITE);

        // Player paddle
        display.drawFastVLine(PLAYER_X, player_y, PADDLE_HEIGHT, BLACK);
        if(analogRead(joyX)< 1000) {
            player_y -= 1;
        }
        if(analogRead(joyX)> 2000) {
            player_y += 1;
        }
        //up_state = down_state = false;
        if(player_y < 1) player_y = 1;
        if(player_y + PADDLE_HEIGHT > 31) player_y = 31 - PADDLE_HEIGHT;
        display.drawFastVLine(PLAYER_X, player_y, PADDLE_HEIGHT, WHITE);

        update = true;
    }

    if(update)
        display.display();
}

void drawCourt() {
    display.drawRect(0, 0, 128, 32, WHITE);
}
