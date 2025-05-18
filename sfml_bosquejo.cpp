#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf; 
using namespace std;


int main()
{
 
RenderWindow window(VideoMode({1920, 1080}), "---LOGIC---");


        //cargar fuente
        Font fuente1("C:/Users/Sergio/Desktop/SFML-3.0.0/Nabla.ttf");
        Font fuente2("C:/Users/Sergio/Desktop/SFML-3.0.0/Jersey.ttf");
        float ventana_alto = static_cast<float>(window.getSize().y);
        float ventana_ancho = static_cast<float>(window.getSize().x);
        //crear figuras
        float anchoRC = 600.f;
        float altoRC = 300.f;
        float anchoRI1 = 200.f;
        float altoRI1 = 100.f;
        float anchoRI2 = 200.f;
        float altoRI2 = 100.f;

        RectangleShape rectanguloCentro({anchoRC, altoRC});
        RectangleShape rectanguloInicio1({anchoRI1, altoRI1});
        RectangleShape rectanguloInicio2({anchoRI2, altoRI2});


     
        rectanguloCentro.setOrigin({anchoRC/2,altoRC/2});
        rectanguloInicio1.setOrigin({anchoRI1, altoRI1});
        rectanguloInicio2.setOrigin({anchoRI2, altoRI2});
        // darle color
        rectanguloCentro.setFillColor(Color(76,153,0));
        rectanguloInicio1.setFillColor(Color(76,153,0));
        rectanguloInicio2.setFillColor(Color(76,153,0));
        //colorear el borde
        rectanguloCentro.setOutlineThickness(-5.f);
        rectanguloInicio1.setOutlineThickness(-5.f);
        rectanguloInicio2.setOutlineThickness(-5.f);
        rectanguloCentro.setOutlineColor(Color(102,204,0));
        rectanguloInicio1.setOutlineColor(Color(102,204,0));
        rectanguloInicio2.setOutlineColor(Color(102,204,0));

        //texto
        Text texto1(fuente1, "LOGIC", 200);
        texto1.setOutlineThickness(5);
        texto1.setOutlineColor(Color::Black);
        Text texto2(fuente2, "INICIO", 50);
         texto2.setOutlineThickness(5);
        texto2.setOutlineColor(Color::Black);
        Text texto3(fuente2, "SALIR", 50);
         texto3.setOutlineThickness(5);
        texto3.setOutlineColor(Color::Black);
        
        //loop del programa
        while(window.isOpen())
        {

                while(std::optional event = window.pollEvent())
                {
                    if(event->is<sf::Event::Closed>())
                    {
                        window.close();
                    }
                    else if(event->is<sf::Event::Resized>())
                    {
                       sf::View vista(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                        window.setView(vista);
                    }

                }
            
            //llenar la ventna con un color
            window.clear(sf::Color(0,51,25));

             //dibujar mouse 
              sf::ConvexShape mouse;
            mouse.setOutlineColor(sf::Color(32,32,32));
            mouse.setOutlineThickness((2.f));
            mouse.setPointCount(4);
            mouse.setPoint(0,{-15.f/2, 0.f});
            mouse.setPoint(1, {10.f, -13.f/2});
            mouse.setPoint(2, {15.f/2, 0.f});
            mouse.setPoint(3, {10.f, 13.f/2});
            mouse.rotate(sf::degrees(45));
            
            //esconder el cursor
            window.setMouseCursorVisible(false);
            //posicion del mouse
            auto posicionMouse = Vector2f(sf::Mouse::getPosition(window));
            //dibujar donde esta el mouse
            mouse.setPosition(sf::Vector2f(posicionMouse));
            mouse.setOrigin(mouse.getGeometricCenter());
           
            
               // state of button
             
            bool botonPresionado = false;

             // state of mouse
            bool mousePresionado = false;
              // state of mouse
            bool onMousePress   = false;
            bool onMouseRelease = false;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            if (not mousePresionado)
                onMousePress = true;
            mousePresionado = true;
        }
        else
        {
            if (mousePresionado)
                onMouseRelease = true;
            mousePresionado = false;
        }


            // interaccion del mouse con los botones
            // BOTON INICIO
            if (rectanguloInicio1.getGlobalBounds().contains(posicionMouse))
            {
                rectanguloInicio1.setFillColor(Color(102,204,0));
                rectanguloInicio1.setOutlineColor(Color(76,153,0));
                texto2.setOutlineColor(Color::White);
                texto2.setFillColor(Color::Black);
                    if (onMousePress)
                        botonPresionado = true;
                
                    if (mousePresionado and botonPresionado)
                        {
                        rectanguloInicio1.setFillColor(sf::Color::Yellow);
                        window.clear(sf::Color(0,51,25));
                        window.display();
                        //aqui cambiar de pantalla
                       window.close();

                        RenderWindow window2(VideoMode({1980,1060}), "---LOGIC---");
                        while(window2.isOpen())
                       {

                                    while(std::optional event = window2.pollEvent())
                                    {
                                        if(event->is<sf::Event::Closed>())
                                        {
                                            window2.close();
                                        }
                                        else if(event->is<sf::Event::Resized>())
                                        {
                                        sf::View vista(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                                            window2.setView(vista);
                                        }

                                    }
                                        window2.clear(Color(0,51,25));
                                        
                                        Text seleccion(fuente2, "Seleccione una opcion: ", 70);
                                        RectangleShape rectangulo({anchoRC, altoRC});
                                        RectangleShape rectanguloInicio1({anchoRI1, altoRI1});
                                        RectangleShape rectanguloInicio2({anchoRI2, altoRI2});

                                        seleccion.setPosition({ventana_ancho/3, ventana_alto/8});
                                        window2.draw(seleccion);
                                        window2.display();




                    
                            
                        }
                                        
                    }
                    else
                        rectanguloInicio1.setFillColor(sf::Color(102, 204, 0));
            }else{

                rectanguloInicio1.setFillColor(Color(76,153,0));
                rectanguloInicio1.setOutlineColor(Color(102,204,0));
                texto2.setFillColor(Color::White);
                texto2.setOutlineColor(Color::Black);
                rectanguloInicio1.setFillColor(sf::Color(102,204,0));
           
            }
            if (not mousePresionado)
            botonPresionado = false;



            //BOTON SALIR
            if (rectanguloInicio2.getGlobalBounds().contains(posicionMouse))
            {
                rectanguloInicio2.setFillColor(Color(102,204,0));
                rectanguloInicio2.setOutlineColor(Color(76,153,0));
                texto3.setOutlineColor(Color::White);
                texto3.setFillColor(Color::Black);
                    if (onMousePress)
                        botonPresionado = true;
                
                    if (mousePresionado and botonPresionado)
                        {
                        rectanguloInicio2.setFillColor(sf::Color::Yellow);
                        window.close();
                        }
                    else
                        rectanguloInicio2.setFillColor(sf::Color(102, 204, 0));
            }else{

                rectanguloInicio2.setFillColor(Color(76,153,0));
                rectanguloInicio2.setOutlineColor(Color(102,204,0));
                texto3.setFillColor(Color::White);
                texto3.setOutlineColor(Color::Black);
                rectanguloInicio2.setFillColor(sf::Color(102,204,0));
           
            }
            if (not mousePresionado)
            botonPresionado = false;



          
            //centrar textos
            auto centroRect1x = (rectanguloInicio1.getPosition().x)-(rectanguloInicio1.getSize().x) + 50;
            auto centroRect1y = (rectanguloInicio1.getPosition().y)-(rectanguloInicio1.getSize().y);
            auto centroRect2x = (rectanguloInicio2.getPosition().x)-(rectanguloInicio2.getSize().x) + 50;
            auto centroRect2y = (rectanguloInicio2.getPosition().y)-(rectanguloInicio2.getSize().y);

            //que la figura se quede en su lugar
            rectanguloCentro.setPosition({ventana_ancho/2,(ventana_alto/2)-250.f});
            rectanguloInicio1.setPosition({(ventana_ancho/2)-100,(ventana_alto/2)+100});
            rectanguloInicio2.setPosition({(ventana_ancho/2)+300,(ventana_alto/2)+100});
            texto1.setPosition({(ventana_ancho/2)-270.f,(ventana_alto/2)-380.f});
            texto2.setPosition({centroRect1x, centroRect1y});
            texto3.setPosition({centroRect2x, centroRect2y});
            //dibujar las figuras
            window.draw(rectanguloCentro);
            window.draw(rectanguloInicio1);
            window.draw(rectanguloInicio2);
            window.draw(mouse);
            window.draw(texto1);
            window.draw(texto2);
            window.draw(texto3);

           
            //terminar de dibujar
            window.display();

        }
        

    //fin del programa
    return 0;
}
