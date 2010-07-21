/*      ST7565Fireworks.pde
 *      
 *      Floppyright 2010 Tuna <tuna@supertunaman.com>
 *      
 *      An example sketch featuring Particle.h
 *      
 *      Assumes that you have adafruit's ST7565 Arduino library 
 *      installed and the ST7565 LCD attached to pins 9, 8, 7, 6, and 5,
 *      respectively.
 *      
 */

#include <ST7565.h>
#include <Particle.h>

ST7565 glcd(9, 8, 7, 6, 5);
Particles parts;
int loopcount = 0;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  glcd.st7565_init();
  glcd.st7565_command(CMD_DISPLAY_ON);
  glcd.st7565_command(CMD_SET_ALLPTS_NORMAL);
  glcd.st7565_set_brightness(0x18);
  glcd.clear();
}

void loop() {
  if(loopcount % 10 == 0) // Every 10th loop
  {
    Serial.println("BOOM");
    parts.createExplosion((rand() % SCREEN_WIDTH), (rand() % SCREEN_HEIGHT), 25);
  } else if (loopcount % 75 == 0) { //Every 75 loops
    glcd.clear();
  }
  
  parts.moveParticles();
  drawParticles(); 
  glcd.display();
  delay(100);
  loopcount++;
}


// This is a function to draw all of the particles to the screen.
// You may as well copypasta this into whatever sketch you use it on.
void drawParticles()
{
  int i;
  for (i = 0; i < parts.getActiveParticles(); i++)
  {
    int x, y, velX, velY;
    x = parts.particles[i].x;
    y = parts.particles[i].y;
    velX = parts.particles[i].velX;
    velY = parts.particles[i].velY;
    
    if (velX > 0) {
      velX++;
    } else {
      velX--;
    }
    if (velY > 0) {
      velY++;
    } else {
      velY--;
    }
    
    if ((x < 0) || (x > SCREEN_WIDTH))
      continue;
    if ((x < 0) || (x > SCREEN_WIDTH))
      continue;
    
    glcd.setpixel(x, y, BLACK);
    //glcd.setpixel(x - (velX/5), y - (velY/5), WHITE); // uncomment for trail-deleting action!
    // NOTE: this doesn't remove pixels of deleted particles
  }
}
