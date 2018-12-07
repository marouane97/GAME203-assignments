#ifndef BODY_H
#define BODY_H
#include "Vector.h"
#include "SDL.h"

class Body {

private:
	//tags = 0; null
	//tags = 1; player
	//tags = 2; ball
	//tags = 3; frame blocks (bounding border)
	//tags = 4; regular blocks
	//etc...
	int tags;//To determine how the object should behave when collided
	float mass = 1.0f;
	float radius;
	float length;
	float width;
	
	MATH::Vec3 vel;
	MATH::Vec3 accel;
	SDL_Surface *bodyImage;
	
public:
	//Variables
	MATH::Vec3 pos;//To set initial position from Scene01

	//Constructors
	Body(char* imageName_, MATH::Vec3 pos_, int tags_);//Use the image dimension to set length/width
	Body(char* imageName_, float radius_, MATH::Vec3 pos_);//Circle
	Body(char* imageName_, float length_, float width_, MATH::Vec3 pos_);//Rectangle
	Body(char* imageName_, float mass_, MATH::Vec3 pos_, MATH::Vec3 vel_, MATH::Vec3 accel_);//Object with mass
	~Body();

	//Methods
	void SetImage(const char* imageName_);
	void SetPosition(MATH::Vec3 pos_);
	void SetVelocity(MATH::Vec3 vel_);
	void ApplyForce(MATH::Vec3 force);
	void Update(const float deltaTime);
	void OnDestroy();
	
	int GetTags();

	friend class Collider;

	//Need this to drag the ball initially
	inline MATH::Vec3 GetVelocity() {
		if (vel) {
			return vel;
		}
	}

	/// Just a little helper function
	SDL_Surface* getImage();
};


#endif
