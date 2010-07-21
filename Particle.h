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

