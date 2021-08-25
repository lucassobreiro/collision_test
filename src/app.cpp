#include "app.hpp"

Wall wall[WALL_LIMIT];
Water water[WATER_LIMIT];

Player player;
Collision collision;

void App::initApp(bool restart)
{	
	if(!restart)
	{
		srand(time(NULL));	

		view.setSize(sf::Vector2f(W_WIDTH, W_HEIGHT));

		window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), "Collision Test - by lucassobreiro", sf::Style::Close);
		window.setFramerateLimit(60);
		window.setView(view);
	}
	else
	{
		wallMovement = false;
		player.setSpeed(8);
	}
	
	player.initPlayer();

	for(int a=0; a<WALL_LIMIT; a++)
	{
		wall[a].initWall(0, 50, 0);
		while(collision.simple(player.getRec(), wall[a].getRec()))
			wall[a].initWall(0, 50, 0);
	}
		
	for(int a=0; a<WATER_LIMIT; a++)
		water[a].initWall(0, 153, 204);

	update();
}

void App::update()
{
	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
				case(sf::Event::Closed):
				{
					window.close();
					break;
				}

				case(sf::Event::KeyPressed):
				{
					switch(event.key.code)
					{
						case(sf::Keyboard::Tab):
						{
							wallMovement =! wallMovement;
							break;
						}
						
						case(sf::Keyboard::LShift):
						{
							std::cout << "PosX: " << player.getRec().getPosition().x <<
							"\tPosY: " << player.getRec().getPosition().y << "\tSpeed: " <<
							player.getSpeed() << std::endl;
							break;
						}
	
						case(sf::Keyboard::P):
						{
							player.setSpeed(player.getSpeed() + 1);
							std::cout << "Speed: " << player.getSpeed() << std::endl;
							break;
						}

						case(sf::Keyboard::O):
						{
							player.setSpeed(player.getSpeed() - 1);
							std::cout << "Speed: " << player.getSpeed() << std::endl;
							break;
						}

						case(sf::Keyboard::R):
						{
							initApp(true);
							break;
						}

						case(sf::Keyboard::Escape):
						{
							window.close();
							break;
						}

						default:
							break;
					}
					break;
				}

				default:
					break;
			}
					
		}
			
		//fps limit	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			window.setFramerateLimit(99999);
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			window.setFramerateLimit(5);
		else
			window.setFramerateLimit(60);
		
		player.movement();	

		for(int a=0; a<WALL_LIMIT; a++)
		{
			collision.teleport(player.getRecAddress(), wall[a].getRec());
			if(wallMovement)
				wall[a].movement();
		}
		
		player.setColorToBlue(false);

		for(int a=0; a<WATER_LIMIT; a++)
		{
			if(collision.simple(player.getRec(), water[a].getRec()))
				player.setColorToBlue(true);
			/*else
				player.setColorToBlue(false);*/

			if(wallMovement)
				water[a].movement();
		}	
		
		view.setCenter(sf::Vector2f(player.getRec().getPosition().x + player.getRec().getSize().x / 2,
		player.getRec().getPosition().y + player.getRec().getSize().y / 2));

		window.setView(view);
		
		//draw
		window.clear(sf::Color(0, 150, 0));
		for(int a=0; a<WATER_LIMIT; a++)
			window.draw(water[a].getRec());
		for(int a=0; a<WALL_LIMIT; a++)
			window.draw(wall[a].getRec());
		window.draw(player.getRec());
		window.display();
	}
}

