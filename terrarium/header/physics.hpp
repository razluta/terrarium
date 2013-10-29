/*
 * physics.hpp
 *
 *  Created on: 28/10/2013
 *      Author: felipe
 */

#ifndef PHYSICS_HPP_
#define PHYSICS_HPP_

namespace Physics
{
	class World;

	struct Vector
	{
		float x, y, z;

		Vector();
		Vector(float x1=0, float y1=0, float z1=0);
		Vector(const Vector &v);

	};

	class Body
	{
		friend class World;

		private:

		struct Implementation;
		Implementation* implementation;

		public:

		Body(double x, double y, double size);
		Body(double x, double y, double width, double height);
		~Body(); //TODO

		double getX() const;
		double getY() const;
		double getWidth() const;
		double getHeight() const;
		Vector getVelocity() const;
		float getAngle() const;

		void setX(double new_x);
		void setY(double new_y);
		void setDynamic();
		void setFixedRotation(bool choice=true);

		void applyImpulse(Vector impulse, Vector point);
		void applyForceToCenter(Vector force);
	};

	class World
	{
		struct Implementation;
		Implementation* implementation;

		public:

		World(Vector gravityAcceleration);

		void addBody(Body* b);
		void destroyBody(Body* b);

		void step(float timeStep, int velocityIterations, int positionIterations);
	};

}


#endif /* PHYSICS_HPP_ */
