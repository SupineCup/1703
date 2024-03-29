#pragma once
#include "settings.h"

class Meteor {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;

	void spawn() {
		speedy = rand() % 6 + 2;
		speedx = rand() % 5 - 2;
		sf::FloatRect bounds = sprite.getGlobalBounds();
		float x = rand() % (int)(WINDOW_WIDTH - bounds.width);
		float y = -(rand() % (int)(WINDOW_HEIGHT - bounds.height) + bounds.height);
		sprite.setPosition(x, y);
	}

public:
	static std::string mFileNames[];
	Meteor() {
		int index = rand() % METEOR_TYPES_QTY;
		texture.loadFromFile(IMAGES_FOLDER + mFileNames[index]);
		sprite.setTexture(texture);
		spawn();
	}

	void update() {
		sprite.move(speedx, speedy);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		if (bounds.left < -bounds.width || bounds.left > WINDOW_WIDTH ||
			bounds.top > WINDOW_HEIGHT)
		{
			spawn();
		}
	}

	sf::Sprite getSprite() { return sprite; }
};

std::string Meteor::mFileNames[] = { "meteorBrown_big1.png",  "meteorBrown_big2.png",
	"meteorBrown_med1.png", "meteorBrown_med2.png", "meteorBrown_small1.png",
	"meteorBrown_small2.png", "meteorBrown_tiny1.png", "meteorBrown_tiny2.png" };