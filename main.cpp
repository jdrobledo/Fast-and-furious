#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
int main()
{
	// Crear una ventana SFML
	sf::RenderWindow window(sf::VideoMode(800, 600), "Fast & Furious");
	window.setFramerateLimit(60);


	// posición inicial del objeto
	sf::Vector2f position(0.0f, 0.0f);

	sf::CircleShape pelota(50.0f);
	pelota.setPosition(position);
	pelota.setFillColor(sf::Color::Blue);
	
	// Definir la velocidad constante del objeto en el eje x (movimiento rectilíneo uniforme)
	const float speedInicial = 6.0f;
	const float speedFinal = 24.0f;
	float speedActual = speedInicial;
		
	// Bucle principal del juego
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Actualización de la posición del círculo
		sf::Vector2f currentPosition = pelota.getPosition();
		float newXPosition = currentPosition.x + speedActual;
		pelota.setPosition(newXPosition, currentPosition.y);

		// Verificar si el círculo salió de la pantalla
		if (newXPosition > window.getSize().x) {
			// Volver a la posición inicial en el lado izquierdo
			pelota.setPosition(0.0f, currentPosition.y);

			// Aumentar la velocidad
			speedActual += 2.0f;

			// Reiniciar la velocidad cuando alcance la velocidad final
			if (speedActual > speedFinal) {
				speedActual = 0.0f; // aquí detengo cuando llego a la velocidad final
			}
		}

		// Limpiar la ventana
		window.clear();
		
		// Dibujar el objeto en su posición actual
		
		window.draw(pelota);

		// Mostrar todo en la ventana
		window.display();
	}
	return 0;
}