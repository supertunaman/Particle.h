/*      Particle.cpp
 *      
 *      Floppyright 2010 Tuna <tuna@supertunaman.com>
 *      
 *      A particle system for the Arduino and any given graphic LCD.
 *      
 */

#include "WProgram.h"
#include "Particle.h"

Particles::Particles(){}
Particles::~Particles(){}

// Adds a particle to particles[]
void Particles::addParticle(Particle *particle)
{
    // don't exceed the max! 
    if (activeParticles >= MAX_PARTICLES)
        return;
    
    particles[activeParticles] = *particle;
    activeParticles++;
}

// replaces particles[index] with last particle in the list
void Particles::delParticle(int index)
{
    particles[index] = particles[activeParticles - 1];
    activeParticles--;
}

// updates the posisitions of all the particles with their velocities
void Particles::moveParticles()
{
    int i;
    
    // This is what deccelerates the particles.
    for (i = 0; i < activeParticles; i++)
    {
        particles[i].x += particles[i].velX / 5;    // calculate true velocity
        particles[i].y += particles[i].velY / 5;
        if (particles[i].velX > 0) {
            particles[i].velX--;        // subtract from positive numbers
        } else {
            particles[i].velX++;        // add to negative numbers
        }
        if (particles[i].velY > 0) {
            particles[i].velY--;        // for both coordinates.
        } else {
            particles[i].velY++;
        }
        
        // and delete stopped particles from the list.
        // perhaps I should move this to up about 15 lines, so that stopped
        //  pixels can be deleted from the sketch.
        if ((particles[i].velX / 5 == 0) || (particles[i].velY / 5 == 0))
        {
            delParticle(i);
            
            // this particle is being replaced with the one at the end 
            // of the list, so we have to take a step back 
            i--; 
        }
    }
}

// creates num_parts particles at x,y with random velocities
void Particles::createExplosion(int x, int y, int num_parts)
{
    int i;
    Particle particle;
    
    for (i = 0; i < num_parts; i++)
    {
        particle.x = x;
        particle.y = y;
        particle.velX = (rand() % 50) - 25;
        particle.velY = (rand() % 50) - 25;
        
        addParticle(&particle);
    }
}

int Particles::getActiveParticles()
{
    return activeParticles;
}

