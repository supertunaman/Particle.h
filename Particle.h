/*      Particle.h
 *      
 *      Floppyright 2010 Tuna <tuna@supertunaman.com>
 *      
 *      A particle system for the Arduino and any given graphic LCD.
 *      
 */

#ifndef PARTICLE_H
#define PARTICLE_H

#include "WProgram.h"

#define MAX_PARTICLES 75 //This is 600 bytes. Think before changing this.
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

/* The Particle class has four members; x and y coordinates, and then
 * x and y velocity. The velocity is a number between -25 and 25, which is 
 * divided by 5 as an integer to come out to some number between -5 and 
 * 5. This is so that the particle will actually slow to a halt over a 
 * longer period of time as the velocity is added to or subtracted from, 
 * one moveParticles() at a time. */
class Particle {
    public:
        int x;
        int y;
        int velX;
        int velY;
};

class Particles {
    public:
        Particles();
        ~Particles();
        void moveParticles();
        void createExplosion(int x, int y, int num_parts);
        int getActiveParticles();
        Particle particles[MAX_PARTICLES];
    
    private:
        void addParticle(Particle *particle);
        void delParticle(int index);
        int activeParticles;
};

#endif

