/*
 * block.cpp
 *
 *  Created on: Jun 18, 2013
 *      Author: felipe
 */

#include "../header/block.hpp"

Block::Block(Image* i, int x_grid, int y_grid):
Entity(NULL, new Body(convertToMeters(x_grid*BLOCK_SIZE), convertToMeters(y_grid*BLOCK_SIZE), convertToMeters(BLOCK_SIZE))),
x_grid_pos(x_grid),
y_grid_pos(y_grid)
{
	animation = new AnimationSet(i);

	animation->add("full_cover", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("top_free", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("bottom_free", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("left_free", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("right_free", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("top_left_free", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("bottom_left_free", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("top_right_free", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("bottom_right_free", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("horizontal_free", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("vertical_free", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("bottom_covered", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("top_covered", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("right_covered", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("left_covered", BLOCK_SIZE, BLOCK_SIZE);
	animation->add("full_free", BLOCK_SIZE, BLOCK_SIZE);
	//nao da pra compilar no lab2 com as libs do allegro compilado no lab3

	animation->setCurrent("full_free");
}

/** Caution: the given animation should be correctly configured for blocks */
Block::Block(AnimationSet* anim, int x_grid, int y_grid):
Entity(anim, new Body(convertToMeters(x_grid*BLOCK_SIZE), convertToMeters(y_grid*BLOCK_SIZE), convertToMeters(BLOCK_SIZE))),
x_grid_pos(x_grid),
y_grid_pos(y_grid)
{}

Block::~Block() {
	// TODO Auto-generated destructor stub
}

int Block::getX() {
	return x_grid_pos;
}

int Block::getY() {
	return y_grid_pos;
}

void Block::draw(const Rect* visibleAreaPosition)
{
	if(visibleAreaPosition == NULL){
//	    animation->draw(x_grid_pos*BLOCK_SIZE, y_grid_pos*BLOCK_SIZE);
		animation->draw(convertToPixels(body->getX()), convertToPixels(body->getY()));
	}
	else
//		animation->draw(x_grid_pos*BLOCK_SIZE - visibleAreaPosition->x, y_grid_pos*BLOCK_SIZE - visibleAreaPosition->y);
		animation->draw(convertToPixels(body->getX()) - visibleAreaPosition->x, convertToPixels(body->getY()) - visibleAreaPosition->y);
}
