
/*
LOGIC - VERSION GRAFICA(NO TERMINADA)
Karim Herrera, Montse Sanchez, Sergio Barajas 
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
using namespace sf; 
using namespace std;


int main()
{
menu1: 
RenderWindow window(VideoMode({1920, 1080}), "---LOGIC---");

        //sprites
        Texture texture1("sprites/lapiz_sprite.png");
        Texture texture2("sprites/libro_sprite.png");
        Sprite sprite_lapiz(texture1);
        Sprite sprite_libro(texture2);



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

                   // Crear los rectángulos para los cuadros de texto
        sf::RectangleShape boxUser(sf::Vector2f(300.f, 50.f));
        sf::RectangleShape boxPass(sf::Vector2f(300.f, 50.f));
        sf::RectangleShape boxConfirmPass(sf::Vector2f(300.f, 50.f));

        RectangleShape rectanguloCentro({anchoRC, altoRC});
        RectangleShape rectanguloInicio1({anchoRI1, altoRI1});
        RectangleShape rectanguloInicio2({anchoRI2, altoRI2});
        RectangleShape rectanguloInicio3({anchoRI2, altoRI2});
        RectangleShape rectanguloTitulo2({anchoRI1+50, altoRI1+15});
     
        rectanguloCentro.setOrigin({anchoRC/2,altoRC/2});
        rectanguloCentro.setFillColor(Color(3, 173, 252));
        rectanguloCentro.setOutlineThickness(-5.f);
        rectanguloCentro.setOutlineColor(Color(61, 3, 252));
        rectanguloTitulo2.setOrigin({anchoRI1/2,altoRI1/2});
        rectanguloTitulo2.setFillColor(Color(3, 173, 252));
        rectanguloTitulo2.setOutlineThickness(-5.f);
        rectanguloTitulo2.setOutlineColor(Color(61, 3, 252));
        rectanguloInicio1.setFillColor(Color(3, 173, 252));
        rectanguloInicio2.setFillColor(Color(3, 173, 252));
        rectanguloInicio3.setFillColor(Color(3, 173, 252));
        //colorear el borde

        rectanguloInicio1.setOutlineThickness(-5.f);
        rectanguloInicio2.setOutlineThickness(-5.f);
        rectanguloInicio3.setOutlineThickness(-5.f);
        rectanguloInicio1.setSize({300.f, 150.f});
        rectanguloInicio2.setSize({300.f,150.f});
        rectanguloInicio3.setSize({300.f,150.f});
                // Posicionar cuadros y textos
        boxUser.setPosition({ventana_ancho/2 - 150.f, ventana_alto/2 - 50.f});
        boxPass.setPosition({ventana_ancho/2 - 150.f, ventana_alto/2 + 20.f});
        boxConfirmPass.setPosition({ventana_ancho/2 - 150.f, ventana_alto/2 + 90.f});
        boxUser.setFillColor(sf::Color::White);
        boxPass.setFillColor(sf::Color::White);
        boxConfirmPass.setFillColor(sf::Color::White);
        boxUser.setOutlineThickness(2.f);
        boxPass.setOutlineThickness(2.f);
        boxConfirmPass.setOutlineThickness(2.f);
    
        
                         
        rectanguloInicio1.setOutlineColor(Color(61, 3, 252));
        rectanguloInicio2.setOutlineColor(Color(61, 3, 252));
        rectanguloInicio3.setOutlineColor(Color(61, 3, 252));

        rectanguloInicio1.setPosition({(ventana_ancho/3)-200,(ventana_alto/2)});
        rectanguloInicio2.setPosition({(ventana_ancho/3)+150,(ventana_alto/2)});
        rectanguloInicio3.setPosition({(ventana_ancho/3)+500,(ventana_alto/2)});


        //sprites
        sprite_lapiz.setScale({0.3f,0.3f});
        sprite_libro.setScale({0.3f,0.3f});
        sprite_lapiz.setPosition({(ventana_ancho/2)+230,(ventana_alto/2)-150});
        sprite_libro.setPosition({(ventana_ancho/2)-475,(ventana_alto/2)-575});
        //texto
        Text texto1(fuente1, "LOGIC", 200);
        texto1.setOutlineThickness(5);
        texto1.setOutlineColor(Color::Black);
        Text texto2(fuente2, "INICIAR\nSESION", 50);
         texto2.setOutlineThickness(5);
        texto2.setOutlineColor(Color::Black);
        Text texto4(fuente2, " NUEVO\nUSUARIO", 50);
         texto4.setOutlineThickness(5);
        texto4.setOutlineColor(Color::Black);
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
            window.clear(sf::Color(13,30,173));

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
           
            
               //estado de boton
             
            bool botonPresionado = false;

            //estado del mouse
            bool mousePresionado = false;
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
                rectanguloInicio1.setFillColor(Color(61, 3, 252));
                rectanguloInicio1.setOutlineColor(Color(20, 2, 82));
                texto2.setOutlineColor(Color::White);
                texto2.setFillColor(Color::Black);
                    if (onMousePress)
                        botonPresionado = true;
                
                    if (mousePresionado and botonPresionado)
                        {
                        rectanguloInicio1.setFillColor(sf::Color::Yellow);
                        
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
                                        
                                        window2.clear(Color(13,30,173));
                                        Text titulo2(fuente1,"LOGIC",80);
                                        Text seleccion(fuente2, "Salir", 70);
                                        Text user(fuente2, "Usuario: ", 30);
                                        Text pass(fuente2, "Contrasena: ", 30);
                                        user.setFillColor(sf::Color::Black);
                                        pass.setFillColor(sf::Color::Black);
                                        
                                        RectangleShape rectangulo({anchoRC, altoRC});
                                        RectangleShape rectanguloSalir({100, 100});
                                        RectangleShape rectanguloInicio1({anchoRI1, altoRI1});
                                        RectangleShape rectanguloInicio2({anchoRI2, altoRI2});
                                                                    
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
                                        window2.setMouseCursorVisible(false);
                                        //posicion del mouse
                                        auto posicionMouse = Vector2f(sf::Mouse::getPosition(window2));
                                        //dibujar donde esta el mouse
                                        mouse.setPosition(sf::Vector2f(posicionMouse));
                                        mouse.setOrigin(mouse.getGeometricCenter());
                                    
                                        
                                        //estado de boton
                                        
                                        bool botonPresionado = false;

                                        //estado del mouse
                                        bool mousePresionado = false;
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
                                       
                             
                                        
                                        rectanguloInicio1.setOrigin({anchoRI1, altoRI1});
                                        rectanguloInicio2.setOrigin({anchoRI2, altoRI2});
                                        rectanguloSalir.setOrigin({200/2, 80/2});
                                        // darle color
                                    
                                        rectanguloInicio1.setFillColor(Color(3, 173, 252));
                                        rectanguloInicio2.setFillColor(Color(3, 173, 252));
                                        rectanguloSalir.setFillColor(Color(3, 173, 252));
                                        //colorear el borde
                                       
                                        rectanguloInicio1.setOutlineThickness(-5.f);
                                        rectanguloInicio2.setOutlineThickness(-5.f);
                                        rectanguloSalir.setOutlineThickness(-5.f);
                                        rectanguloInicio1.setSize({300.f, 150.f});
                                        rectanguloInicio2.setSize({300.f,150.f});
                                        rectanguloSalir.setSize({200.f,80.f});
                                       
                                        rectanguloInicio1.setOutlineColor(Color(61, 3, 252));
                                        rectanguloInicio2.setOutlineColor(Color(61, 3, 252));
                                        rectanguloSalir.setOutlineColor(Color(61, 3, 252));

                                        rectanguloInicio1.setPosition({(ventana_ancho/2)-350,(ventana_alto/2)+100});
                                        rectanguloInicio2.setPosition({(ventana_ancho/2)+100,(ventana_alto/2)+100});
                                        rectanguloSalir.setPosition({(ventana_ancho/2)+750,(ventana_alto/2)+200});
                                        rectanguloTitulo2.setPosition({150,120});

                                                                            //BOTON SALIR
                                            if (rectanguloSalir.getGlobalBounds().contains(posicionMouse))
                                            {
                                                rectanguloSalir.setFillColor(Color(61, 3, 252));
                                                rectanguloSalir.setOutlineColor(Color(20, 2, 82));
                                                seleccion.setOutlineColor(Color::White);
                                                seleccion.setFillColor(Color::Black);
                                                    if (onMousePress)
                                                        botonPresionado = true;
                                                
                                                    if (mousePresionado and botonPresionado)
                                                        {
                                                        rectanguloSalir.setFillColor(sf::Color::Yellow);
                                                        goto menu1;
                                                        
                                                        }
                                                    else
                                                        rectanguloSalir.setFillColor(sf::Color(61, 3, 252));
                                            }else{ 

                                                rectanguloSalir.setFillColor(Color(61, 3, 252));
                                                rectanguloSalir.setOutlineColor(Color(20, 2, 82));
                                                texto3.setFillColor(Color::White);
                                                texto3.setOutlineColor(Color::Black);
                                                rectanguloSalir.setFillColor(sf::Color(61, 3, 252));
                                        
                                            }
                                            //reiniciar el estado del boton
                                            if (not mousePresionado)
                                            botonPresionado = false;

                                                                        
                                        user.setPosition(boxUser.getPosition() + sf::Vector2f(5.f, 5.f));
                                        pass.setPosition(boxPass.getPosition() + sf::Vector2f(5.f, 5.f));
                                        seleccion.setPosition(rectanguloSalir.getPosition()-Vector2f(45.f,50.f));
                                        titulo2.setPosition({70,80});
                                        
                                        window2.draw(rectanguloTitulo2);

                                        window2.draw(boxUser);
                                        
                                       
                                        window2.draw(rectanguloSalir);
                                        window2.draw(boxPass);
                                        window2.draw(mouse);
                                        window2.draw(user);
                                        window2.draw(pass);
                                         window2.draw(seleccion);
                                         window2.draw(titulo2);
                                        window2.display();
                                        



                    
                            
                        }
                                        
                    }
                    else
                        rectanguloInicio1.setFillColor(sf::Color(61, 3, 252));
            }else{

                rectanguloInicio1.setFillColor(Color(61, 3, 252));
                rectanguloInicio1.setOutlineColor(Color(20, 2, 82));
                texto2.setFillColor(Color::White);
                texto2.setOutlineColor(Color::Black);
                rectanguloInicio1.setFillColor(sf::Color(61, 3, 252));
           
            }
            //reiniciar el estado del boton
            if (not mousePresionado)
            botonPresionado = false;



            //BOTON SALIR
            if (rectanguloInicio3.getGlobalBounds().contains(posicionMouse))
            {
                rectanguloInicio3.setFillColor(Color(61, 3, 252));
                rectanguloInicio3.setOutlineColor(Color(20, 2, 82));
                texto3.setOutlineColor(Color::White);
                texto3.setFillColor(Color::Black);
                    if (onMousePress)
                        botonPresionado = true;
                
                    if (mousePresionado and botonPresionado)
                        {
                        rectanguloInicio3.setFillColor(sf::Color::Yellow);
                        window.close();
                        }
                    else
                        rectanguloInicio3.setFillColor(sf::Color(61, 3, 252));
            }else{ 

                rectanguloInicio3.setFillColor(Color(61, 3, 252));
                rectanguloInicio3.setOutlineColor(Color(20, 2, 82));
                texto3.setFillColor(Color::White);
                texto3.setOutlineColor(Color::Black);
                rectanguloInicio3.setFillColor(sf::Color(61, 3, 252));
           
            }
            //reiniciar el estado del boton
            if (not mousePresionado)
            botonPresionado = false;

            //BOTON Nuevo usuario
            if (rectanguloInicio2.getGlobalBounds().contains(posicionMouse))
            {
                rectanguloInicio2.setFillColor(Color(61, 3, 252));
                rectanguloInicio2.setOutlineColor(Color(20, 2, 82));
                texto4.setOutlineColor(Color::White);
                texto4.setFillColor(Color::Black);
                    if (onMousePress)
                        botonPresionado = true;
                
                    if (mousePresionado and botonPresionado)
                        {
                        rectanguloInicio2.setFillColor(sf::Color::Yellow);
                                
                        
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
                                        
                                        window2.clear(Color(13,30,173));
                                        Text titulo2(fuente1,"LOGIC",80);
                                        Text seleccion(fuente2, "Salir", 70);
                                        Text user(fuente2, "Usuario: ", 30);
                                        Text pass(fuente2, "Contrasena: ", 30);
                                        Text confirmPass(fuente2,"Confirmar contrasena:",20);
                                        user.setFillColor(sf::Color::Black);
                                        pass.setFillColor(sf::Color::Black);
                                        confirmPass.setFillColor(sf::Color::Black);
                                        
                                        RectangleShape rectangulo({anchoRC, altoRC});
                                        RectangleShape rectanguloSalir({100, 100});
                                        RectangleShape rectanguloInicio1({anchoRI1, altoRI1});
                                        RectangleShape rectanguloInicio2({anchoRI2, altoRI2});
                                                                    
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
                                        window2.setMouseCursorVisible(false);
                                        //posicion del mouse
                                        auto posicionMouse = Vector2f(sf::Mouse::getPosition(window2));
                                        //dibujar donde esta el mouse
                                        mouse.setPosition(sf::Vector2f(posicionMouse));
                                        mouse.setOrigin(mouse.getGeometricCenter());
                                    
                                        
                                        //estado de boton
                                        
                                        bool botonPresionado = false;

                                        //estado del mouse
                                        bool mousePresionado = false;
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
                                       
                             
                                        
                                        rectanguloInicio1.setOrigin({anchoRI1, altoRI1});
                                        rectanguloInicio2.setOrigin({anchoRI2, altoRI2});
                                        rectanguloSalir.setOrigin({200/2, 80/2});
                                        // darle color
                                    
                                        rectanguloInicio1.setFillColor(Color(3, 173, 252));
                                        rectanguloInicio2.setFillColor(Color(3, 173, 252));
                                        rectanguloSalir.setFillColor(Color(3, 173, 252));
                                        //colorear el borde
                                       
                                        rectanguloInicio1.setOutlineThickness(-5.f);
                                        rectanguloInicio2.setOutlineThickness(-5.f);
                                        rectanguloSalir.setOutlineThickness(-5.f);
                                        rectanguloInicio1.setSize({300.f, 150.f});
                                        rectanguloInicio2.setSize({300.f,150.f});
                                        rectanguloSalir.setSize({200.f,80.f});
                                       
                                        rectanguloInicio1.setOutlineColor(Color(61, 3, 252));
                                        rectanguloInicio2.setOutlineColor(Color(61, 3, 252));
                                        rectanguloSalir.setOutlineColor(Color(61, 3, 252));

                                        rectanguloInicio1.setPosition({(ventana_ancho/2)-350,(ventana_alto/2)+100});
                                        rectanguloInicio2.setPosition({(ventana_ancho/2)+100,(ventana_alto/2)+100});
                                        rectanguloSalir.setPosition({(ventana_ancho/2)+750,(ventana_alto/2)+200});
                                        rectanguloTitulo2.setPosition({150,120});

                                                                            //BOTON SALIR
                                            if (rectanguloSalir.getGlobalBounds().contains(posicionMouse))
                                            {
                                                rectanguloSalir.setFillColor(Color(61, 3, 252));
                                                rectanguloSalir.setOutlineColor(Color(20, 2, 82));
                                                texto3.setOutlineColor(Color::White);
                                                texto3.setFillColor(Color::Black);
                                                    if (onMousePress)
                                                        botonPresionado = true;
                                                
                                                    if (mousePresionado and botonPresionado)
                                                        {
                                                        rectanguloSalir.setFillColor(sf::Color::Yellow);
                                                        goto menu1;
                                                        
                                                        }
                                                    else
                                                        rectanguloSalir.setFillColor(sf::Color(61, 3, 252));
                                            }else{ 

                                                rectanguloSalir.setFillColor(Color(61, 3, 252));
                                                rectanguloSalir.setOutlineColor(Color(20, 2, 82));
                                                texto3.setFillColor(Color::White);
                                                texto3.setOutlineColor(Color::Black);
                                                rectanguloSalir.setFillColor(sf::Color(61, 3, 252));
                                        
                                            }
                                            //reiniciar el estado del boton
                                            if (not mousePresionado)
                                            botonPresionado = false;

                                                                        
                                        user.setPosition(boxUser.getPosition() + sf::Vector2f(5.f, 5.f));
                                        pass.setPosition(boxPass.getPosition() + sf::Vector2f(5.f, 5.f));
                                        confirmPass.setPosition(boxConfirmPass.getPosition() + sf::Vector2f(5.f, 5.f));
                                        seleccion.setPosition(rectanguloSalir.getPosition()-Vector2f(45.f,50.f));
                                        titulo2.setPosition({70,80});
                                        
                                        window2.draw(rectanguloTitulo2);

                                        window2.draw(boxUser);
                                        window2.draw(boxConfirmPass);
                                       
                                        window2.draw(rectanguloSalir);
                                        window2.draw(boxPass);
                                        window2.draw(mouse);
                                        window2.draw(user);
                                        window2.draw(pass);
                                        window2.draw(confirmPass);
                                        window2.draw(seleccion);
                                        window2.draw(titulo2);
                                        window2.display();
                       }
                                        



                        //INICIO DE SESION
                        }
                    else
                        rectanguloInicio2.setFillColor(sf::Color(61, 3, 252));
            }else{ 

                rectanguloInicio2.setFillColor(Color(61, 3, 252));
                rectanguloInicio2.setOutlineColor(Color(20, 2, 82));
              texto4.setFillColor(Color::White);
                texto4.setOutlineColor(Color::Black);
                rectanguloInicio2.setFillColor(sf::Color(61, 3, 252));
           
            }
            //reiniciar el estado del boton
            if (not mousePresionado)
            botonPresionado = false;



          
           
            //que la figura se quede en su lugar
            rectanguloCentro.setPosition({ventana_ancho/2,(ventana_alto/2)-250.f});

            
            
            texto1.setPosition({(ventana_ancho/2)-270.f,(ventana_alto/2)-380.f});
            texto2.setPosition({(ventana_ancho/3)-100,(ventana_alto/2)+10});
            texto3.setPosition({(ventana_ancho/3)+600,(ventana_alto/2)+50});
            texto4.setPosition({(ventana_ancho/3)+225,(ventana_alto/2)+15});
            //dibujar las figuras
            window.draw(rectanguloCentro);
            window.draw(rectanguloInicio1);
            window.draw(rectanguloInicio2);
            window.draw(rectanguloInicio3);
            window.draw(mouse);
            window.draw(texto1);
            window.draw(texto2);
            window.draw(texto3);
            window.draw(texto4);
            window.draw(sprite_lapiz);
            window.draw(sprite_libro);

           
            //terminar de dibujar
            window.display();

        }
        

    //fin del programa
    return 0;
}
